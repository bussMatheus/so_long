# Source files
SRC = SRC/ft_atoi.c SRC/ft_bzero.c SRC/ft_isalnum.c SRC/ft_isalpha.c \
    SRC/ft_isascii.c SRC/ft_isdigit.c SRC/ft_isprint.c SRC/ft_memchr.c \
    SRC/ft_memcmp.c SRC/ft_memset.c SRC/ft_strchr.c SRC/ft_strlcat.c \
    SRC/ft_strlen.c SRC/ft_strncmp.c SRC/ft_strnstr.c SRC/ft_strrchr.c \
    SRC/ft_tolower.c SRC/ft_toupper.c SRC/ft_calloc.c SRC/ft_memcpy.c \
    SRC/ft_strjoin.c SRC/ft_strlcpy.c SRC/ft_strdup.c SRC/ft_substr.c \
    SRC/ft_memmove.c SRC/ft_strtrim.c SRC/ft_putchar_fd.c SRC/ft_putstr_fd.c \
    SRC/ft_putendl_fd.c SRC/ft_putnbr_fd.c SRC/ft_itoa.c SRC/ft_strmapi.c \
    SRC/ft_striteri.c SRC/ft_split.c

BONUS_SRC = BONUS/ft_lstadd_front.c BONUS/ft_lstlast.c BONUS/ft_lstnew.c \
        BONUS/ft_lstadd_back.c BONUS/ft_lstdelone.c BONUS/ft_lstclear.c \
        BONUS/ft_lstsize.c BONUS/ft_lstiter.c BONUS/ft_lstmap.c

# Object files
OBJS = $(SRC:%.c=%.o)
OBJBONUS = $(BONUS_SRC:%.c=%.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Library name
NAME = libft.a

# Archive command
AR = ar rcs

# ANSI color codes
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m
NC = \033[0m  # No Color (reset)

# Targets
$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(YELLOW)Creating static library: $(NAME)$(NC)"
	@echo "$(GREEN)SRC files are compiled and library is ready.$(NC)"

all: $(NAME)

$(OBJS): %.o: %.c
	@echo "$(BLUE)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJBONUS)
	@$(AR) $(NAME) $(OBJBONUS)
	@echo "$(GREEN)Bonus files are compiled and library is ready.$(NC)"

$(OBJBONUS): %.o: %.c
	@echo "$(BLUE)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning up object files...$(NC)"
	@ rm -rf $(OBJS) $(OBJBONUS)

fclean: clean
	@echo "$(RED)Removing static library: $(NAME)$(NC)"
	@ rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus