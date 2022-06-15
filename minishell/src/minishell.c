/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:54:34 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/13 18:17:22 by mpatrini         ###   ########.fr       */
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

int	ft_find(char **builtin, char *str)
{
	int	i;

	i = 0;
	while (builtin[i])
	{
		if (!(ft_strncmp(str, builtin[i], ft_strlen(str))) && ft_strlen(str) == ft_strlen(builtin[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*find_exec(DIR *stream, char *str, char *dir_name)
{
	char			*full_path;
	char			*cmd;
	struct dirent	*dp;

	full_path = NULL;
	cmd = ft_substr(str, 0, ft_strchr_int(str, ' '));
	if (!stream)
		return (NULL);
	dp = readdir(stream);
	while (dp)
	{
		if (!ft_strncmp(cmd, dp->d_name, ft_strlen(cmd)) \
			&& !ft_strncmp(dp->d_name, cmd, ft_strlen(dp->d_name)) \
			&& (str[ft_strlen(cmd)] == ' ' || str[ft_strlen(cmd)] == 0))
		{
			full_path = ft_strjoin(dir_name, "/");
			full_path = ft_strjoin_free(full_path, ft_strdup(dp->d_name));
			return (full_path);
		}
		dp = readdir(stream);
	}
	g_exit_status = 1;
	free(cmd);
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
