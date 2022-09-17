NAME = libftprintf.a
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
	ft_printf_needs.c \
	ft_printf_needs2.c


OBJS = $(SRCS:.c=.o)

all:	$(NAME)

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
		ar crs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:		fclean $(NAME)