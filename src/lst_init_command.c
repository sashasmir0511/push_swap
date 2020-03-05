/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:55:23 by lhaired           #+#    #+#             */
/*   Updated: 2020/03/03 20:55:24 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_command_list	*lst_init_command(void)
{
	t_command_list	*list;

	if (!(list = (t_command_list *)ft_memalloc(sizeof(t_command_list))))
		error_exit();
	list->size = 0;
	list->head = NULL;
	return (list);
}
