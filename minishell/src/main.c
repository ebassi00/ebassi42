/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:06:44 by ebassi            #+#    #+#             */
/*   Updated: 2022/04/26 18:26:59 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void handle_op(t_tok *input_ln, char *op)
{
	input_ln->type = 1;
	input_ln->data = op;
	input_ln->data = ft_strtrim(input_ln->data, " ");
	input_ln->exit = 0;
}

int error(char *str)
{
	ft_putendl_fd(str, 1);
	return (0);
}

void	get_command(t_tok *input_ln, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	input_ln->id = 0;
	while (line[i])
	{
		if (line[i] == '|' || line[i] == '>' || line[i] == '<' || (line[i] == '&' && line[i + 1] == '&'))
		{
			if (i != 0)
			{
				get_next_lst(input_ln);
				input_ln = input_ln->next;
			}
			if (line[i] == line[i + 1])
			{
				handle_op(input_ln, ft_substr(line, i, 2));
				get_next_lst(input_ln);
				input_ln = input_ln->next;
				j = i + 2;
				i++;
			}
			else
			{
				handle_op(input_ln, ft_substr(line, i, 1));
				get_next_lst(input_ln);
				input_ln = input_ln->next;
				j = i + 1;
			}
		}
		input_ln->type = 0;
		input_ln->data = ft_substr(line, j, i - j + 1);
		input_ln->data = ft_strtrim(input_ln->data, " ");
		input_ln->exit = 0;
		i++;
	}
	input_ln->next = 0;
}

int		ft_find(char **builtin, char *str)
{
	int	i;

	i = 0;
	while (builtin[i])
	{
		if (!(ft_strncmp(str, builtin[i], ft_strlen(str))))
			return (1);
		i++;
	}
	return (0);
}

char	*find_exec(DIR *stream, char *str, char *dir_name)
{
	char			*full_path;
	struct dirent	*dp;

	full_path = 0;
	dp = readdir(stream);
	while (dp)
	{
		if (!ft_strncmp(dp->d_name, str, ft_strlen(dp->d_name)))
		{
			full_path = ft_strjoin(dir_name, "/");
			full_path = ft_strjoin(full_path, dp->d_name);
			return (full_path);
		}
		dp = readdir(stream);
	}
	return (0);
}

// void	my_handler(int signo)
// {
// 	if (signo == SIGINT)
// 	{
// 		ft_putchar_fd('\n', 1);
// 		signal(SIGINT, my_handler);
// 	}
// }

char	*last_field(char *env)
{
	int	i;
	int	j;

	i = ft_strlen(env) - 1;
	j = i;
	while (env[j])
	{
		if (env[j] == '/')
			return (ft_substr(env, j + 1, i - j));
		j--;
	}
	return (env);
}

void	my_exec(char **path, char *str)
{
	int 	i;
	char	*is_exec;
	char	**flags;
	DIR		*stream;

	i = 0;
	stream = NULL;
	while (path[i])
	{
		stream = opendir(path[i]);
		is_exec = find_exec(stream, str, path[i]);
		if (is_exec)
		{
			flags = ft_split(str, ' ');
			execve(is_exec, flags, NULL);
			closedir(stream);
			i = 0;
			while (path[i])
				free(path[i++]);
			free(path);
			return ;
		}
		closedir(stream);
		i++;
	}
	if (!is_exec)
	{
		ft_putstr_fd(last_field(getenv("SHELL")), 1);
		ft_putstr_fd(": command not found: ", 1);
		ft_putendl_fd(str, 1);
	}
	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
}

void	execute_command_from_system(char *str)
{
	char	**path;
	pid_t	pid;

	pid = fork();
	path = ft_split(getenv("PATH"), ':');
	// signal(SIGINT, my_handler);
	if (pid == 0)
		my_exec(path, str);
	else if (pid < 0)
	{
		free(path);
		ft_putendl_fd("Fork failed to create a new process.", 1);
		return ;
	}
	wait(&pid);
}

void	handle_cmd(t_tok *input_ln, t_env *env, char *argv[])
{
	int		i;
	char	*str;
	char	**builtin;

	(void)argv;
	i = 0;
	str = 0;
	builtin = ft_split("cd echo env exit export pwd unset", ' ');
	while (input_ln)
	{
		i = 0;
		while (1)
		{
			if (input_ln->data[i] == ' ' || !input_ln->data[i])
			{
				str = ft_substr(input_ln->data, 0, i);
				if (ft_find(builtin, str))
				{
					if (!(ft_strncmp(str, "pwd", 3)))
						get_pwd();
					else if (!(ft_strncmp(str, "cd", 2)))
						change_dir(input_ln);
					else if (!(ft_strncmp(str, "echo", 4)))
						ft_echo(input_ln);
					else if (!(ft_strncmp(str, "env", 3)))
						get_env(env);
					else if (!(ft_strncmp(str, "exit", 4)))
						exit_command();
					else if (!(ft_strncmp(str, "export", 6)))
						export_command(env, input_ln);
					else if (!(ft_strncmp(str, "unset", 5)))
						get_pwd();
				}
				else
					execute_command_from_system(input_ln->data);
				break ;
			}
			i++;
		}
		input_ln = input_ln->next;
	}
}

void	init_mini(int argc, char *argv[], char *envp[])
{
	t_tok	input_ln;
	t_env	env;
	char	*command;
	char	*line;
	char	*str;

	(void)argc;
	(void)argv;
	line = 0;
	command = 0;
	init_env(&env);
	take_environ(&env, envp);
	/*----------------------DA DECOMMENTARE-----------------------*/
	// signal(SIGINT, signal_handler);
	// signal(SIGQUIT, signal_handler);
	// signal(SIGTSTP, signal_handler);
	while (42)
	{
		init(&input_ln);
		str = set_prompt();
		line = readline(str);
		if (ft_strlen(line) > 0)
		{
			add_history(line);
			get_command(&input_ln, line);
			// print_list(&input_ln);
			handle_cmd(&input_ln, &env, argv);
		}
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	init_mini(argc, argv, envp);
	return (0);
}
