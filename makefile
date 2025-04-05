CC=gcc
CFLAGS=-Wall
LDFLAGS=-lm

.PHONY: all
all: speaknum

.PHONY: clean
clean:
	$(RM) *~ *.o speaknum

OBJECTS=speaknum.o
speaknum: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o speaknum
