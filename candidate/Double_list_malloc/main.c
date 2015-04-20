/*
** main.c for  in /home/coutar_a/Dropbox/PSU_2014_malloc
** 
** Made by Ambroise Coutarel
** Login   <coutar_a@epitech.net>
** 
** Started on  Wed Jan 28 14:16:01 2015 Ambroise Coutarel
** Last update Sat Jan 31 09:19:20 2015 Rémi DURAND
*/

#include <string.h>
#include <stdio.h>
#include "malloc.h"

int	main(void)
{
  char	*ptr;

  ptr = calloc(9, 4);
  printf("%s\n", ptr);
  ptr = strcpy(ptr, "koujouko\n");
  printf("%s\n", ptr);
  show_alloc_mem();
  return 0;
}
