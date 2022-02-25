NAME = so_long
LIBFT = ./libft/libft.a
SRCSFLS = check_validity.c command_handle.c fill_matrix.c \
		img_to_win.c move_down_func.c move_left_func.c \
		move_right_func.c move_up_func.c move.c \
		parse_map.c so_long.c free_all.c
SRCS = $(addprefix src/, $(SRCSFLS))
OBJS = $(SRCS:.c=.o)
HDRS = so_long.h
FLAGS = -Wall -Werror -Wextra
COMPILER = -l mlx -framework openGL -framework AppKit

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(LIBFT)
	gcc $(FLAGS) $(SRCS) $(LIBFT) $(COMPILER) -o $(NAME)

bonus: all

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean:	clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re bonus