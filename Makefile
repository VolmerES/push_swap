NAME = push_swap
CC = gcc
SRC =	./src/checker.c \
		./src/list_utils.c \
		./src/push_swap.c \
		./src/push.c \
		./src/reverse_rotate.c \
		./src/rotate.c \
		./src/stack.c \
		./src/swap.c \
		./src/tiny_stack.c


OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
FT_LIB = ./libft/libft.a

all : $(NAME)
	@echo "\x1b[32m Compilacion PUSH SWAP: OK"

$(NAME) : $(OBJS) $(FT_LIB)
	@$(CC) -Llibft -lft $(OBJS) -o $(NAME)


$(FT_LIB) : 
	@make -C ./libft/

%.o : %.c
	@$(CC) -c $(CFLAGS) $? -o $@

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft/

re: fclean all

.PHONY : clean fclean
