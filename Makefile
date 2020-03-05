# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhaired <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 18:13:39 by lhaired           #+#    #+#              #
#    Updated: 2020/02/24 18:13:40 by lhaired          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME_PUSH = push_swap
NAME_CHECKER = checker

SRC = check_dooble.c check_sort_stack.c counter.c direction.c \
	error_exit.c filling_array.c is_valid.c lst_add_command.c \
	lst_create_command.c lst_delete.c lst_find_number.c lst_free_command.c \
	lst_init_b.c lst_init_command.c lst_make_for_tab.c lst_print.c lst_push.c\
	lst_reverse_rotate.c lst_rotate.c lst_swap.c lstadd.c lstnew.c \
	make_stack.c opt_markup_stack.c print_commands.c push_swap.c quick_sort.c\
	read_instructions.c set_index.c solve.c solve_a.c solve_b.c \

OBJ = $(SRC:.c=.o)

SRC_CH = check_dooble.c check_sort_stack.c checker.c counter.c direction.c \
	error_exit.c filling_array.c is_valid.c lst_add_command.c \
	lst_create_command.c lst_delete.c lst_find_number.c lst_free_command.c \
	lst_init_b.c lst_init_command.c lst_make_for_tab.c lst_print.c lst_push.c\
	lst_reverse_rotate.c lst_rotate.c lst_swap.c lstadd.c lstnew.c \
	make_stack.c opt_markup_stack.c quick_sort.c\
	read_instructions.c set_index.c solve.c solve_a.c solve_b.c \

OBJ_CH = $(SRC_CH:.c=.o)

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

SRCS=$(addprefix $(SRC_DIR)/,$(SRC))
SRCS_CH=$(addprefix $(SRC_DIR)/,$(SRC_CH))
OBJS=$(addprefix $(OBJ_DIR)/,$(OBJ))
OBJS_CH=$(addprefix $(OBJ_DIR)/,$(OBJ_CH))

all: $(NAME_PUSH) $(NAME_CHECKER)

$(NAME_PUSH): $(OBJS)
	@make -C ft_printf
	@$(CC)  $(CFLAGS) -o $(NAME_PUSH) $(OBJS) -L ft_printf -lftprintf

$(NAME_CHECKER): $(OBJS_CH)
	@make -C ft_printf
	@$(CC)  $(CFLAGS) -o $(NAME_CHECKER) $(OBJS_CH) -L ft_printf -lftprintf

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@make clean -C ft_printf
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME_PUSH)
	@/bin/rm -f $(NAME_CHECKER)
	@make fclean -C ft_printf

re: fclean all
