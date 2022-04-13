CC := gcc
CFLAGS := -Wall -g
BINS := $(patsubst %.c,%,$(wildcard *.c))

trash := $(BINS) *.o

clean:
	$(RM) $(trash)

.PHONY: clean
