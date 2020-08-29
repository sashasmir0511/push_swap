/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:52:09 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/27 17:52:10 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear(t_head *head_a, t_head *head_b)
{
	lst_delete(head_a);
	lst_delete(head_b);
}

int			main(int argc, char **argv)
{
	t_head	*head_a;
	t_head	*head_b;

	head_a = NULL;
	if (!(head_b = (t_head *)ft_memalloc(sizeof(t_head))))
		error_exit();
	head_b->stack = NULL;
	head_b->size = 0;
	if (argc >= 2)
	{
		if (!(head_a = make_stack(argc, argv)))
		{
			clear(head_a, head_b);
			error_exit();
		}
		read_instructions(head_a, head_b);
		clear(head_a, head_b);
	}
	else
		clear(head_a, head_b);
	return (0);
}
