# Names of the executables
NAME          := push_swap
BONUS_NAME    := checker

# Compilation settings
CC            := cc
CFLAGS        := -Wall -Wextra -Werror -I .

# Mandatory source files
SRCS          := main/main.c \
                 main/parsing.c \
                 main/parse_helpers.c \
                 main/validation.c \
                 main/val_helpers_1.c \
                 main/val_helpers_2.c \
                 main/bench.c \
                 main/bench_helper.c \
                 stack_impl/impl_1.c \
                 stack_impl/impl_2.c \
                 stack_impl/impl_3.c \
                 stack_impl/impl_helpers.c \
                 utils/utils_str.c \
                 utils/utils_stack.c \
                 utils/split.c \
                 sorts/sort_small.c \
                 sorts/insertion_sort.c \
                 sorts/chunk_sort.c \
                 sorts/radix_sort.c \
                 sorts/chunk_helper.c \
                 sorts/adaptive.c

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