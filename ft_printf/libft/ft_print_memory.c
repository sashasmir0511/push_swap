/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:10:15 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/24 16:10:18 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_space(size_t j)
{
	while (j < 16)
	{
		write(1, "  ", 2);
		if (j % 2)
			write(1, " ", 1);
		j++;
	}
}

static void	print_dot(unsigned char *p, size_t i, size_t size)
{
	size_t	j;

	j = 0;
	while (j < 16 && i + j < size)
	{
		if (*(p + i + j) >= 32 && *(p + i + j) < 127)
			write(1, p + i + j, 1);
		else
			write(1, ".", 1);
		j += 1;
	}
}

void		ft_print_memory(const void *addr, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned char	*p;
	char			*str;

	str = "0123456789abcdef";
	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 16 && i + j < size)
		{
			write(1, &str[(*(p + i + j) / 16) % 16], 1);
			write(1, &str[*(p + i + j) % 16], 1);
			if (j % 2)
				write(1, " ", 1);
			j += 1;
		}
		print_space(j);
		print_dot(p, i, size);
		write(1, "\n", 1);
		i += 16;
	}
}
