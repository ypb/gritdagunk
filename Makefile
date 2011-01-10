
CC = gcc
CFLAGS=-Wall -pedantic -ansi

NAME = gdg

HDRS = obj.h ent.h log.h
SRCS = main00.c ent.c log.c
OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
		$(CC) -o $@ $^

main00.o: main00.c ent.h

ent.o: ent.c obj.h ent.h log.h

clean:
		rm -f *~ $(OBJS) $(NAME)

