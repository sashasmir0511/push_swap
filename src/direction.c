/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:05:05 by lhaired           #+#    #+#             */
/*   Updated: 2020/03/05 13:05:06 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list_swap	*find_a_elem(t_head *head_a, size_t index)
{
	t_list_swap	*current;

	current = head_a->markup_stack;
	if (index < current->index)
	{
		while (index < current->prev->index
			&& current->index > current->prev->index)
			current = current->prev;
	}
	else
	{
		while (index > current->index
			&& current->index < current->next->index)
			current = current->next;
		if (index > current->index && current->index > current->next->index)
			current = current->next;
	}
	return (current);
}

static void			estimate_direction(t_head *head, size_t index,
						size_t *rx_size, size_t *rrx_size)
{
	t_list_swap		*current;

	if (head && head->stack)
	{
		current = head->stack;
		while (current->index != index)
		{
			(*rx_size)++;
			current = current->next;
		}
		current = head->stack;
		while (current->index != index)
		{
			(*rrx_size)++;
			current = current->prev;
		}
	}
}

static void			set_direction(size_t size,
						t_shift_info new, t_shift_info *shift_info)
{
	if (!shift_info->is_set || size < shift_info->size)
	{
		shift_info->a_elem = new.a_elem;
		shift_info->b_elem = new.b_elem;
		shift_info->a_direction = new.a_direction;
		shift_info->b_direction = new.b_direction;
		shift_info->size = size;
		shift_info->is_set = 1;
	}
}

static void			optimal_direction(t_head *head_a, t_head *head_b,
						t_list_swap *b_elem, t_shift_info *shift_info)
{
	t_shift_info	new_shift_info;
	size_t			ra_size;
	size_t			rra_size;
	size_t			rb_size;
	size_t			rrb_size;

	ra_size = 0;
	rra_size = 0;
	rb_size = 0;
	rrb_size = 0;
	new_shift_info.a_elem = find_a_elem(head_a, b_elem->index);
	new_shift_info.b_elem = b_elem;
	estimate_direction(head_a, new_shift_info.a_elem->index,
						&ra_size, &rra_size);
	estimate_direction(head_b, b_elem->index,
						&rb_size, &rrb_size);
	new_shift_info.a_direction = R;
	new_shift_info.b_direction = R;
	set_direction(ft_max(ra_size, rb_size), new_shift_info, shift_info);
	new_shift_info.a_direction = RR;
	set_direction(rra_size + rb_size, new_shift_info, shift_info);
	new_shift_info.b_direction = RR;
	set_direction(ft_max(rra_size, rrb_size), new_shift_info, shift_info);
	new_shift_info.a_direction = R;
	set_direction(ra_size + rrb_size, new_shift_info, shift_info);
}

void				opt_direction(t_head *head_a, t_head *head_b,\
						t_shift_info *shift_info)
{
	size_t		i;
	t_list_swap *current;

	if (head_b)
	{
		i = 0;
		current = head_b->stack;
		while (i < head_b->size)
		{
			optimal_direction(head_a, head_b, current, shift_info);
			i++;
			current = current->next;
		}
	}
}
