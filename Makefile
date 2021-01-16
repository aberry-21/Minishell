.PHONY:		all re clean fclean tools

NAME		=	minishell

CC			=	gcc

CFLAGS		=	-I ./includes -I ./tools/libft/includes/ -I ./tools/list/includes/ -I ./tools/dlist/includes/ -I ./tools/line/includes/

FILES		=	src/ft_put_line.c src/main.c\
				src/input/input.c src/reload_signature.c\
				src/launch_executable.c

OBJS		=	$(FILES:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) | tools
	${CC} ${CFLAGS} ${OBJS} -L ./tools/libft/ -L ./tools/line/ -L ./tools/dlist/ -ldlist -lft -lline -o ${NAME}

tools:
	make -C ./tools/libft/
	make -C ./tools/line/
	make -C ./tools/dlist/

clean:
	rm -rf ${OBJS}

fclean:		clean
	rm -rf ${NAME}

re:			fclean all