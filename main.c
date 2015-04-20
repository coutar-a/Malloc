/*
** main.c for  in /home/coutar_a/Dropbox/PSU_2014_malloc
** 
** Made by Ambroise Coutarel
** Login   <coutar_a@epitech.net>
** 
** Started on  Wed Jan 28 14:16:01 2015 Ambroise Coutarel
** Last update Sat Jan 31 13:05:27 2015 Rémi DURAND
*/

#include <string.h>
#include <stdio.h>
#include "malloc.h"

int	main(void)
{
  char	*ptr;

  ptr = malloc(10000000000000);
  if (ptr)
    show_alloc_mem();
  return 0;
}
