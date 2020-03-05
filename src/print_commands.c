/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:24:50 by lhaired           #+#    #+#             */
/*   Updated: 2020/03/05 14:24:51 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_commands(t_command_list *list)
{
	t_command *current;

	current = list->head;
	while (current)
	{
		ft_putendl(current->name);
		current = current->next;
	}
}
