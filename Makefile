##
## Makefile for makefile in /home/durand_u/Dropbox/PSU_2014_malloc
## 
## Made by Rémi DURAND
## Login   <durand_u@epitech.net>
## 
## Started on  Wed Jan 28 12:48:40 2015 Rémi DURAND
## Last update Sat Jan 31 14:41:11 2015 Rémi DURAND
##

SRC	=	malloc.c		\
		free.c			\
		calloc.c		\
		show_alloc_mem.c	\
		realloc.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

NAME	=	libmy_malloc_$(HOSTTYPE).so

LINK	=	libmy_malloc.so

CFLAGS	+=	-W -Wall -Wextra -Werror -fPIC

all: $(NAME)

symblink:
	ln -s $(NAME) $(LINK)

$(NAME): $(OBJ) symblink
	$(CC) -shared -o $(NAME) $(OBJ) $(CFLAGS)

clean:	
	rm $(OBJ)

fclean:	clean
	rm $(NAME) $(LINK)

re: fclean all
