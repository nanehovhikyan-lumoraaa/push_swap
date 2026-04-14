NAME := checker
CC	:= cc
CFLAGS := -Wall -Wextra -Werror -I .

SRCS		= bonus.c \
		  bonus_impl.c \
		  utils_bonus.c \
		  helpers.c \
		  get_next_line/get_next_line.c \
		  get_next_line/get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

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

bonus: all

.PHONY: all clean fclean re bonus