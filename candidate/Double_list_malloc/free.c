/*
** free.c for free in /home/durand_u/Dropbox/PSU_2014_malloc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Tue Jan 27 14:39:09 2015 Rémi DURAND
** Last update Sat Jan 31 11:27:33 2015 Rémi DURAND
*/

#include "malloc.h"

t_mdata		get_mdata(void *ptr)
{
  return ((t_mdata)(ptr - MDATA_SIZE));
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
      if (mdata->next != NULL)
	mdata->next->prev = mdata;
    }
  return (mdata);
}

void		free(void *ptr)
{
  t_mdata	mdata_tmp;

  if (is_valid(ptr))
    {
      mdata_tmp = get_mdata(ptr);
      mdata_tmp->f_flag = 1;
      if (mdata_tmp->prev && mdata_tmp->prev->f_flag)
	mdata_tmp = gathering(mdata_tmp->prev);
      if (mdata_tmp->next)
        gathering(mdata_tmp);
      else
	{
	  if (g_beg->f_flag && !g_beg->next)
	    g_beg = NULL;
	  else
	    mdata_tmp->prev->next = NULL;
	  brk(mdata_tmp);
	}
    }
}
