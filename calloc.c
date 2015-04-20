/*
** calloc.c for malloc in /home/coutar_a/Dropbox/PSU_2014_malloc
** 
** Made by Ambroise Coutarel
** Login   <coutar_a@epitech.net>
** 
** Started on  Wed Jan 28 13:44:45 2015 Ambroise Coutarel
** Last update Sat Jan 31 09:56:54 2015 Rémi DURAND
*/

#include "malloc.h"

void		*calloc(size_t mb, size_t size)
{
  size_t	ctr;
  int		*ret;
  size_t	limit;

  ctr = 0;
  ret = malloc(mb * size);
  limit = (get_mdata(ret))->size;
  while (ret != NULL && (ctr * 4) < limit)
    {
      ret[ctr] = 0;
      ++ctr;
    }
  return (ret);
}
