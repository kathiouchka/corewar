# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybeaure <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 09:52:13 by ybeaure           #+#    #+#              #
#    Updated: 2016/12/15 12:56:04 by ybeaure          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		corewar

FILES =		main.c \
			boot_vm.c \
			op.c \
			init_champs.c \
			init_cycle.c \
			file_parsing.c \
			others.c \
			start_fight.c \
			init_ram.c \
			b_swap.c \
			aff.c \
			add_sub_and.c \
			fork_lfork.c \
			ld_lld_st.c \
			ldi_lldi_sti.c \
			live.c \
			or_xor.c \
			zjmp.c \
			update_cycle.c \

SRCS =		$(addprefix srcs/, $(FILES))

OBJS =		$(SRCS:.c=.o)

DEBUG =		-fsanitize=address

FLAGS =		-Wall -Werror -Wextra $(DEBUG)

CC =		gcc

all: libft/libft.a $(NAME)

libft/libft.a:
	make -C ./libft/

$(%.o): $(%.c)
	$(CC) $(FLAGS) -o $@ -c $^

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^ -Llibft -lft

clean:
	@make -C ./libft/ clean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft/ fclean

re: fclean all clean

.PHONY: clean
