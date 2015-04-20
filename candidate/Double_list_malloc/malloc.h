/*
** main.c for malloc.h in /home/durand_u/Dropbox/PSU_2014_malloc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Tue Jan 27 14:24:37 2015 Rémi DURAND
** Last update Sat Jan 31 11:55:54 2015 Rémi DURAND
*/

#ifndef _MAL_H_
# define _MAL_H_

#include <unistd.h>
#include <stdlib.h>

#define			MDATA_SIZE 40
#define			ROUND4(size) (((((size) - 1) / 4) * 4) + 4)

typedef struct		s_mdata
{
  size_t		size;
  struct s_mdata	*next;
  struct s_mdata	*prev;
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
void			cp_data(t_mdata mdata_src, t_mdata mdata_dest);
void			*bigger_alloc(void *ptr, t_mdata mdata_tmp, size_t aligned_size);
t_mdata			find_space(t_mdata *lastnode, size_t size);
t_mdata			get_more_heap(t_mdata lastnode, size_t size);
void			node_alloc(t_mdata node, size_t size);
void			node_resizing(t_mdata mem_node, size_t size);
t_mdata			get_mdata(void *ptr);
int			is_valid(void *ptr);
t_mdata			gathering(t_mdata mdata);

#endif /* !_MAL_H_ */
