/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:03:07 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/25 15:03:08 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int				check_only_number(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ' || av[i][j] == '\n' || av[i][j] == '\t' \
				|| av[i][j] == '\f' || av[i][j] == '\v' || av[i][j] == '\r')
				j++;
			if (((av[i][j] == '-' || av[i][j] == ' ') &&
			ft_isdigit(av[i][j + 1])) || ((av[i][j] == '+' || av[i][j] == ' ')
			&& ft_isdigit(av[i][j + 1])))
				j++;
			if (!ft_isdigit(av[i][j]) && av[i][j] != '\0')
				return (0);
			while (ft_isdigit(av[i][j]))
				j++;
			if (av[i][j] != '\t' && av[i][j] != ' ' && av[i][j] != '\0')
				return (0);
		}
	}
	return (1);
}

int						*is_valid(int argc, char **argv)
{
	int				count;
	int				i;
	int				*tab;

	i = 1;
	if (check_only_number(argc, argv))
	{
		count = counter(argv);
		tab = filling_array(count, argv);
	}
	else
		return (NULL);
	if (check_dooble(count, tab))
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}
