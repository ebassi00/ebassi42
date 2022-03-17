NAME = philo
SRCS = philo.c utils.c create_philo.c
OBJS = $(SRCS:.c=.o)
HEADER = philo.h
CC = gcc -pthread
FLAGS = -Wall -Werror -Wextra

all: philo

bonus: philo

philo:
	$(CC) $(FLAGS) $(SRCS) -o philo

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus