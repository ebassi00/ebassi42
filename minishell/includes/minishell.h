/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:07:29 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/13 19:54:21 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>
# include <termios.h>
# include <dirent.h>
# include <term.h>
# include <curses.h>
# include <termcap.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/wait.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define GREEN "\1\e[1;32m\2"
# define RESET "\1\e[0m\2"
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

typedef struct s_mini {
	int		pipe;
	int		output_fd;
	int		input_fd;
	int		saved_stdout;
	int		saved_stdin;
	char	*tmpdirections;
	int		redir;
	int		redir_open;
	int		redir_exec;
	char	**env;
}	t_mini;

int	g_exit_status;

void	signal_handler(int sig);
void	get_command(t_tok *input_ln, char *line, char **env);
char	*ft_get_env(char **env, char *str);
void	get_pwd(void);
char	*set_prompt(char **env);
void	get_next_lst(t_tok *input_ln);
void	init(t_tok *x);
void	print_list(t_tok *x);
void	change_dir(t_tok *input_ln, t_mini *mini);
void	exit_command(t_mini *mini, t_tok *i_ln);
void	ft_echo(t_tok *input_ln, char **env);
void	get_env(char **env);
char	*trim_all(char *str, char op);
char	**export_command(char **env, t_tok *str);
char	**unset_var(char **env, t_tok *input);
void	exit_command_signal(int sig);
void	handle_op(t_tok *input_ln, char *op);
int		error(char *str);
void	expand_envars(t_tok *input_ln, char **env);
int		ft_find(char **builtin, char *str);
char	*find_exec(DIR *stream, char *str, char *dir_name);
char	*last_field(char *env);
void	execute_command_from_system(char *str, int i, char **env);
void	middle_pipe(t_mini *minishell);
void	last_pipe(t_mini *minishell);
void	reset_fd(t_mini *minishell);
int		count_quotes(char *line, char ext, char inte);
char	*check_readline(char *line);
void	handle_cmd(t_mini *mini, t_tok *i_ln);
int		handle_separator(t_tok *input_ln);
void	redir(t_mini *minishell, t_tok *input_ln, int flag, int type);
void	init_mini(char *envp[]);
void	first_pipe(t_mini *minishell);
void	middle_pipe(t_mini *minishell);
void	last_pipe(t_mini *minishell);
void	reset_fd(t_mini *minishell);
int		ft_strlen_matrix_wild(char **matrix);
char	*get_path(char *data);
char	*ft_is_exec(char **path, char *str, char ***flags, char **env);
void	my_exec(char **path, char *is_exec, char **flags, char **env);
void	my_exec2(char *str, char **env);
void	ft_wildcard(char *str, int i, char **env);
char	**ft_find_files(char *dir, int i);
int		ft_folder_size(char *dir);
int		ft_strcmp_end(char *name, char *end);
void	ft_free_matrix_wild(char **matrix);
void	ft_exec_wild(char *is_exec, char **path, char **files, char **env);
char	**ft_find_files3(char *dir, char *srch, int i);
char	**ft_findwild_multi3(char *str, char *dir);
char	**ft_find_multi(char **files, char *find, char *last);
char	**ft_check_last(char **files, char *str, int i);
void	ft_findwild_multi(char *str, char *dir, char **path, char **env);
char	**ft_findwild_multi2(char *str, char *dir);
void	rl_replace_line(const char *text, int clear_undo); //fix rl_replace
char	**ft_init_env(char **env, int k);
int		qquotes(char c, int q);
char	**ft_echo_wild2_help(char **files, char *str, char *find, char **last);
void	ft_echo_wild_h(char **files, int flag_h);
char	**ft_echo_wild2(char *str, char *dir);
void	ft_echo2(char **echo, char **env);
void	ft_echo_env(char *echo, int *flag34, int *flag39, char **env);
void	ft_echo_wild(char *str);
void	ft_echo_helper(char echo, int *flag34, int *flag39);
void	ft_echo(t_tok *input_ln, char **env);
int		ft_echo_env2(char *echo, int i, char **env);
char	**ft_check_last_echo(char **files, char *str, int i, int j);
char	**ft_find_multi_echo(char **files, char *find, char *last);
char	**ft_echo_wild3(char *str, char *dir);
void	ft_echo_flag(int *i);
int		find_flag(char *data);
int		prev_echo(char *data, int i);

#endif