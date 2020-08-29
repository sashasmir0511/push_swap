/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:23:08 by lhaired           #+#    #+#             */
/*   Updated: 2020/03/03 19:23:09 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head	*make_stack(int argc, char **argv)
{
	int		count;
	int		*tab;
	t_head	*head_a;

	tab = is_valid(argc, argv);
	if (tab == NULL)
		return (NULL);
	count = counter(argv);
	head_a = lst_make_for_tab(count, tab);
	if (head_a == NULL || count == 0)
	{
		lst_delete(head_a);
		free(tab);
		return (NULL);
	}
	quick_sort(tab, 0, count - 1);
	set_index(tab, count, head_a);
	free(tab);
	return (head_a);
}
