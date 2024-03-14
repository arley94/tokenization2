# NAMES
NAME = test

# COMPILER OPTIONS
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -g3

# LIBS
LIBS_PATH = libs/

# LIBFT
LIBFT_PATH 	= $(LIBS_PATH)libft/
LIBFT_NAME 	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# INCLUDES
INCLUDE = -I ./include/

# SOURCE FILES
SRC_DIRS := $(wildcard src/*/)
SRC := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)*.c))

# OBJECT FILES
OBJ_PATH	= obj/
OBJ_FILES	:= $(patsubst src/%.c,%.o,$(SRC))
OBJ 		:= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

# COMMANDS
RM		= rm -f

# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
BLUE	=	\033[94;1m
PINK	=	\033[95;1m
CLEAR	=	\033[0m

# MAKEFILE RULES
all:	$(NAME)

$(NAME): $(LIBFT) $(OBJ_PATH) $(OBJ)
	@echo "$(PINK)Compiling $(NAME).$(CLEAR)"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(INCLUDE) $(LIBFT)
	@echo "$(GREEN)[OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)"

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

$(OBJ_PATH)%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c -o $@ $< $(INCLUDE)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	echo "$(PINK)Removing .o object files.$(CLEAR)"
	rm -rf $(OBJ_PATH)
	make clean -sC $(LIBFT_PATH)
	echo "$(GREEN)Object files removed correctly\n$(CLEAR)"

fclean: clean
	@make fclean -sC $(LIBFT_PATH)
	@$(RM) $(NAME)
	@echo "$(GREEN)Exec. files removed correctly\nSuccess!$(CLEAR)"

re: fclean all

.PHONY:		all clean fclean re