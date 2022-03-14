SRCS = func.c push_swap_utils.c push_swap.c algorithm2.c \
		insertion_sort.c push_swap_utils2.c
HEADER = push_swap.h
LIBFT = ./libft/libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra

all: push_swap

bonus: push_swap

$(LIBFT):
	$(MAKE) -C ./libft

push_swap: $(LIBFT)
	$(CC) $(FLAGS) $(LIBFT) $(SRCS) -o push_swap

clean:
	$(MAKE) clean -C ./libft

fclean:	clean
	rm -f push_swap
	$(MAKE) fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re bonus