
CC = gcc
CFLAGS=-Wall -pedantic -ansi

NAME = gdg

HDRS = obj.h ent.h log.h gdg.h
SRCS = main01.c ent.c log.c gdg.c
OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
		$(CC) -o $@ $^

main00.o: main00.c ent.h
main01.o: main01.c ent.h gdg.h

ent.o: ent.c obj.h ent.h log.h

gdg.o: gdg.c ent.h log.h

clean:
		rm -f *~ $(OBJS) $(NAME)

