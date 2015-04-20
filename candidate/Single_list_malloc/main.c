#include <stdio.h>
#include "malloc.h"

int	main()
{
  char	*ptr;

  ptr = calloc(100, 4);
  show_alloc_mem();
  ptr = realloc(ptr, 390);
  free(ptr);
  ptr = malloc(8);
  main();
}
