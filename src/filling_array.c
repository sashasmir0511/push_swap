/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:10:30 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/25 12:10:31 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			ft_free_2d_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	while (--i != -1)
		free(str[i]);
	free(str);
}

static long	long	ft_atol_ps(const char *str)
{
	int					negative;
	unsigned long long	res;

	res = 0;
	negative = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' \
			|| *str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-' && str++)
		negative = -1;
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + ((int)*str - 48);
		str++;
		if (res > INT_MAX)
			error_exit();
	}
	return (res * negative);
}

static int			*cutter(int count, int *stack, char **av)
{
	int		i;
	char	**temp;
	int		j;
	int		k;

	i = 0;
	k = 1;
	j = 0;
	temp = NULL;
	while (i != count)
	{
		j = 0;
		temp = ft_strsplit(av[k], ' ');
		while (temp[j] != NULL)
		{
			if (ft_atol_ps(temp[j]) >= INT_MIN
			&& ft_atol_ps(temp[j]) <= INT_MAX)
				stack[i++] = ft_atoi(temp[j++]);
			else
				error_exit();
		}
		ft_free_2d_arr(temp);
		k++;
	}
	return (stack);
}

int					*filling_array(int count, char **argv)
{
	int		*tab;

	if (!(tab = (int *)ft_memalloc(sizeof(int) * count)))
		return (NULL);
	ft_bzero(tab, count);
	tab[0] = 0;
	tab = cutter(count, tab, argv);
	return (tab);
}
