/*
** list_make_circle.c for generic_list in /home/caudou_j/Documents/projets/arduino
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Sun May 18 22:57:40 2014 caudou_j
** Last update Sun May 18 23:29:25 2014 caudou_j
*/

#include	<stdlib.h>
#include	"generic_list.h"

void		list_make_circle(t_list list)
{
  t_list	head;

  if (list == NULL)
    return ;
  head = list;
  while (list != NULL)
    {
      if (list->next == NULL)
	{
	  list->next = head;
	  return ;
	}
      list = list->next;
      if (list == head)
	return ;
    }
  return ;
}
