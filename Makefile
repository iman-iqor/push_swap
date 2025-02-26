CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb -fsanitize=address -g3
SRC = main.c helpers1.c helpers2.c helpers3.c
# BSRC = ./bonus_src/heredoc.c ./bonus_src/pipex_bonus.c ./bonus_src/get_next_line_project/get_next_line_bonus.c ./bonus_src/get_next_line_project/get_next_line_utils_bonus.c ./bonus_src/pipex_bonus_utils1.c ./bonus_src/pipex_bonus_utils2.c ./bonus_src/pipex_bonus_utils3.c ./bonus_src/here_doc_utils1.c ./bonus_src/here_doc_utils2.c
NAME  = push_swap
RM = rm -f

all: ${NAME} 

${NAME}: ${SRC}
	make -C ./libft/
	${CC} ${CFLAGS} ${SRC} ./libft/libft.a -o ${NAME}
# bonus:
# 	make -C ./ft_printf/
# 	make -C ./ft_fprintf/
# 	make -C ./libft/
# 	${CC} ${CFLAGS} ${BSRC} ./libft/libft.a ./ft_printf/libftprintf.a ./ft_fprintf/libftfprintf.a -o $(NAME)

clean:
	make -C ./libft/ clean

fclean: clean
	${RM} $(NAME)
	make -C ./libft/ fclean

re: fclean all