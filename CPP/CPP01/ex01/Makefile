NAME = zombie
SRCS = main.cpp Zombie.cpp ZombieHorde.cpp
HEADERS = Zombie.hpp
COMPILE = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

zombie:
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus