NAME = zombie
SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
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