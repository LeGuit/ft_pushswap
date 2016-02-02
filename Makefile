# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 16:48:42 by gwoodwar          #+#    #+#              #
#    Updated: 2016/02/02 14:01:20 by gwoodwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	gcc
FLAGS =	-Wall -Werror -Wextra
NAME =	push_swap
LIB =	libft/libftprintf.a
HEAD =	ft_pushswap.h

SRCS =	test_arg.c \
		ps_parse.c \
		ps_print.c \
		ps_exit.c \
		ps_solve.c \
		algo.c \
		ope_lst.c \
		main.c

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

$(LIB):
	make -C libft/ fclean
	make -C libft/

$(NAME): $(LIB) $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS) $(LIB)

%.o: %.c
	$(CC) $(FLAGS) -I $(HEAD) -o $@ -c $<

clean:
	make -C libft/ clean
	@/bin/rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

help:
	@echo "Option available -v -c"
	@echo "If you have an error check your arguments"
