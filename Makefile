NAME = push_swap
CC = gcc
SRC =	checker.c \
		list_utils.c \
		push_swap.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		stack.c \
		swap.c \
		tiny_stack.c


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
	@$(CC) -c $(CFLAGS) $?

clean:
	@rm -f *.o
	@make clean -C ./libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft/

re: fclean all

.PHONY : clean fclean
