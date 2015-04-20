##
## Makefile for makefile in /home/durand_u/Dropbox/PSU_2014_malloc
## 
## Made by Rémi DURAND
## Login   <durand_u@epitech.net>
## 
## Started on  Wed Jan 28 12:48:40 2015 Rémi DURAND
## Last update Thu Jan 29 16:39:06 2015 Rémi DURAND
##

SRC	=	malloc.c		\
		free.c			\
		show_alloc_mem.c	\
		realloc.c		\
		calloc.c

CC	=	gcc

NAME	=	libmy_malloc_$(shell echo $(HOSTTYPE)).so

CFLAGS	+=	-W -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME):
	$(CC) -shared -o $(NAME) -fPIC $(SRC) $(CFLAGS)

clean:	
	rm $(NAME)

re: clean all

main:
	gcc -o test main.c -L./ -lmy_malloc_x86_64
