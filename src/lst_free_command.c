/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:22:56 by lhaired           #+#    #+#             */
/*   Updated: 2020/03/05 14:22:57 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_command_list(t_command_list *list)
{
	t_command *current;
	t_command *delete;

	current = list->head;
	while (current)
	{
		delete = current;
		current = current->next;
		free(delete->name);
		free(delete);
	}
	free(list);
}
