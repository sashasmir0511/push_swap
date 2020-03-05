/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:25:25 by lhaired           #+#    #+#             */
/*   Updated: 2020/03/03 21:25:28 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		needs_pb(t_head *head_a)
{
	size_t		i;
	t_list_swap	*current;

	if (head_a)
	{
		i = 0;
		current = head_a->stack;
		while (i < head_a->size)
		{
			if (!current->keep_in_stack)
				return (1);
			i++;
			current = current->next;
		}
	}
	return (0);
}

static int		needs_sa(t_head *head_a,
					size_t (*markup_stack)(t_head *, t_list_swap *))
{
	size_t		current_pairs;

	if (head_a && head_a->size >= 2)
	{
		lst_swap(head_a);
		current_pairs = markup_stack(head_a, head_a->markup_stack);
		lst_swap(head_a);
		markup_stack(head_a, head_a->markup_stack);
		if (current_pairs > head_a->pairs)
			return (1);
	}
	return (0);
}

void			solve_a(t_head *head_a, t_head *head_b,
					size_t (*markup_stack)(t_head *, t_list_swap *),
					t_command_list *command_list)
{
	while (needs_pb(head_a))
	{
		if (needs_sa(head_a, markup_stack))
		{
			lst_swap(head_a);
			lst_add_command(command_list, lst_create_command("sa"));
			head_a->pairs = markup_stack(head_a, head_a->markup_stack);
		}
		else if (head_a->stack->keep_in_stack == 0)
		{
			lst_push(head_a, head_b);
			lst_add_command(command_list, lst_create_command("pb"));
		}
		else
		{
			lst_rotate(head_a);
			lst_add_command(command_list, lst_create_command("ra"));
		}
	}
}
