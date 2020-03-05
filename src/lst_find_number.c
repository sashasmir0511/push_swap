/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:15:44 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/25 14:15:45 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_swap		*lst_find_number(t_head *head, int f)
{
	t_list_swap	*lst;

	lst = head->stack;
	if (!lst)
		return (NULL);
	if (lst->number == f)
		return (lst);
	lst = lst->next;
	while (lst != head->stack)
	{
		if (lst->number == f)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
