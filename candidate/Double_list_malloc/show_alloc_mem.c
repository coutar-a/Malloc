/*
** show_alloc_mem.c for  in /home/coutar_a/Dropbox/PSU_2014_malloc
** 
** Made by Ambroise Coutarel
** Login   <coutar_a@epitech.net>
** 
** Started on  Wed Jan 28 14:11:02 2015 Ambroise Coutarel
** Last update Wed Jan 28 16:31:14 2015 Ambroise Coutarel
*/

#include <stdio.h>
#include "malloc.h"

void		show_alloc_mem()
{
  t_mdata	tempNode;

  tempNode = g_beg;
  printf("break : %p\n", sbrk(0));
  while (tempNode != NULL && tempNode != sbrk(0))
    {
      if (tempNode->f_flag == 0)
	printf("%p - %p : %lu octets\n", 
	       (tempNode->d_beg), 
	       (tempNode->d_beg + tempNode->size),
	       tempNode->size); 
      tempNode = tempNode->next;
    }
}
