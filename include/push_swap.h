/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:56:32 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/24 15:56:34 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../ft_printf/include/ft_printf.h"
# include "../ft_printf/include/get_next_line.h"
# include <stdlib.h>
# include <limits.h>

typedef enum
{
	R,
	RR
}	t_direction;

typedef struct	s_list_swap
{
	int					number;
	size_t				index;
	int					keep_in_stack;
	struct s_list_swap	*next;
	struct s_list_swap	*prev;
}				t_list_swap;

typedef struct	s_head
{
	t_list_swap			*stack;
	t_list_swap			*markup_stack;
	size_t				size;
	size_t				pairs;
}				t_head;

typedef struct	s_command
{
	char				*name;
	struct s_command	*next;
}				t_command;

typedef struct	s_command_list
{
	size_t				size;
	t_command			*head;
}				t_command_list;

typedef struct	s_shift_info
{
	t_list_swap			*a_elem;
	t_list_swap			*b_elem;
	int					a_direction;
	int					b_direction;
	size_t				size;
	int					is_set;
}				t_shift_info;

/*
**--------------List Function--------------------------------------------
*/
t_list_swap		*lstnew(int number);
void			lstadd(t_head *head, t_list_swap *new);
void			lst_rotate(t_head *head);
void			lst_rotate_rr(t_head *head_a, t_head *head_b);
void			lst_reverse_rotate(t_head *head);
void			lst_reverse_rotate_rrr(t_head *head_a, t_head *head_b);
void			lst_swap(t_head *head);
void			lst_swap_ss(t_head *head_a, t_head *head_b);
void			lst_push(t_head *head_from, t_head *head_to);
void			lst_print(t_head *head);
t_head			*lst_make_for_tab(int count, int *tab);
void			lst_delete(t_head *head);
t_list_swap		*lst_find_number(t_head *head, int f);
t_command		*lst_create_command(const char *name);
void			lst_add_command(t_command_list *list, t_command *command);
t_head			*lst_init_b();
t_command_list	*lst_init_command(void);
void			free_command_list(t_command_list *list);
void			print_commands(t_command_list *list);
/*
**-----------------------------------------------------------------------
*/

/*
**--------------Quick Sort-----------------------------------------------
*/
void			quick_sort(int *tab, int left, int right);
int				*filling_array(int argc, char **argv);
void			set_index(int *tab, int size, t_head *head);
/*
**-----------------------------------------------------------------------
*/

/*
**--------------ERROR----------------------------------------------------
*/
void			error_exit();
int				*is_valid(int argc, char **argv);
int				check_dooble(int count, int *av);
int				counter(char **av);
/*
**-----------------------------------------------------------------------
*/

/*
**--------------Sort_stack-----------------------------------------------
*/
t_command_list	*solve(t_head *head_a,
					size_t (*markup_stack)(t_head *, t_list_swap *));
void			solve_a(t_head *head_a, t_head *head_b,
					size_t (*markup_stack)(t_head *, t_list_swap *),
					t_command_list *command_list);
void			solve_b(t_head *head_a, t_head *head_b,
					t_command_list *command_list);
t_head			*make_stack(int argc, char **argv);
void			opt_markup_stack(t_head *head_a,
					size_t (*markup_stack)(t_head *, t_list_swap *));
size_t			markup_stack_index(t_head *head_a,
					t_list_swap *markup_head);
void			opt_direction(t_head *head_a, t_head *head_b,
					t_shift_info *shift_info);
/*
**-----------------------------------------------------------------------
*/

/*
**--------------Checker--------------------------------------------------
*/
int				check_dooble_stack(t_head *head_a);
void			read_instructions(t_head *head_a, t_head *head_b);
int				check_sort_stack(t_head *head);
/*
**-----------------------------------------------------------------------
*/
#endif
