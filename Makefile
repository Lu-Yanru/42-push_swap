NAME = push_swap

# Directories
SRCDIR = srcs
INCDIR = includes

# Source files and obj files
SRC = $(addprefix $(SRCDIR)/, \
	main.c \
	main_utils.c \
	check_args.c \
	check_arg_utils.c \
	stack_init.c \
	stack_utils.c \
	op_swap.c \
	op_rotate.c \
	op_rev_rotate.c \
	op_push.c \
	sort.c \
	sort_lis.c \
)

OBJ = $(SRC:.c=.o)

HEADER = $(addprefix $(INCDIR)/, push_swap.h)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
