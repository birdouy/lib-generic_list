/*
** list_infos.c for generic_list in /home/caudou_j/Documents/projets/arduino/generic_list/src
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Wed May 14 16:51:49 2014 caudou_j
** Last update Mon May 19 01:03:38 2014 caudou_j
*/

#include	<stdlib.h>
#include	"generic_list.h"

unsigned int	list_get_size(t_list list)
{
  unsigned int	cursor;
  t_list	head;

  if (list == NULL)
    return (0);
  head = list;
  cursor = 0;
  while (list != NULL)
    {
      cursor++;
      list = list->next;
      if (list == head)
	return (cursor);
    }
  return (cursor);
}

t_bool	list_is_empty(t_list list)
{
  if (list == NULL)
    return (MY_TRUE);
  return (MY_FALSE);
}

void            list_dump(t_list list, t_value_displayer val_disp)
{
  if (list == NULL)
    return ;
  while (list != NULL)
    {
      val_disp(list->value);
      list = list->next;
    }
}
