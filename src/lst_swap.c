/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:21:53 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/24 17:21:54 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_swap(t_head *head)
{
	int bubble;

	if (head->stack == NULL)
		return ;
	if ((head->stack)->next == NULL)
		return ;
	bubble = (head->stack)->number;
	(head->stack)->number = (head->stack)->next->number;
	(head->stack)->next->number = bubble;
	bubble = (head->stack)->index;
	(head->stack)->index = (head->stack)->next->index;
	(head->stack)->next->index = bubble;
}

void	lst_swap_ss(t_head *head_a, t_head *head_b)
{
	lst_swap(head_a);
	lst_swap(head_b);
}
