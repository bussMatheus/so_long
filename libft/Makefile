SRC = so_long.c parse_map.c validate_map.c \
	render.c clean.c utils.c validate_map_utils.c \
	init_game.c hooks.c

OBJ = $(SRC:%.c=%.o)

NAME = so_long

CC = cc
FLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -rf

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX = ${MLX_DIR}/libmlx.a

LIBS = ${LIBFT} ${MLX} -lXext -lX11 -lm -lbsd

# ANSI color codes
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m
NC = \033[0m  # No Color (reset)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) ${MLX}
	$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "$(GREEN)Compiled so_long successfully$(NC)"

#Run libft's makefile in the libft directory

$(OBJS): %.o: %.c
	@echo "$(BLUE)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

clean:
	@echo "$(RED)Removing object files: $(NAME)$(NC)"
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@echo "$(RED)Removing static library: $(NAME)$(NC)"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re