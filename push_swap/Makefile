SRCS = func.c push_swap_utils.c push_swap.c algorithm.c \
		insertion_sort.c push_swap_utils2.c push_swap_utils3.c \
		push_swap_utils4.c func2.c func3.c
CHECK_SRCS = checker.c push_swap_utils.c func.c func2.c func3.c \
			checker2.c
HEADER = push_swap.h checker.h
LIBFT = ./libft/libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra

all: push_swap checker

bonus: push_swap checker

$(LIBFT):
	$(MAKE) -C ./libft

push_swap: $(LIBFT)
	$(CC) $(FLAGS) $(LIBFT) $(SRCS) -o push_swap

checker: $(LIBFT)
	$(CC) $(FLAGS) $(LIBFT) $(CHECK_SRCS) -o checker

clean:
	$(MAKE) clean -C ./libft

fclean:	clean
	rm -f push_swap checker
	$(MAKE) fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re bonus