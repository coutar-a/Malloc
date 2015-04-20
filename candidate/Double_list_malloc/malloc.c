/*
** malloc.c for malloc in /home/durand_u/Dropbox/PSU_2014_malloc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Tue Jan 27 14:38:55 2015 Rémi DURAND
** Last update Sat Jan 31 09:42:44 2015 Rémi DURAND
*/

#include "malloc.h"

t_mdata		g_beg = NULL;

char		closest_value(size_t val1, size_t val2, size_t wanted_size)
{
  char		ret;

  ret = val1 < val2 && val1 >= wanted_size ? 1 : 0;
  return (ret);
}

t_mdata		find_space(t_mdata *lastnode, size_t size)
{
  t_mdata	tempNode;
  t_mdata	fart;

  tempNode = g_beg;
  fart = tempNode;
  while (tempNode)
    {
      if (closest_value(fart->size, tempNode->size, size))
	fart = tempNode;
      *lastnode = tempNode;
      tempNode = tempNode->next;
    }
  return (!fart ? fart : tempNode);
}
/*
t_mdata		find_space(t_mdata *lastnode, size_t size)
{
  t_mdata	tempNode;

  tempNode = g_beg;
  while (tempNode != NULL && !(tempNode->f_flag && tempNode->size >= size))
    {
      *lastnode = tempNode;
      tempNode = tempNode->next;
    }
  return tempNode;
}
*/
t_mdata		get_more_heap(t_mdata lastnode, size_t size)
{
  t_mdata	newNode;

  newNode = sbrk(0);
  if ((void *)-1 == sbrk(size + MDATA_SIZE))
    return NULL;
  newNode->size = size;
  newNode->next = NULL;
  newNode->prev = NULL;
  newNode->comp = newNode->d_beg;
  if (lastnode != NULL)
    {
      lastnode->next = newNode;
      newNode->prev = lastnode;
    }
  newNode->f_flag = 0;
  return newNode;
}

void		node_alloc(t_mdata node, size_t size)
{
  t_mdata	newNode;

  newNode = (t_mdata)(node->d_beg + size);
  newNode->size = node->size - size - MDATA_SIZE;
  newNode->next = node->next;
  newNode->prev = node;
  newNode->f_flag = 1;
  newNode->comp = newNode->d_beg;
  node->size = size;
  node->next = newNode;
}

void		node_resizing(t_mdata mem_node, size_t size)
{
  if ((mem_node->size - size) >= (MDATA_SIZE + 4))
    node_alloc(mem_node, size);
  mem_node->f_flag = 0;
}

void		*malloc(size_t size)
{
  t_mdata	last;
  t_mdata	mem_node;
  size_t	aligned_size;

  last = NULL;
  aligned_size = ROUND4(size);
  if (!g_beg)
    {
      if(!(mem_node = get_more_heap(NULL, aligned_size)))
	return NULL;
      g_beg = mem_node;
    }
  else
    {
      last = g_beg;
      if(!(mem_node = find_space(&last, aligned_size)))
	{
	  if(!(mem_node = get_more_heap(last, aligned_size)))
	    return NULL;
	}
      else
	node_resizing(mem_node, aligned_size);
    }
  return (size <= 0 ? NULL : mem_node->d_beg);
}
