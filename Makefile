.PHONY:		all re clean fclean tools

NAME		=	minishell

CC			=	gcc

CFLAGS		=	-I ./includes -I ./tools/dict/includes/ -I ./tools/libft/includes/ -I ./tools/list/includes/ -I ./tools/dlist/includes/ -I ./tools/line/includes/

FILES		=	src/main.c\
				src/ft_put_line.c\
				src/input/input.c src/reload_signature.c\
				src/launch_executable.c\
				src/env/env_utils.c\
				src/builtins/ft_cd.c\
				src/builtins/ft_export.c\
				src/builtins/ft_unset.c\
				src/redirections.c


OBJS		=	$(FILES:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) | tools
	${CC} ${CFLAGS} ${OBJS} -L ./tools/dict/ -L ./tools/libft/ -L ./tools/line/ -L ./tools/dlist/ -ldlist -lft -lline -ldict -o ${NAME}

tools:
	make -C ./tools/libft/
	make -C ./tools/line/
	make -C ./tools/dlist/
	make -C ./tools/dict/

clean:
	rm -rf ${OBJS}

fclean:		clean
	rm -rf ${NAME}

re:			fclean all