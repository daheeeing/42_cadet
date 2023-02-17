# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 18:40:44 by daheepark         #+#    #+#              #
#    Updated: 2023/01/26 18:43:44 by daheepark        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT =	make -C libft

SRCS =	main.c \
		

OBJS =	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

clean	:
			$(RM) $(OBJS)
			make -C libft clean
fclean	:	clean
			$(RM) push_swap libft/libft.a

re	:	fclean 
		make all

.PHONY	:	all clean fclean re