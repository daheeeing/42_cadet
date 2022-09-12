NAME = libftprintf.a
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
SRCS =

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
			$(RM) libftpriontf.h.gch

re:		fclean $(NAME)