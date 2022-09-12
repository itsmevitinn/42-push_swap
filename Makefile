NAME = push_swap

FLAGS = -Wall -Wextra -Werror

GCC = gcc

MAKE_IN_DIRECTORY = make -C

LIBFT_PATH = ./libft

MAKE_LIBFT = $(MAKE_IN_DIRECTORY) $(LIBFT_PATH)

LIBFT = ./libft/libft.a

SRC_DIR = ./src/

SRCS = free.c algorithms.c commands.c errors.c push_swap.c utils.c utils2.c

FUNCS = $(addprefix $(SRC_DIR), $(SRCS))

RM = rm -f
	
all:		$(NAME)

$(NAME):	$(LIBFT)
			@$(GCC) -g $(FUNCS) $(LIBFT) -o $(NAME)
			@echo "\033[32m 💯 | Push_swap created."

$(LIBFT):
			@$(MAKE_LIBFT)
clean: 
			$(MAKE_IN_DIRECTORY) $(LIBFT_PATH) clean 

fclean: 	
			@$(MAKE_IN_DIRECTORY) $(LIBFT_PATH) fclean 
			@$(RM) $(NAME)
			@echo "\033[33m 🌪️  | Push_swap all cleaned."

re:			fclean all

.PHONY:		all clean fclean re
