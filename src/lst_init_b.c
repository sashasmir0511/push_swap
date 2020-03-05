/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:49:25 by lhaired           #+#    #+#             */
/*   Updated: 2020/03/03 20:49:26 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head	*lst_init_b(void)
{
	t_head	*head;

	if (!(head = (t_head *)ft_memalloc(sizeof(t_head))))
		error_exit();
	head->markup_stack = NULL;
	head->stack = NULL;
	head->pairs = 0;
	head->size = 0;
	return (head);
}
