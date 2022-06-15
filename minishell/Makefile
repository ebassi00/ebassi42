# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/12 16:02:33 by mpatrini          #+#    #+#              #
#    Updated: 2022/06/13 19:09:44 by mpatrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

LIBFT	=	./libft/libft.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g -I includes/ -I libft/#-fsanitize=address -fno-omit-frame-pointer

READLINE	= -L/usr/include -lreadline -I$(HOME)/.brew/opt/readline/include #-L$(HOME)/.brew/opt/readline/lib

RM		=	rm -f

SRCSFLS = main.c \
			utils.c \
			utils2.c \
			init_environ.c \
			minishell.c \
			minishell2.c \
			minishell3.c \
			minishell4.c \
			minishell5.c \
			minishell6.c \
			minishell7.c \
			pipe.c \
			wildcard.c \
			wildcard2.c \
			wildcard3.c \
			
BUILTINS = cd.c \
			echo.c \
			echo2.c \
			echo3.c \
			echo4.c \
			pwd.c \
			env.c \
			exit.c \
			export.c \
			unset.c \

SRCS = $(addprefix src/, $(SRCSFLS)) $(addprefix builtins/, $(BUILTINS))

OBJ		=	$(SRCS:.c=.o)

$(NAME):	$(OBJ)
			@make -C libft/
			@printf "\e[92mBuilding $(NAME)...\e[39m\n"
			@$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJ) $(READLINE)
			@printf "\e[102mEverything has been compiled, use './minishell' to run the program!\e[0m\n"

%.o	:	%.c
			@$(CC) $(CFLAGS) -c $< -o $@
				
all		:	$(NAME)

clean	:
			@printf "\e[93mCleaning Minishell objects...\e[39m\n"
			@$(RM) $(OBJ) $(OBJ2)
			@printf "\e[93mCleaning Libft objects...\e[39m\n"
			@make clean -C ./libft
			@printf "\e[103mAll objects have been deleted\e[0m\n"

fclean	:	clean
			@printf "\e[91mCleaning Minishell...\e[39m\n"
			@$(RM) $(NAME)
			@printf "\e[91mCleaning Libft...\e[39m\n"
			@make fclean -C ./libft
			@printf "\e[101mAll executables and libraries have been deleted\e[0m\n"

re		:	fclean all

.PHONY	:	all clean fclean re
