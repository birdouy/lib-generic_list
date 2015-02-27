/*
** list_modif_add.c for generic_list in /home/caudou_j/Documents/projets/arduino/generic_list/src
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Wed May 14 16:52:02 2014 caudou_j
** Last update Mon May 19 02:07:12 2014 caudou_j
*/

#include	<stdlib.h>
#include	"generic_list.h"

t_bool		list_add_elem_at_front(t_list *front_ptr, void *elem)
{
  t_list	new;

  if ((new = malloc(sizeof(t_node))) == NULL)
    return (MY_FALSE);
  new->value = elem;
  new->next = *front_ptr;
  *front_ptr = new;
  return (MY_TRUE);
}

t_bool		list_add_elem_after_elem(t_list front_ptr, void *elem)
{
  t_list	new;

  if ((new = malloc(sizeof(t_node))) == NULL)
    return (MY_FALSE);
  new->value = elem;
  if (front_ptr == NULL)
    new->next = NULL;
  else
    new->next = front_ptr->next;
  front_ptr->next = new;
  return (MY_TRUE);
}

t_bool		list_add_elem_at_back(t_list *front_ptr, void *elem)
{
  t_list	new_back;
  t_list	tmp;

  if ((new_back = malloc(sizeof(t_node))) == NULL)
    return (MY_FALSE);
  new_back->value = elem;
  new_back->next = NULL;
  if (*front_ptr == NULL)
    {
      *front_ptr = new_back;
      return (MY_TRUE);
    }
  tmp = *front_ptr;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_back;
  return (MY_TRUE);
}

static t_bool	list_at_position_prepare(unsigned int *cursor,
					 t_list *last,
					 t_list *new,
					 t_list *front_ptr)
{
  *cursor = 1;
  *last = *front_ptr;
  if ((*new = malloc(sizeof(t_node))) == NULL)
    return (MY_FALSE);
  return (MY_TRUE);
}

t_bool		list_add_elem_at_position(t_list *front_ptr, void *elem,
					  unsigned int position)
{
  t_list	tmp;
  t_list	new;
  t_list	last;
  unsigned int	cursor;

  if (position == 0 || front_ptr == NULL)
    return (list_add_elem_at_front(front_ptr, elem));
  if ((tmp = last->next) == NULL)
    return (list_add_elem_at_back(front_ptr, elem));
  if (list_at_position_prepare(&cursor, &last, &new, front_ptr) == MY_FALSE)
    return (MY_FALSE);
  new->value = elem;
  while (tmp != NULL)
    {
      if (position == cursor++)
	{
	  last->next = new;
	  new->next = tmp;
	  return (MY_TRUE);
	}
      last = tmp;
      tmp = tmp->next;
    }
  return (MY_FALSE);
}
