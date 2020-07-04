#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

void* sum_runner(void* arg){
	long long sum = 0;
	long long limit= *(long long *)arg;

	for(long long i=0 ; i<=limit ; i++){
		sum += i;
	}
	long long * ret;
	ret = malloc(sizeof(*ret));

	*ret = sum;

	pthread_exit(ret);
}

int main(int argc,char** argv){

	if (argc < 2){
		printf("Usage: %s <num 1> <num 2> ><num 3> ...\n",argv[0]);
		exit(-1);
	}
	int num_args = argc -1 ;
	long long args[num_args];

	pthread_t tids[num_args];

	for(int i=0;i<num_args;i++) {
		args[i] = atoll(argv[i+1]);

		pthread_attr_t attr;
		pthread_attr_init(&attr);
		
		pthread_create(&tids[i],&attr,sum_runner,&args[i]);
	}

	long long sum = 0;
	long long * sum_part_ptr = 0;

	for(int i=0;i<num_args;i++) {
		pthread_join(tids[i],(void **)&sum_part_ptr);
		sum += *sum_part_ptr;
		printf("TID:%d:Sum each: %lld\n",i,*sum_part_ptr);
		free(sum_part_ptr);
	}

	printf("Sum: %lld\n",sum);

	return 0;
}