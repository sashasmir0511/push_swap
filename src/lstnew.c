/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:27:05 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/24 16:27:06 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_swap	*lstnew(int number)
{
	t_list_swap	*list;

	if (!(list = (t_list_swap*)ft_memalloc(sizeof(t_list_swap))))
		return (NULL);
	list->number = number;
	list->index = 0;
	list->next = list;
	list->prev = list;
	list->keep_in_stack = 0;
	return (list);
}
