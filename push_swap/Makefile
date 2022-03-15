SRCSFLS = func.c push_swap_utils.c push_swap.c algorithm.c \
		insertion_sort.c push_swap_utils2.c push_swap_utils3.c \
		push_swap_utils4.c func2.c func3.c algorithm_utils.c \
		algorithm_utils2.c
CHECK_SRCSFLS = checker.c checker2.c checker_utils.c
CHECK_SRCSFLS2 = push_swap_utils.c func.c func2.c func3.c
SRCS = $(addprefix src/, $(SRCSFLS))
SRCS_BONUS = $(addprefix src_bonus/, $(CHECK_SRCSFLS))
SRCS_BONUS2 = $(addprefix src/, $(CHECK_SRCSFLS2))
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
	$(CC) $(FLAGS) $(LIBFT) $(SRCS_BONUS) $(SRCS_BONUS2) -o checker

clean:
	$(MAKE) clean -C ./libft

fclean:	clean
	rm -f push_swap checker
	$(MAKE) fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re bonus