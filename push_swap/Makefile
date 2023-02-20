# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapark <dapark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 18:40:44 by daheepark         #+#    #+#              #
#    Updated: 2023/02/20 17:53:52 by dapark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

SRCS =	main.c \
		check.c \
		parsing_utils.c \
		make_stack.c \
				

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