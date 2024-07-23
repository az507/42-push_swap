# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achak <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 08:34:23 by achak             #+#    #+#              #
#    Updated: 2024/02/24 13:30:19 by achak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= main.c ft_split.c helper_fns.c helper_fns2.c instructions.c \
	  instructions2.c instructions3.c sort_stack.c rotate_both.c \
	  push_swap.c cleanup.c check_stack.c

OBJ	= ${SRCS:.c=.o}

BONUS	= checker

BONUS_S = get_next_line.c get_next_line_utils.c checker.c instructions.c \
	  instructions2.c instructions3.c push_swap.c ft_split.c helper_fns.c \
	  cleanup.c check_stack.c

BONUS_O	= ${BONUS_S:.c=.o}

CC	= cc -g -Wall -Werror -Wextra

AR	= ar rcs

all:	$(NAME)

$(NAME):
	$(CC) -c $(SRCS)
	$(AR) $(NAME) $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

bonus:	$(BONUS)

$(BONUS): $(BONUS_S) $(SRCS)
	$(CC) -c $(BONUS_S) $(SRCS)
	$(AR) $(BONUS) $(BONUS_O) $(OBJ)
	$(CC) $(BONUS_O) -o $(BONUS)

clean:
	rm -rf $(OBJ) $(BONUS_O)

fclean:	clean
	rm -rf $(NAME) $(BONUS) a.out

re:	fclean all
