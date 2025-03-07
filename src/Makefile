NAME = push_swap
SRCS = main.c sort_mysort.c sort_radix_index.c sort_radix.c sort_small.c sort_tiny_inverse.c sort_tiny.c stack_operations.c stack_operations2.c stack_utils.c stack_utils2.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
