/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:24:53 by lhaired           #+#    #+#             */
/*   Updated: 2020/03/03 14:24:55 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		counter(char **av)
{
	int		count;
	int		i;
	int		j;
	char	**temp;

	count = 0;
	i = 0;
	while (av[++i] != NULL)
	{
		j = 0;
		temp = ft_strsplit(av[i], ' ');
		while (temp[j++] != NULL)
			count++;
		while (--j != -1)
			free(temp[j]);
		free(temp);
		temp = NULL;
	}
	return (count);
}
