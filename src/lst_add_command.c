/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:07:12 by lhaired           #+#    #+#             */
/*   Updated: 2020/03/03 21:07:14 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_add_command(t_command_list *list, t_command *command)
{
	t_command	*last;

	if (list && command)
	{
		if (!list->head)
			list->head = command;
		else
		{
			last = list->head;
			while (last->next)
				last = last->next;
			last->next = command;
		}
		list->size++;
	}
}
