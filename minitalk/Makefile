.SUFFIX: .c.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS_CLIENT = tool.c client.c

SRCS_SERVER = tool.c server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

NAME_SERVER = server

NAME_CLIENT = client

all : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER) : $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $@

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all