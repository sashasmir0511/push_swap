/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:43:05 by lhaired           #+#    #+#             */
/*   Updated: 2020/03/03 21:43:06 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_shift_info	*init_shift_info(void)
{
	t_shift_info	*shift_info;

	if (!(shift_info = (t_shift_info *)ft_memalloc(sizeof(t_shift_info))))
		error_exit();
	shift_info->a_elem = NULL;
	shift_info->b_elem = NULL;
	shift_info->a_direction = R;
	shift_info->b_direction = R;
	shift_info->size = 0;
	shift_info->is_set = 0;
	return (shift_info);
}

static void			for_norm2(t_head *head_b,
						t_shift_info *shift_info, t_command_list *command_list)
{
	if (shift_info->b_elem != head_b->stack)
	{
		if (shift_info->b_direction == R)
		{
			lst_rotate(head_b);
			lst_add_command(command_list, lst_create_command("rb"));
		}
		else
		{
			lst_reverse_rotate(head_b);
			lst_add_command(command_list, lst_create_command("rrb"));
		}
	}
}

static void			for_norm1(t_head *head_a, t_head *head_b,
						t_shift_info *shift_info, t_command_list *command_list)
{
	if (shift_info->a_elem != head_a->stack)
	{
		if (shift_info->a_direction == R)
		{
			lst_rotate(head_a);
			lst_add_command(command_list, lst_create_command("ra"));
		}
		else
		{
			lst_reverse_rotate(head_a);
			lst_add_command(command_list, lst_create_command("rra"));
		}
	}
	else
		for_norm2(head_b, shift_info, command_list);
}

static void			move_b(t_head *head_a, t_head *head_b,
						t_shift_info *shift_info,
						t_command_list *command_list)
{
	while (shift_info->a_elem != head_a->stack
		|| shift_info->b_elem != head_b->stack)
	{
		if (shift_info->a_direction == shift_info->b_direction
			&& shift_info->a_elem != head_a->stack
			&& shift_info->b_elem != head_b->stack)
		{
			if (shift_info->a_direction == R)
			{
				lst_rotate_rr(head_a, head_b);
				lst_add_command(command_list, lst_create_command("rr"));
			}
			else
			{
				lst_reverse_rotate_rrr(head_a, head_b);
				lst_add_command(command_list, lst_create_command("rrr"));
			}
		}
		else
			for_norm1(head_a, head_b, shift_info, command_list);
	}
}

void				solve_b(t_head *head_a, t_head *head_b,
				t_command_list *command_list)
{
	t_shift_info	*shift_info;

	shift_info = init_shift_info();
	while (head_b->size)
	{
		shift_info->is_set = 0;
		opt_direction(head_a, head_b, shift_info);
		move_b(head_a, head_b, shift_info, command_list);
		lst_push(head_b, head_a);
		lst_add_command(command_list, lst_create_command("pa"));
	}
	free(shift_info);
}
