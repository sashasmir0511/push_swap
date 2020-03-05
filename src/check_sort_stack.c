/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:54:02 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/27 19:54:04 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sort_stack(t_head *head)
{
	t_list_swap	*tmp;
	int			i;

	tmp = head->stack;
	if (!tmp)
		return (1);
	i = tmp->number;
	tmp = tmp->next;
	while (head->stack != tmp)
	{
		if (tmp->number <= i)
			return (1);
		i = tmp->number;
		tmp = tmp->next;
	}
	return (0);
}
