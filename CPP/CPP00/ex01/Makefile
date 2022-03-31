NAME = phonebook
SRCS = Contacts.cpp main.cpp PhoneBook.cpp
HEADERS = Contacts.hpp PhoneBook.hpp
COMPILE = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

phonebook:
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus