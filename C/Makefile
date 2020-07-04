CC ?= gcc
AR  ?= ar
MAKE ?= make

LIBS := -pthread

CFLAGS := -I./ \
         -I./*

ALLFILES := $(shell find . -name '*.c')


all: $(ALLFILES)
	$(eval FOLDERNAME := $(shell dirname $?))
	$(CC) $(CFLAGS) $(LIBS) $? -o $(FOLDERNAME)/a.out

clean:
	rm -f *.o
	rm -f */*.out
