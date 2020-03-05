/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:07:53 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/25 14:07:55 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(int *tab, int size, t_head *head)
{
	t_list_swap	*tmp;
	int			i;

	i = 0;
	while (i < size)
	{
		tmp = lst_find_number(head, tab[i]);
		if (!tmp)
			return ;
		tmp->index = i;
		i++;
	}
}
