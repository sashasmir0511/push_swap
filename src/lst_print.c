/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:46:27 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/24 17:46:29 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_print(t_head *head)
{
	int			i;
	t_list_swap *tmp;

	i = 1;
	ft_printf("--------%d--------\n", i);
	ft_printf("number\t%d\nindex\t%d\n", (head->stack)->number, \
				(head->stack)->index);
	ft_printf("-----------------\n");
	tmp = (head->stack)->next;
	while (tmp != (head->stack))
	{
		i++;
		ft_printf("--------%d--------\n", i);
		ft_printf("number\t%d\nindex\t%d\n", tmp->number, tmp->index);
		ft_printf("-----------------\n");
		tmp = tmp->next;
	}
}
