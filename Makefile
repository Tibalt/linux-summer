
CC = gcc # C compiler

CFLAGS = -fPIC -Wall -Wextra -O2 -g -c -std=gnu99 # C flags
LDFLAGS = #-shared  # linking flags

RM = rm -f  # rm command
TARGET =  a.out# target lib

SRCS = main.c car.c

OBJS = $(SRCS:.c=.o)

.PHONY: all
all: ${TARGET}

$(TARGET): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(SRCS:.c=.o):%.o:%.c
	$(CC) $(INCPATH) $(CFLAGS) -o $@ $^

#include $(SRCS:.c=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d)


