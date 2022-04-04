NAME = fixed
SRCS = main.cpp Fixed.cpp
HEADERS = Fixed.hpp
COMPILE = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

fixed:
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus