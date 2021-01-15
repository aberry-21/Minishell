.PHONY:		all re clean fclean tools

NAME		=	minishell

CC			=	gcc

CFLAGS		=	-I ./includes -I ./tools/libft/includes/ -I ./tools/list/includes/ -I ./tools/dlist/includes/

FILES		=	src/ft_put_line.c src/main.c\
				src/input.c src/reload_signature.c

OBJS		=	$(FILES:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) | tools
	${CC} ${CFLAGS} ${OBJS} -L ./tools/libft/ -lft -o ${NAME}

tools:
	make -C ./tools/libft/

clean:
	rm -rf ${OBJS}

fclean:		clean
	rm -rf ${NAME}

re:			fclean all