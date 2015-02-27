/*
** list_create_nodes.c for generic_list in /home/caudou_j/Documents/projets/arduino
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Sun May 18 22:37:42 2014 caudou_j
** Last update Mon May 19 02:00:36 2014 caudou_j
*/

#include	<stdlib.h>
#include	"generic_list.h"

t_bool		list_create_nodes_at_front(t_list *front_ptr, size_t list_size, void *param,
					   t_value_constructor __constructor)
{
  size_t	size;
  void		*value;

  size = 0;
  while (size < list_size)
    {
      if (__constructor != NULL)
	value = __constructor(param);
      else
	value = NULL;
      list_add_elem_at_back(front_ptr, value);
      ++size;
    }
  return (MY_TRUE);
}
