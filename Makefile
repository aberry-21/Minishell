.PHONY:		all re clean fclean tools

NAME		=	minishell

CC			=	gcc

LIBS		=	$(addprefix ./tools/, libft list dlist line dict list)

INC			=	$(addprefix -I, $(addsuffix /includes/, . $(LIBS)))

# -Wall -Wextra -Werror
CFLAGS		=	-O3 -MMD $(INC) $(ADD_FLAGS)

FILES		=	$(addprefix src/,\
					main.c launch_executable.c\
					$(addprefix env/,\
						env_to_string.c from_pp_chr.c print_for_export.c env_utils.c print.c get.c\
					)\
					$(addprefix wildcard/,\
						ft_parse_wildcard_recursion_set_path_and_pattern.c wildcard.c ft_wildcard_find_str.c\
						ft_parse_wildcard_recursion.c ft_wildcard_set_pattern_array.c wildcard_utils.c\
					)\
					$(addprefix prompt/,\
						prompt.c prompt_utils.c\
					)\
					$(addprefix input/,\
						input.c mode.c normal.c insert.c\
						$(addprefix graphical/,\
							$(addprefix cmd_line/,\
								line_get.c new.c delone.c\
							)\
							$(addprefix command/,\
								get.c new.c reload_len_prefix.c render.c com2com_copy.c\
							)\
							$(addprefix output_line/,\
								new.c delete.c\
							)\
							$(addprefix signature/,\
								render.c\
							)\
							$(addprefix window/,\
								clean.c render.c\
							)\
						)\
						$(addprefix keys/,\
							any_key.c command_end.c control_d.c cursor_right.c key_enter.c line_home.c\
							classic_enter.c command_home.c cursor_down.c cursor_up.c key_enter_line.c\
							skip_word_left.c command_down.c command_up.c cursor_left.c key_delete.c\
							line_end.c skip_word_right.c mode_to_normal.c mode_to_insert.c\
							new_line_down.c new_line_up.c cursor_left_to_insert.c cursor_right_to_insert.c\
							cursor_up_to_insert.c cursor_down_to_insert.c line_add_clipboard.c\
							clipboard_paste_down.c clipboard_clear.c line_to_clipboard.c line_delete.c\
						)\
						$(addprefix utils/,\
							ft_cursor_sync.c get_length_number.c\
						)\
					)\
					$(addprefix parse/,\
						run.c error.c\
						$(addprefix build_tree/,\
							command.c build.c redirection.c tokenize.c group.c\
							pipe.c sequence.c variable.c double_quotes.c quotes.c\
						)\
						$(addprefix classes/,\
							$(addprefix element/,\
								checker.c create.c destructor.c run.c to_immutable.c\
							)\
							$(addprefix sequence/,\
								checker.c create.c destructor.c run.c\
							)\
							$(addprefix pipe/,\
								checker.c create.c destructor.c run.c\
							)\
							$(addprefix and/,\
								checker.c create.c destructor.c run.c\
							)\
							$(addprefix or/,\
								checker.c create.c destructor.c run.c\
							)\
							$(addprefix group/,\
								checker.c create.c destructor.c run.c\
							)\
							$(addprefix string/,\
								checker.c create.c destructor.c run.c\
							)\
							$(addprefix immutable/,\
								checker.c create.c destructor.c run.c\
							)\
							$(addprefix variable/,\
								checker.c create.c destructor.c run.c\
							)\
							$(addprefix separator/,\
								checker.c create.c destructor.c run.c\
							)\
							$(addprefix redirection/,\
								checker.c create.c destructor.c run.c\
							)\
							$(addprefix command/,\
								checker.c create.c destructor.c run.c\
							)\
						)\
					)\
				)

OBJS		=	$(FILES:.c=.o)
DEPENDS		=	$(OBJS:.o=.d)

all:		$(NAME)

debug:		CFLAGS	+= -fsanitize=address -g
debug:		all;

$(NAME):	$(OBJS) | tools
	${CC} ${CFLAGS} ${OBJS} $(addprefix -L, $(LIBS)) -ldlist -lft -lline -ldict -llist -o ${NAME}

define		ft_tools
	for library in $(LIBS) ; do \
		make $(1) -C $$library ;\
	done
endef

tools:
	$(call ft_tools, )

clean:
	$(call ft_tools, clean)
	rm -rf ${OBJS} ${DEPENDS}

fclean:		clean
	rm -rf ${NAME}
	$(call ft_tools, fclean)

re:			fclean all

-include ${DEPENDS}
