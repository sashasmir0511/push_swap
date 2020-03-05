/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:32:46 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/25 12:32:47 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble(int *a, int *b)
{
	int bubble;

	bubble = *a;
	*a = *b;
	*b = bubble;
}

void		quick_sort(int *tab, int left, int right)
{
	int		pivot;
	int		l_hold;
	int		r_hold;

	pivot = left;
	l_hold = left;
	r_hold = right;
	while (left < right)
	{
		while ((tab[right] >= tab[pivot]) && (left < right))
			right--;
		while ((tab[left] <= tab[pivot]) && (left < right))
			left++;
		if (left >= right)
		{
			bubble(&tab[pivot], &tab[right]);
			break ;
		}
		else
			bubble(&tab[left], &tab[right]);
	}
	if (right - l_hold)
		quick_sort(tab, l_hold, right - 1);
	if (r_hold - right)
		quick_sort(tab, right + 1, r_hold);
}
