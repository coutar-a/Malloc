/*
** free.c for free in /home/durand_u/Dropbox/PSU_2014_malloc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Tue Jan 27 14:39:09 2015 Rémi DURAND
** Last update Thu Jan 29 16:32:59 2015 Rémi DURAND
*/

#include "malloc.h"

t_mdata		get_mdata(void *ptr)
{
  char		*mdata_tmp;

  mdata_tmp = ptr;
  return (ptr = mdata_tmp -= MDATA_SIZE);
}

int		is_valid(void *ptr)
{
  if (g_beg != NULL && (g_beg < (t_mdata)ptr && ptr < sbrk(0)))
    return (ptr == (get_mdata(ptr))->comp);
  return (0);
}

t_mdata		gathering(t_mdata mdata)
{
  if (mdata->next && mdata->next->f_flag)
    {
      mdata->size += MDATA_SIZE + mdata->next->size;
      mdata->next = mdata->next->next;
    }
  return (mdata);
}

t_mdata		get_prev_node(t_mdata mdata)
{
  t_mdata	ret;

  if (mdata == g_beg)
    return (NULL);
  ret = g_beg;
  while (ret->next != mdata)
    ret = ret->next;
  return (ret);
}

void		free(void *ptr)
{
  t_mdata	mdata_tmp;
  t_mdata	mdata_prev;

  if (is_valid(ptr))
    {
      mdata_tmp = get_mdata(ptr);
      mdata_tmp->f_flag = 1;
      mdata_prev = get_prev_node(mdata_tmp);
      if (mdata_prev && mdata_prev->f_flag)
	mdata_tmp = gathering(mdata_prev);
      if (mdata_tmp->next)
        gathering(mdata_tmp);
      else
	{
	  if (g_beg->f_flag && !g_beg->next)
	    g_beg = NULL;
	  else
	    mdata_prev->next = NULL;
	  brk(mdata_tmp);
	}
    }
}
