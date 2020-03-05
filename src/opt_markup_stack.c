/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_markup_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:36:28 by lhaired           #+#    #+#             */
/*   Updated: 2020/03/03 19:36:30 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	markup_stack_index(t_head *head_a, t_list_swap *markup_head)
{
	size_t			index;
	size_t			pairs;
	t_list_swap		*current;

	pairs = 0;
	if (head_a && markup_head)
	{
		index = markup_head->index;
		markup_head->keep_in_stack = 1;
		current = markup_head->next;
		while (current != markup_head)
		{
			if (current->index == index + 1)
			{
				pairs++;
				index++;
				current->keep_in_stack = 1;
			}
			else
				current->keep_in_stack = 0;
			current = current->next;
		}
	}
	return (pairs);
}

void	opt_markup_stack(t_head *head_a,
						size_t (*markup_stack)(t_head *, t_list_swap *))
{
	size_t			i;
	size_t			current_pairs;
	t_list_swap		*current;

	if (head_a)
	{
		i = 0;
		current = head_a->stack;
		while (i < head_a->size)
		{
			current_pairs = markup_stack(head_a, current);
			if (current_pairs > head_a->pairs)
			{
				head_a->markup_stack = current;
				head_a->pairs = current_pairs;
			}
			else if (current_pairs == head_a->pairs &&
			(!(head_a->markup_stack) || current->number
			< head_a->markup_stack->number))
				head_a->markup_stack = current;
			i++;
			current = current->next;
		}
	}
	markup_stack(head_a, head_a->markup_stack);
}
