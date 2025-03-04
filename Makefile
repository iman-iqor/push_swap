CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
SRC = main.c helpers1.c helpers2.c helpers3.c helpers4.c operations_push.c operations_rotate.c operations_swap.c operations_reverse.c helpers5.c sort_five.c algo1.c algo2.c algo3.c

NAME  = push_swap
RM = rm -f

all: ${NAME} 

${NAME}: ${SRC}
	make -C ./libft/
	${CC} ${CFLAGS} ${SRC} ./libft/libft.a -o ${NAME}


clean:
	make -C ./libft/ clean

fclean: clean
	${RM} $(NAME)
	make -C ./libft/ fclean

re: fclean all