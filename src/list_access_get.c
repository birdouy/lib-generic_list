/*
** list_access_get.c for generic_list in /home/caudou_j/Documents/projets/arduino/generic_list/src
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Wed May 14 16:52:25 2014 caudou_j
** Last update Sun May 18 23:16:18 2014 caudou_j
*/

#include	<stdlib.h>
#include	"generic_list.h"

void		*list_get_elem_at_front(t_list list)
{
  if (list == NULL)
    return (NULL);
  return (list->value);
}

void		*list_get_elem_at_back(t_list list)
{
  t_list	head;

  if (list == NULL)
    return (NULL);
  head = list;
  while (list->next != NULL)
    {
      list = list->next;
      if (list == head)
	return (NULL);
      if (list == head)
	return (NULL);
    }
  return (list->value);
}

void		*list_get_elem_like(t_list list,
				    t_bool (*func_cmp)(void *value,
						       void *param),
				    void *param)
{
  t_list	head;

  if (list == NULL)
    return (NULL);
  head = list;
  while (list != NULL)
    {
      if (func_cmp(list->value, param) == MY_TRUE)
	return (list->value);
      list = list->next;
      if (list == head)
	return (NULL);
    }
  return (NULL);
}

void		*list_get_elem_like_ptr(t_list list, void *cmp)
{
  t_list	head;

  if (list == NULL)
    return (NULL);
  head = list;
  while (list != NULL)
    {
      if (list->value == cmp)
	return (list->value);
      list = list->next;
      if (list == head)
	return (NULL);
    }
  return (NULL);
}

void		*list_get_elem_at_position(t_list list,
					   unsigned int position)
{
  t_list	head;
  unsigned int	cursor;

  if (list == NULL)
    return (0);
  head = list;
  cursor = 0;
  while (list != NULL)
    {
      if (cursor == position)
	return (list->value);
      cursor++;
      list = list->next;
      if (list == head)
	return (NULL);
    }
  return (NULL);
}
