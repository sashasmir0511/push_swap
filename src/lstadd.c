/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:34:20 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/24 16:34:21 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd(t_head *head, t_list_swap *new)
{
	if (new == NULL)
		return ;
	if (head->stack != NULL)
	{
		new->next = head->stack;
		new->prev = (head->stack)->prev;
		(head->stack)->prev->next = new;
		(head->stack)->prev = new;
	}
	head->stack = new;
}
