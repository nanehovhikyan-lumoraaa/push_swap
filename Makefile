CC := cc
CFLAGS := -Wall -Werror -Wextra -I .
NAME := push_swap
SRCS		:= main/main.c \
			  main/parsing.c \
			  main/valod.c \
			  stack_impl/impl.c \
			  utils/utils.c \
			  utils/ft_split.c \
			  sorts/sort_small.c \
			  sorts/insertion.c \
			  sorts/chunk.c \
			  sorts/radix_sort.c \
			  sorts/adaptive.c \
			  main/bench.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
