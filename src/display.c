#include "push_swap.h"

int	display(size_t	n, t_head *h)
{
	size_t		i;
	t_list_swap *s;

	i = 0;
	if (n > 100)
		return 0;
	s = h->stack;
	ft_printf(ESC "[H");
	ft_printf(ESC "[2J");
	ft_printf(ESC "[H");
	ft_printf(ESC "[%dm", B_BLUE);
	ft_printf("Stack A | Stack B\n");
	while (i < n)
	{
		ft_printf("%d\t|\t\n", s->number);
		s = s->next;
		i++;
	}
	ft_printf(ESC "[0m");
	return (int)h->size;
}
