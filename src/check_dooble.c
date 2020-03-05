/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dooble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:35:27 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/25 16:35:29 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_dooble_stack(t_head *head_a)
{
	size_t		i;
	size_t		j;
	t_list_swap	*a;
	t_list_swap	*b;

	i = 0;
	a = head_a->stack;
	while (i < head_a->size)
	{
		j = i + 1;
		b = a->next;
		while (j < head_a->size)
		{
			if (a->number == b->number)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_dooble(int count, int *av)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (av[i] == av[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
