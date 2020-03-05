/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_make_for_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:56:53 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/24 17:56:54 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head	*lst_make_for_tab(int count, int *tab)
{
	t_head		*head;
	t_list_swap *new;
	int			i;

	i = count - 1;
	new = NULL;
	if (!(head = (t_head *)ft_memalloc(sizeof(t_head))))
		return (NULL);
	while (i >= 0)
	{
		if (!(new = lstnew(tab[i])))
			return (NULL);
		lstadd(head, new);
		i--;
	}
	head->size = count;
	head->pairs = 0;
	head->markup_stack = NULL;
	return (head);
}
