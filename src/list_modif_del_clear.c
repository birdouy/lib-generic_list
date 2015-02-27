/*
** list_modif_del_clear.c for generic_list in /home/caudou_j/Documents/projets/arduino/generic_list/src
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Wed May 14 16:51:56 2014 caudou_j
** Last update Wed May 21 17:48:20 2014 caudou_j
*/

#include	<stdlib.h>
#include	"generic_list.h"

void		list_clear(t_list *front_ptr,
			   void (*free_func)(void *elem))
{
  t_list	last;
  t_list	head;

  head = *front_ptr;
  while (*front_ptr)
    {
      last = (*front_ptr)->next;
      if (free_func != NULL)
	free_func((*front_ptr)->value);
      free(*front_ptr);
      *front_ptr = NULL;
      *front_ptr = last;
      if (*front_ptr == head)
	return ;
    }
}

t_bool		list_del_elem_at_front(t_list *front_ptr)
{
  t_list	next_front;

  if (*front_ptr != NULL)
    {
      next_front = *front_ptr;
      next_front = next_front->next;
      free(*front_ptr);
      *front_ptr = next_front;
      return (MY_TRUE);
    }
  return (MY_FALSE);
}

t_bool		list_del_elem_at_back(t_list *front_ptr)
{
  t_list	tmp;
  t_list	head;

  if (*front_ptr != NULL)
    {
      tmp = *front_ptr;
      head = *front_ptr;
      while (tmp->next != NULL)
	{
	  if (tmp->next->next == NULL)
	    {
	      free(tmp->next->next);
	      tmp->next = NULL;
	      return (MY_TRUE);
	    }
	  tmp = tmp->next;
	  if (tmp == head)
	    return (MY_FALSE);
	}
      free(tmp);
      *front_ptr = NULL;
    }
  return (MY_FALSE);
}

t_bool		list_del_elem_like(t_list *front_ptr, void *value,
				   void (*free_func)(void *value))
{
  t_list	tmp;
  t_list	last;
  t_list	head;

  if (*front_ptr == NULL)
    return (MY_FALSE);
  tmp = *front_ptr;
  last = tmp;
  head = *front_ptr;
  while (tmp != NULL)
    {
      if (tmp->value == value)
	{
	  if (last != tmp)
	    last->next = tmp->next;
	  else
	    *front_ptr = tmp->next;
	  if (free_func != NULL)
	    free_func(tmp->value);
	  free(tmp);
	  return (MY_TRUE);
	}
      last = tmp;
      tmp = tmp->next;
      if (tmp == head)
	return (MY_FALSE);
    }
  return (MY_FALSE);
}

t_bool		list_del_elem_at_position(t_list *front_ptr,
					  unsigned int position)
{
  t_list	last;
  t_list	tmp;
  unsigned int	cursor;
  t_list	head;

  if (*front_ptr == NULL)
    return (MY_FALSE);
  if (position == 0)
    return (list_del_elem_at_front(front_ptr));
  cursor = 1;
  head = *front_ptr;
  last = *front_ptr;
  tmp = last->next;
  while (tmp != NULL)
    {
      if (cursor == position)
	{
	  last->next = tmp->next;
	  free(tmp);
	  return (MY_TRUE);
	}
      cursor++;
      last = tmp;
      tmp = tmp->next;
      if (tmp == head)
	return (MY_FALSE);
    }
  return (MY_FALSE);
}
