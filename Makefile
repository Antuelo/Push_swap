NAME = push_swap
SRCS = src/main.c src/transformation.c src/ft_split.c src/sort_mysort.c \
		src/sort_radix_index.c src/sort_radix.c src/sort_small.c src/sort_tiny_inverse.c \
		src/sort_tiny.c src/stack_operations.c src/stack_operations2.c src/stack_utils.c \
		src/stack_utils2.c src/ft_strdup.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
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
