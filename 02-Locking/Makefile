CC ?= gcc
AR  ?= ar
MAKE ?= make

LIBS := -pthread

CFLAGS := -I./ \
		  -I./*

TARGETS := $(shell ls -l | grep ^d | awk '{print $$NF}')
$(info All Targets are $(TARGETS))

.PHONY: all clean $(TARGETS)

all : clean $(TARGETS)

$(TARGETS):
	$(info Making $@)
	$(CC) $(CFLAGS) $(LIBS) $@/main.c -o $@/a.out

clean:
	rm -f *.o
	rm -f */*.out
