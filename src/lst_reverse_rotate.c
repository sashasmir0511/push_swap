/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:56:53 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/24 16:56:55 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_reverse_rotate(t_head *head)
{
	if (head->stack != NULL)
		head->stack = (head->stack)->prev;
}

void	lst_reverse_rotate_rrr(t_head *head_a, t_head *head_b)
{
	lst_reverse_rotate(head_a);
	lst_reverse_rotate(head_b);
}
