##
## Makefile for makefile in /home/durand_u/Dropbox/PSU_2014_malloc
## 
## Made by Rémi DURAND
## Login   <durand_u@epitech.net>
## 
## Started on  Wed Jan 28 12:48:40 2015 Rémi DURAND
## Last update Fri Jan 30 12:06:39 2015 Rémi DURAND
##

SRC	=	malloc.c		\
		free.c			\
		calloc.c		\
		show_alloc_mem.c	\
		realloc.c

CC	=	gcc

NAME	=	libmy_malloc_$(shell echo $(HOSTTYPE)).so

HOST	= $(shell echo $(HOSTTYPE))

ambroise =	libmy_malloc_x86_64.so

CFLAGS	+=	-W -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME):
	$(CC) -shared -o $(NAME) -fPIC $(SRC) $(CFLAGS)

pokut:
	$(CC) -shared -o $(ambroise) -fPIC $(SRC) $(CFLAGS)

clean:	
	rm $(NAME)

fart:
	rm $(ambroise)

prout: fart pokut

re: clean all

main:
	gcc -o test main.c -L./ -lmy_malloc_x86_64
