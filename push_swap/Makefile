# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 18:40:44 by daheepark         #+#    #+#              #
#    Updated: 2023/03/06 01:29:55 by daheepark        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

SRCS =	main.c \
		check.c \
		stack_utils.c \
		make_stack.c \
		working.c \
		sorting.c \
		sorting_min.c \
	
OBJS =	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)
fclean	:	clean
			$(RM) push_swap

re	:	fclean 
		make all

.PHONY	:	all clean fclean re