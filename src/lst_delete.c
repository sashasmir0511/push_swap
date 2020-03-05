/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:30:23 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/24 19:30:24 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_swap	*lst_delete_one(t_list_swap *lst)
{
	t_list_swap	*prev;
	t_list_swap	*next;

	prev = lst->prev;
	next = lst->next;
	if (prev != NULL)
		prev->next = lst->next;
	if (next != NULL)
		next->prev = lst->prev;
	free(lst);
	return (next);
}

void		lst_delete(t_head *head)
{
	if (!head)
		return ;
	while (head->stack)
	{
		(head->stack)->prev->next = NULL;
		head->stack = lst_delete_one(head->stack);
	}
	free(head);
}
