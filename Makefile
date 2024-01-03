# Variables

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src/
OBJ_DIR = obj/
LIB_DIR = libft/
INCLUDES = -I include/ -I $(LIB_DIR)

# Source and Object files

SRC_FILES = indexing.c parse.c push_swap.c sort_large.c sort_small.c sort_utils.c stack_operations.c stack_operations2.c stack_rotations.c stack_rotations2.c stack_utils.c stack.c utilities.c
OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# Rules

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) -L$(LIB_DIR) -lft
	@echo "Compilation complete."

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned object files."

fclean: clean
	@$(MAKE) -C $(LIB_DIR) fclean
	@rm -f $(NAME)
	@echo "Cleaned everything."

re: fclean all

.PHONY: all clean fclean re