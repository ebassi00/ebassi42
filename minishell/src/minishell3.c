/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:54:34 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/13 14:55:51 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_is_exec(char **path, char *str, char ***flags, char **env)
{
	int		i;
	char	*is_exec;
	DIR		*stream;

	i = -1;
	stream = NULL;
	while (path[++i])
	{
		stream = opendir(path[i]);
		is_exec = find_exec(stream, str, path[i]);
		if (stream != NULL)
			closedir(stream);
		if (!access(str, R_OK))
			is_exec = str;
		if (is_exec)
		{
			*flags = ft_split(str, ' ');
			return (is_exec);
		}
	}
	if (!is_exec)
		my_exec2(str, env);
	return (NULL);
}

char	*extract_command(char *str)
{
	char	**splitted_cmd;
	int		i;
	int		j;

	i = -1;
	splitted_cmd = ft_split(str, ' ');
	str = ft_strdup("");
	while (splitted_cmd[++i])
	{
		j = -1;
		while (splitted_cmd[i][++j])
		{
			if (splitted_cmd[i][j] == 34 || splitted_cmd[i][j] == 39)
			{
				if (ft_strchr(&splitted_cmd[i][j+1], 34) && splitted_cmd[i][j+1])
					splitted_cmd[i] = trim_all(splitted_cmd[i], 34);
				else if (ft_strchr(&splitted_cmd[i][j+1], 39) && splitted_cmd[i][j+1])
					splitted_cmd[i] = trim_all(splitted_cmd[i], 39);
			}
		}
	}
	str = ft_strjoin_get(str, splitted_cmd[0]);
	i = 0;
	while (splitted_cmd[++i])
	{
		str = ft_strjoin_free(str, ft_strdup(" "));
		str = ft_strjoin_get(str, splitted_cmd[i]);
	}
	ft_free_matrix(splitted_cmd);
	return (str);
}

void	execute_command_from_system(char *str, int i, char **env)
{
	char	**path;
	char	**flags;
	pid_t	pid;
	char	*is_exec;
	
	path = ft_split(ft_get_env(env, "PATH"), ':');
	flags = NULL;
	str = extract_command(str);
	is_exec = ft_is_exec(path, str, &flags, env);
	if (!is_exec)
		return ;
	pid = fork();
	if (pid == 0)
		my_exec(path, is_exec, flags, env);
	// else if (pid < 0)
	// {
	// 	free(path);
	// 	ft_putendl_fd("Fork failed to create a new process.", 2);
	// 	return ;
	// }
	else
		waitpid(pid, &g_exit_status, 0);
	if (i)
		(void)i;
		// waitpid(pid, NULL,0);
	// wait(&pid);
	ft_free_matrix(flags);
}

int	count_quotes(char *line, char ext, char inte)
{
	int	open;
	// int	n;
	// int	i;

	open = 0;
	(void)inte;
	// i = 0;
	// n = ft_strlen(line);
	line--;
	while (*++line)
	{
		if (*line == ext && !open)
			open = 1;
		else if (*line == ext)
			open = 0;
	}
	return (open);
}

int	quote_in_quotes(char *line)
{
	int	i;
	// int	j;
	int	open_m;
	int	open_s;

	i = -1;
	open_s = 0;
	open_m = 0;
	// j = -1;
	while (line[++i])
	{
		if (line[i] == '"' && !open_s && !open_m)
			open_m = 1;
		else if (line[i] == '"' && open_m)
			open_m = 0;
		else if (line[i] == '\'' && !open_s && !open_m)
			open_s = 1;
		else if (line[i] == '\'' && open_s)
			open_s = 0;
	}
	if (!open_s && !open_m)
		return (0);
	else if (open_s && !open_m)
		return (1);
	else if (!open_s && open_m)
		return (2);
	return (0);
}

char	*check_readline(char *line)
{
	char	*tmp;
	// int		quotes;
	int		flag;

	tmp = 0;
	// quotes = 0;
	flag = quote_in_quotes(line);
	while (flag)
	{
		if (flag == 1)
			tmp = readline("quote: ");
		else
			tmp = readline("dquote: ");
		line = ft_strjoin_free(line, tmp);
		flag =  quote_in_quotes(line);
	}
	return (line);
}

char	*get_path(char *data)
{
	if (data[0] == 'c' && data[1] == 'd' && data[2] == ' ' && data[3])
		return (&data[3]);
	return (0);
}
