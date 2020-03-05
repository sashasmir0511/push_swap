/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:45:40 by lhaired           #+#    #+#             */
/*   Updated: 2020/03/03 20:45:42 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		for_norm(t_head *head_a,
					t_command_list *command_list,
					size_t ra_size, size_t rra_size)
{
	while (head_a->stack->index != 0 && (ra_size < rra_size))
	{
		lst_rotate(head_a);
		lst_add_command(command_list, lst_create_command("ra"));
	}
	while (head_a->stack->index != 0 && !(ra_size < rra_size))
	{
		lst_reverse_rotate(head_a);
		lst_add_command(command_list, lst_create_command("rra"));
	}
}

static void		align_a(t_head *head_a,
					t_command_list *command_list)
{
	t_list_swap		*current;
	size_t			ra_size;
	size_t			rra_size;

	if (head_a && head_a->stack)
	{
		ra_size = 0;
		current = head_a->stack;
		while (current->index != 0)
		{
			ra_size++;
			current = current->next;
		}
		rra_size = 0;
		current = head_a->stack;
		while (current->index != 0)
		{
			rra_size++;
			current = current->prev;
		}
		for_norm(head_a, command_list, ra_size, rra_size);
	}
}

t_command_list	*solve(t_head *head_a, \
				size_t (*markup_stack)(t_head *, t_list_swap *))
{
	t_command_list	*command_list;
	t_head			*head_b;

	command_list = lst_init_command();
	head_b = lst_init_b();
	solve_a(head_a, head_b, markup_stack, command_list);
	solve_b(head_a, head_b, command_list);
	align_a(head_a, command_list);
	lst_delete(head_b);
	return (command_list);
}
