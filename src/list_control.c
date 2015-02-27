/*
** list_control.c for generic_list in /home/caudou_j/Documents/projets/arduino/generic_list/src
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Wed May 14 16:52:08 2014 caudou_j
** Last update Sun May 18 23:24:49 2014 caudou_j
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"generic_list.h"

t_return	list_control_all(t_list front_ptr,
				 t_return (*func)(void *value, void *param),
				 void *param)
{
  t_list	tmp_next;
  t_return	ret;
  t_list	head;

  if (front_ptr == NULL)
    return (SUCCESS);
  head = front_ptr;
  while (front_ptr != NULL)
    {
      tmp_next = front_ptr->next;
      if ((ret = func(front_ptr->value, param)) == ERROR
	  || ret == FOUND)
	return (ret);
      front_ptr = tmp_next;
      if (front_ptr == head)
	return (ret);
    }
  return (ret);
}
