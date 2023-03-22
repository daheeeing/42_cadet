NAME =	philo

CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=thread

SRCS = main.c\
		init.c \
		philos.c \
		philos_utils.c \

OBJS =	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) philo

re	:	fclean 
		make all

.PHONY	:	all clean fclean re
