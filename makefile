CC=gcc
CFLAGS=-I. -Wall
LDFLAGS=-lm
DEPS = speaknum.h
OBJ = speaknum.o test_speaknum.o

.PHONY: all
all: test_speaknum

.PHONY: clean
clean:
	$(RM) *~ *.o test_speaknum

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_speaknum: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
