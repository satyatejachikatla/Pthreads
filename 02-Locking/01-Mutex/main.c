#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#define NUM_LOOPS 200000000

long long sum = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* counting_function(void *arg){
	int offset = *(int *)arg;

	for(long long i=0;i<NUM_LOOPS;i++){
		pthread_mutex_lock(&mutex);
		sum += offset;
		pthread_mutex_unlock(&mutex);
	}

	pthread_exit(NULL);
}

int main(){
	pthread_t tids[2];

	int args[2] = { 1, -1};

	pthread_create(&tids[0],NULL,counting_function,&args[0]);
	pthread_create(&tids[1],NULL,counting_function,&args[1]);

	pthread_join(tids[0],NULL);
	pthread_join(tids[1],NULL);

	printf("Sum: %lld\n",sum);

	return 0;
}