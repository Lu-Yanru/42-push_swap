NAME = push_swap

# Directories
SRCDIR = srcs
INCDIR = includes
LIBDIR = libft
CHECKDIR = checker

# Source files and obj files
SRC = $(addprefix $(SRCDIR)/, \
	main.c \
	main_utils.c \
	check_args.c \
	check_args_utils.c \
	stack_init.c \
	stack_utils.c \
	op_swap.c \
	op_rotate.c \
	op_rev_rotate.c \
	op_push.c \
	sort.c \
	sort_lis.c \
	sort_push.c \
	sort_cost.c \
	sort_cost_utils.c \
)

CHECKSRC = $(addprefix $(CHECKDIR)/, \
	checker.c \
	checker_utils.c \
	read_line.c \
	exc_ops.c \
)

OBJ = $(SRC:.c=.o)

CHECKOBJ = $(CHECKSRC:.c=.o)

HEADER = $(addprefix $(INCDIR)/, push_swap.h)

LIBFT = libft/libft.a

CHECKHEAD = checker/checker.h

CHECKNAME = checker

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Rules
all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCDIR) $(OBJ) $(LIBFT) -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

bonus:

clean:
	$(MAKE) clean -C $(LIBDIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
