/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dripanuc <dripanuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:06:44 by ebassi            #+#    #+#             */
/*   Updated: 2022/05/06 17:06:56 by dripanuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_op(t_tok *input_ln, char *op)
{
	input_ln->type = 1;
	input_ln->data = op;
	input_ln->data = ft_strtrim(input_ln->data, " ");
	input_ln->exit = 0;
}

int	error(char *str)
{
	ft_putendl_fd(str, 1);
	return (0);
}

void	expand_envars(t_tok *input_ln)
{
	int		i;
	int		j;
	int 	quotes;
	char	*current_env;
	char	*new_data;

	i = 0;
	j = 0;
	current_env = 0;
	new_data = 0;
	while (input_ln)
	{
		i = 0;
		while (input_ln->data[i])
		{
			if (input_ln->data[i] == '$' && !count_quotes(input_ln->data, &quotes, i) % 2)
			{
				j = i;
				i++;
				while (input_ln->data[i] >= 63 && input_ln->data[i] <= 125)
					i++;
				current_env = ft_substr(input_ln->data, j + 1, i - j - 1);
				current_env = getenv(current_env);
				if (!current_env)
					current_env = ft_strdup("");
				new_data = ft_substr(input_ln->data, 0, j);
				new_data = ft_strjoin(new_data, current_env);
				new_data = ft_strjoin(new_data, &input_ln->data[i]);
				input_ln->data = new_data;
				if (!input_ln->data[i])
					return ;
			}
			if (input_ln->data[i] == '~' && !(count_quotes(input_ln->data, &quotes, i) % 2) && !(quotes % 2))
			{
				new_data = ft_substr(input_ln->data, 0, i);
				new_data = ft_strjoin(new_data, getenv("HOME"));
				new_data = ft_strjoin(new_data, &input_ln->data[i + 1]);
				input_ln->data = new_data;
			}
			i++;
		}
		input_ln = input_ln->next;
	}
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
		if (line[i] == '|' || line[i] == '>' || line[i] == '<' || \
			(line[i] == '&' && line[i + 1] == '&'))
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
	expand_envars(input_ln);
}

int	ft_find(char **builtin, char *str)
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
	int		i;
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
	if (path)
	{
		while (path[i])
			free(path[i++]);
		free(path);
	}
}

void	execute_command_from_system(char *str)
{
	char	**path;
	pid_t	pid;

	pid = fork();
	path = ft_split(getenv("PATH"), ':');
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

int	handle_separator(t_tok *input_ln)
{
	if (!(ft_strncmp(input_ln->data, "|", 1)))
		;
	else if (!(ft_strncmp(input_ln->data, "&&", 2)))
	{
		if (g_exit_status == 1)
			return (0);
	}
	else if (!(ft_strncmp(">>", input_ln->data, 2)))
		ft_echo(input_ln);
	else if (!(ft_strncmp("<<", input_ln->data, 2)))
		ft_echo(input_ln);
	else if (!(ft_strncmp(">", input_ln->data, 1)))
		ft_echo(input_ln);
	else if (!(ft_strncmp("<", input_ln->data, 1)))
		ft_echo(input_ln);
	// printf("%s\n", input_ln->data);
	return (1);
}

void first_pipe(t_mini *minishell)
{
	int			piped[2];

	if (pipe(piped) == -1)
		;

	minishell->saved_stdout = dup(STDOUT_FILENO);
	minishell->saved_stdin = dup(STDIN_FILENO);
	minishell->pipe = 1;
	minishell->output_fd = piped[1];
	minishell->input_fd = piped[0];
	close(STDOUT_FILENO);
	dup2(minishell->output_fd, STDOUT_FILENO);
	close(minishell->output_fd);
}

void middle_pipe(t_mini *minishell)
{
	int			piped[2];

	if (pipe(piped) == -1)
		;
	minishell->output_fd = piped[1];
	close(STDIN_FILENO);
	dup2(minishell->input_fd, STDIN_FILENO);
	close(minishell->input_fd);
	minishell->input_fd = piped[0];
	close(STDOUT_FILENO);
	dup2(minishell->output_fd, STDOUT_FILENO);
	close(minishell->output_fd);
}

void last_pipe(t_mini *minishell)
{
	dup2(minishell->input_fd, STDIN_FILENO);
	close(minishell->input_fd);
	dup2(minishell->saved_stdout, STDOUT_FILENO);
	close(minishell->saved_stdout);
}

void reset_fd(t_mini *minishell)
{
	minishell->pipe = 0;
	dup2(minishell->saved_stdin, STDIN_FILENO);
	close(minishell->saved_stdin);
	// dup2(minishell->saved_stdout, STDOUT_FILENO);
	// close(minishell->saved_stdout);
}

void	handle_cmd(t_mini *minishell, t_env **env, char *argv[], t_tok *input_ln)
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
		while (1 && !input_ln->type)
		{
			if (input_ln->data[i] == ' ' || !input_ln->data[i])
			{
				str = ft_substr(input_ln->data, 0, i);
				if (input_ln->next && !(ft_strncmp("|", input_ln->next->data, 1)) && !minishell->pipe)
					first_pipe(minishell);
				else if (minishell->pipe && input_ln->next && !ft_strncmp("|", input_ln->next->data, 1))
					middle_pipe(minishell);
				else if (minishell->pipe)
					last_pipe(minishell);
				if (ft_find(builtin, str))
				{
					if (!(ft_strncmp("pwd", str, 3)))
						get_pwd();
					else if (!(ft_strncmp("cd", str, 2)))
						change_dir(input_ln);
					else if (!(ft_strncmp("echo", str, 4)))
						ft_echo(input_ln);
					else if (!(ft_strncmp("env", str, 3)))
						get_env(*env);
					else if (!(ft_strncmp("exit", str, 4)))
						exit_command();
					else if (!(ft_strncmp("export", str, 6)))
						export_command(*env, input_ln);
					else if (!(ft_strncmp("unset", str, 5)))
						unset_var(env, input_ln);
				}
				else
					execute_command_from_system(input_ln->data);
				if (minishell->pipe && (!input_ln->next || ft_strncmp("|", input_ln->next->data, 1)))
					reset_fd(minishell);
				break ;
			}
			i++;
		}
		if (input_ln->type)
			if (handle_separator(input_ln) == 0)
				return ;
		input_ln = input_ln->next;
	}
}

int	count_quotes(char *line, int *quotes, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*(quotes) = 0;
	// printf("%s\n", line);
	while (line[i] && i < n)
	{
		if (line[i] == '\'')
			j++;
		else if (line[i] == '\"')
			(*quotes)++;
		i++;
	}
	return (j);
}

char	*check_readline(char *line)
{
	char	*tmp;
	int		quotes;

	tmp = 0;
	quotes = 0;
	while (count_quotes(line, &quotes, ft_strlen(line)) % 2 != 0)
	{
		tmp = readline("quote: ");
		quotes = 0;
		line = ft_strjoin(line, tmp);
	}
	while (quotes % 2 != 0)
	{
		tmp = readline("dquotes: ");
		line = ft_strjoin(line, tmp);
		quotes = 0;
		count_quotes(line, &quotes, ft_strlen(line));
	}
	return (line);
}

void	init_mini(int argc, char *argv[], char *envp[])
{
	t_tok	input_ln;
	t_mini	minishell;
	t_env	*env;
	char	*command;
	char	*line;
	char	*str;

	(void)argc;
	(void)argv;
	line = 0;
	command = 0;
	minishell.pipe = 0;
	minishell.saved_stdout = dup(STDOUT_FILENO);
	minishell.saved_stdin = dup(STDIN_FILENO);
	env = NULL;
	init_env(env);
	take_environ(&env, envp);
	/*----------------------DA DECOMMENTARE-----------------------*/
	signal(SIGINT, &signal_handler);
	// signal(SIGQUIT, &exit_command_signal);
	// signal(SIGTSTP, signal_handler);
	while (42)
	{
		init(&input_ln);
		str = set_prompt();
		line = readline(str);
		if (!line)
			return ;
		line = check_readline(line);
		if (ft_strlen(line) > 0)
		{
			minishell.pipe = 0;
			add_history(line);
			get_command(&input_ln, line);
			handle_cmd(&minishell, &env, argv, &input_ln);
		}
	}
	close(minishell.saved_stdout);
	close(minishell.saved_stdin);
}

int	main(int argc, char *argv[], char *envp[])
{
	g_exit_status = 0;
	init_mini(argc, argv, envp);
	return (0);
}
