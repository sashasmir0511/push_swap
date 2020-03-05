/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:57:02 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/24 16:57:04 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_rotate(t_head *head)
{
	if (head->stack != NULL)
	{
		head->stack = (head->stack)->next;
	}
}

void	lst_rotate_rr(t_head *head_a, t_head *head_b)
{
	lst_rotate(head_a);
	lst_rotate(head_b);
}
