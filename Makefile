# Names of the executables
NAME          := push_swap
BONUS_NAME    := checker

# Compilation settings
CC            := cc
CFLAGS        := -Wall -Wextra -Werror -I .

# Mandatory source files
SRCS          := main/main.c \
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

# Bonus source files
BONUS_SRCS    := bonus/bonus.c \
                 bonus/bonus_impl.c \
                 bonus/utils_bonus.c \
                 bonus/helpers.c \
                 bonus/get_next_line/get_next_line.c \
                 bonus/get_next_line/get_next_line_utils.c

# Object file generation
OBJS          := $(SRCS:.c=.o)
BONUS_OBJS    := $(BONUS_SRCS:.c=.o)

# Default target (Mandatory)
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Bonus target
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

# Generic rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleanup rules
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus