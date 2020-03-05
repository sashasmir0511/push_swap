/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:11:34 by lhaired           #+#    #+#             */
/*   Updated: 2020/03/03 21:11:36 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_command	*lst_create_command(const char *name)
{
	t_command	*command;

	if (!(command = (t_command *)ft_memalloc(sizeof(t_command))))
		error_exit();
	if (!(command->name = ft_strdup(name)))
		error_exit();
	command->next = NULL;
	return (command);
}
