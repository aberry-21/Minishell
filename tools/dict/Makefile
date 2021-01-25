.PHONY:			all clean fclean re

NAME		=	libdict.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I ./includes -I ../libft/includes

NAME_FILES	=	ft_dict_add.c ft_dict_elem_add_back.c\
				ft_dict_get_elem_by_key.c ft_dict_rem.c ft_dict_clean.c\
				ft_dict_elem_init.c ft_dict_get_keys.c ft_dict_del.c\
				ft_dict_elem_last.c ft_dict_hash_function.c ft_dict_double.c\
				ft_dict_get.c ft_dict_init.c

FILES		=	$(addprefix ./src/, $(NAME_FILES))

OBJS		=	$(FILES:.c=.o)

all:		${NAME}

${NAME}:	$(OBJS)
	ar rcs ${NAME} ${OBJS}

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}

re:	fclean all