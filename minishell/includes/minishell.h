/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:07:29 by ebassi            #+#    #+#             */
/*   Updated: 2022/04/26 18:19:19 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <errno.h>
# include <termios.h>
# include <dirent.h>
# include <term.h>
# include <curses.h>
# include <termcap.h>
# include <sys/ioctl.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define GREEN "\e[1;32m"
# define RESET "\e[0m"
# define RED "\e[1;91m"
# define CYAN "\e[1;36m"
# define YELLOW "\e[1;33m"
# define PURPLE "\e[1;35m"
# define BLUE "\e[1;34m"

typedef enum s_redirect {
	RE_GREAT = 1,
	RE_DOUBLE_GREAT = 2,
	RE_LESS = 3,
	PIPE = 4
}	t_redirect;

typedef struct s_tok {
	int				type;
	char			*data;
	int				id;
	int				exit;
	struct s_tok	*next;
}	t_tok;

typedef struct s_env {
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

void	signal_handler(int sig);
void	get_pwd();
char	*set_prompt();
void	get_next_lst(t_tok *input_ln);
void	init(t_tok *x);
void	init_env(t_env *env);
void 	print_list(t_tok *x);
void	change_dir(t_tok *input_ln);
void	exit_command();
void	ft_echo(t_tok *input_ln);
void	get_env(t_env *env);
void	take_elem_env(t_env *env, int i, char *envp[]);
void	take_environ(t_env *env, char *envp[]);
int		is_valid_env(const char *env);
char	*trim_all(char *str, char op);
void	export_command(t_env *env, t_tok *str);

#endif