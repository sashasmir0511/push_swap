/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:47:33 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/27 19:47:35 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear(t_head *head_a, t_head *head_b)
{
	lst_delete(head_a);
	lst_delete(head_b);
}

static int	check_command(t_head *head_a, t_head *head_b, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		lst_swap(head_a);
	else if (ft_strcmp(line, "sb") == 0)
		lst_swap(head_b);
	else if (ft_strcmp(line, "ra") == 0)
		lst_rotate(head_a);
	else if (ft_strcmp(line, "rb") == 0)
		lst_rotate(head_b);
	else if (ft_strcmp(line, "pa") == 0)
		lst_push(head_b, head_a);
	else if (ft_strcmp(line, "pb") == 0)
		lst_push(head_a, head_b);
	else if (ft_strcmp(line, "rra") == 0)
		lst_reverse_rotate(head_a);
	else if (ft_strcmp(line, "rrb") == 0)
		lst_reverse_rotate(head_b);
	else if (ft_strcmp(line, "ss") == 0)
		lst_swap_ss(head_a, head_b);
	else if (ft_strcmp(line, "rrr") == 0)
		lst_reverse_rotate_rrr(head_a, head_b);
	else if (ft_strcmp(line, "rr") == 0)
		lst_rotate_rr(head_a, head_b);
	else
		return (0);
	return (1);
}

void		read_instructions(t_head *head_a, t_head *head_b, int fl)
{
	char	*line;
	size_t	fd;

	fd = 0;
	if (head_a->size == 1)
	{
		ft_printf("OK\n");
		return ;
	}
	fl += 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (!check_command(head_a, head_b, line))
		{
			free(line);
			clear(head_a, head_b);
			error_exit();
		}
		free(line);
	}
	free(line);
	close(fd);
	
	if (!check_sort_stack(head_a) && head_b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
