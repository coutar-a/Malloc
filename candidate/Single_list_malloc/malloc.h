/*
** main.c for malloc.h in /home/durand_u/Dropbox/PSU_2014_malloc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Tue Jan 27 14:24:37 2015 Rémi DURAND
** Last update Thu Jan 29 13:25:44 2015 Rémi DURAND
*/

#ifndef _MAL_H_
# define _MAL_H_

#include <unistd.h>
#include <stdlib.h>

#define			MDATA_SIZE 32
#define		        ROUND4(size) (((((size) - 1) / 4) * 4) + 4)

typedef struct		s_mdata
{
  size_t		size;
  struct s_mdata	*next;
  int			f_flag;
  void			*comp;
  char			d_beg[1];
}			*t_mdata;

extern t_mdata		g_beg;

void			*malloc(size_t size);
void			free(void *ptr);
void			*calloc(size_t mb, size_t size);
void			*realloc(void *ptr, size_t size);
void			show_alloc_mem();
t_mdata			gathering(t_mdata mdata);
t_mdata			get_mdata(void *ptr);
void			node_alloc(t_mdata node, size_t size);
int			is_valid(void *ptr);

#endif /* !_MAL_H_ */
