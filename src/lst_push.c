/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:30:59 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/24 17:31:01 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	for_norm(t_head *head_to, t_list_swap *tmp)
{
	if (head_to->stack)
	{
		tmp->next = head_to->stack;
		tmp->prev = (head_to->stack)->prev;
		head_to->stack = tmp;
		(head_to->stack)->next->prev = (head_to->stack);
		(head_to->stack)->prev->next = (head_to->stack);
	}
	else
	{
		tmp->next = tmp;
		tmp->prev = tmp;
		head_to->stack = tmp;
	}
}

void		lst_push(t_head *head_from, t_head *head_to)
{
	t_list_swap		*tmp;

	if (head_from->stack == NULL)
		return ;
	if (head_from->size > 1)
	{
		(head_from->stack)->prev->next = (head_from->stack)->next;
		(head_from->stack)->next->prev = (head_from->stack)->prev;
		tmp = head_from->stack;
		head_from->stack = (head_from->stack)->next;
	}
	else
	{
		tmp = head_from->stack;
		head_from->stack = NULL;
	}
	for_norm(head_to, tmp);
	head_from->size--;
	head_to->size++;
}
