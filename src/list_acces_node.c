/*
** list_acces_node.c for generic_list in /home/caudou_j/Documents/projets/arduino/generic_list/src
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Wed May 14 16:52:16 2014 caudou_j
** Last update Sun May 18 22:56:46 2014 caudou_j
*/

#include	<stdlib.h>
#include	"generic_list.h"

t_node  *list_get_first_node_with_value(t_list list, void *value,
					t_value_comparator val_comp)
{
  if (list == NULL)
    return (NULL);
  while (list != NULL)
    {
      if (val_comp(value, list->value) == 0)
	return (list);
      list = list->next;
    }
  return (0);
}

t_node		*list_next(t_list list)
{
  if (list == NULL)
    return ( NULL);
  return (list->next);
}
