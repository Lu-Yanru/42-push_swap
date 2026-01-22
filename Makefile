# Program names
NAME = push_swap
BONUS = checker

# Directories
SRCDIR = srcs
INCDIR = includes
LIBFTDIR = libft
CHECKDIR = checker_bonus

# Libraries
LIBFT = $(LIBFTDIR)/libft.a
LIBPS = $(SRCDIR)/libpushswap.a

# Source files and obj files
PSMAIN = push_swap.c
PSMAINOBJ = push_swap.o

PSSRC = $(addprefix $(SRCDIR)/, \
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

PSOBJ = $(PSSRC:.c=.o)

CHECKSRC = $(addprefix $(CHECKDIR)/, \
	checker.c \
	checker_utils.c \
	read_line.c \
	exec_ops.c \
)

CHECKOBJ = $(CHECKSRC:.c=.o)

PSHEADER = $(addprefix $(INCDIR)/, push_swap.h)

CHECKHEADER = $(addprefix $(INCDIR)/, checker.h)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I$(INCDIR) -I$(LIBFTDIR)

# Rules
all: $(NAME)

## push_swap 
$(NAME): $(LIBFT) $(LIBPS) $(PSMAINOBJ)
	$(CC) $(CFLAGS) $(PSMAINOBJ) $(LIBPS) $(LIBFT) -o $(NAME)

## checker
bonus: $(BONUS)

$(BONUS): $(LIBFT) $(LIBPS) $(CHECKOBJ)
	$(CC) $(CFLAGS) $(CHECKOBJ) $(LIBPS) $(LIBFT) -o $(BONUS)

## libpushswap
$(LIBPS): $(PSOBJ)
	ar rcs $(LIBPS) $(PSOBJ)

## libft
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

## Obj compilation
$(SRCDIR)/%.o: $(SRCDIR)/%.c $(PSHEADER)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(PSMAINOBJ): $(PSMAIN) $(PSHEADER)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(CHECKDIR)/%.o: $(CHECKDIR)/%.c $(CHECKHEADER)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

## Cleaning
clean:
	$(MAKE) clean -C $(LIBFTDIR)
	rm -f $(PSOBJ) $(PSMAINOBJ) $(CHECKOBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	rm -f $(NAME) $(BONUS) $(LIBPS)

re: fclean all

.PHONY: all clean fclean re bonus
