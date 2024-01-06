# Variables

NAME = push_swap
CHECKER_NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src/
OBJ_DIR = obj/
LIB_DIR = libft/
INCLUDES = -I include/ -I $(LIB_DIR)

# Source and Object files

PUSH_SWAP_SRC = indexing.c parse.c push_swap.c sort_large.c sort_small.c sort_utils.c stack_operations.c stack_operations2.c stack_rotations.c stack_rotations2.c stack_utils.c stack.c utilities.c
CHECKER_SRC = checker.c parse_bonus.c stack_operations_bonus.c $(filter-out push_swap.c, $(PUSH_SWAP_SRC))

PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

# Rules

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR), $(PUSH_SWAP_OBJ))
	@$(MAKE) -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(addprefix $(OBJ_DIR), $(PUSH_SWAP_OBJ)) -L$(LIB_DIR) -lft
	@echo "Compilation of push_swap complete."

bonus: $(addprefix $(OBJ_DIR), $(CHECKER_OBJ))
	@$(MAKE) -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(CHECKER_NAME) $(addprefix $(OBJ_DIR), $(CHECKER_OBJ)) -L$(LIB_DIR) -lft
	@echo "Compilation of checker complete."

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned object files."

fclean: clean
	@$(MAKE) -C $(LIB_DIR) fclean
	@rm -f $(NAME) $(CHECKER_NAME)
	@echo "Cleaned everything."

re: fclean all

.PHONY: all clean fclean re bonus
