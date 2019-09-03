SRCS = $(shell find -name '*.c')
OBJS = $(SRCS:.c=.o)
EXEC = prg
CFLAGS = -Wall
LFLAGS = -lm
CC = gcc
$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

$(OBJS): $(SRCS)
	$(CC) -c $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJS) $(EXEC)



