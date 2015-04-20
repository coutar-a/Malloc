/*
** realloc.c for realloc in /home/durand_u/Dropbox/PSU_2014_malloc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Thu Jan 29 10:21:47 2015 Rémi DURAND
** Last update Thu Jan 29 16:42:21 2015 Rémi DURAND
*/

#include "malloc.h"

void		cp_data(t_mdata mdata_src, t_mdata mdata_dest)
{
  int		*src_tab;
  int		*dest_tab;
  size_t	v;

  src_tab = mdata_src->comp;
  dest_tab = mdata_dest->comp;
  v = 0;
  while (((v * 4) < mdata_src->size) && ((v * 4) < mdata_dest->size))
    {
      dest_tab[v] = src_tab[v];
      ++v;
    }
}

void		*bigger_alloc(void *ptr, t_mdata mdata_tmp, size_t aligned_size)
{
  void		*new_ptr;
  t_mdata	new_tmp;

  if (mdata_tmp->next != NULL &&
      mdata_tmp->next->f_flag &&
      (mdata_tmp->size + MDATA_SIZE + mdata_tmp->next->size) >= aligned_size)
    {
      gathering(mdata_tmp);
      if ((mdata_tmp->size - aligned_size) >= (MDATA_SIZE + 4))
        node_alloc(mdata_tmp, aligned_size);
    }
  else
    {
      new_ptr = malloc(aligned_size);
      if (new_ptr == NULL)
	return (NULL);
      new_tmp = get_mdata(new_ptr);
      cp_data(mdata_tmp, new_tmp);
      free(ptr);
      return (new_ptr);
    }
  return (ptr);
}

void		*realloc(void *ptr, size_t size)
{
  size_t	aligned_size;
  t_mdata	mdata_tmp;

  if (ptr == NULL)
    return (malloc(size));
  else if (is_valid(ptr))
    {
      aligned_size = ROUND4(size);
      mdata_tmp = get_mdata(ptr);
      if (aligned_size > mdata_tmp->size)
	return (bigger_alloc(ptr, mdata_tmp, aligned_size));
      else if ((mdata_tmp->size - aligned_size) >= (MDATA_SIZE + 4))
        node_alloc(mdata_tmp, aligned_size);
      return (ptr);
    }
  return (NULL);
}
