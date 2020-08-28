/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:55:55 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/24 18:55:56 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_head			*head_a;
	t_command_list	*command;

	if (argc >= 2)
	{
		if (!(head_a = make_stack(argc, argv)))
			error_exit();
		opt_markup_stack(head_a, &markup_stack_index);
		command = solve(head_a, &markup_stack_index);
		lst_delete(head_a);
		print_commands(command);
		free_command_list(command);
	}
	else
		error_exit();
	return (0);
}
