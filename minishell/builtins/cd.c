/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:57:13 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/13 18:40:41 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	change_dir2(t_tok *input_ln)
{
	ft_putstr_fd("cd: no such file or directory: ", STDERR);
	ft_putendl_fd(get_path(input_ln->data), STDERR);
}

void	ft_update_env(char **env)
{
	char	*pwd;
	char	*tmp;
	int		i;

	i = 0;
	pwd = ft_get_env(env, "PWD");
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
		{
			tmp = env[i];
			env[i] = ft_strjoin("PWD=", getcwd(NULL, 0));
			free(tmp);
		}
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
		{
			tmp = env[i];
			env[i] = ft_strjoin("OLDPWD=", pwd);
			free(tmp);
		}
		i++;
	}
}

char	*change_dir3(t_tok *input_ln, char **env, char *home_path)
{
	char	*str;
	char	*pwd;

	str = ft_strtrim(get_path(input_ln->data), " ");
	if (!str)
		return (NULL);
	pwd = getcwd(NULL, 0);
	if (str[0] == '~')
		str = ft_strjoin(ft_strdup(home_path), \
		ft_substr(str, 1, ft_strlen(str)));
	else if (str[0] == '-')
		str = ft_strdup(ft_get_env(env, "OLDPWD"));
	else if (str[0] == '/')
		;
	else
	{
		str = ft_strjoin_free(ft_strdup("/"), str);
		str = ft_strjoin_free(ft_strdup(pwd), str);
	}
	(void)env;
	free(pwd);
	return (str);
}

void	change_dir(t_tok *input_ln, t_mini *mini)
{
	char	*str;

	str = ft_strdup("");
	if (!ft_strncmp("cd", input_ln->data, ft_strlen(input_ln->data)))
	{
		chdir(ft_get_env(mini->env, "HOME"));
		ft_update_env(mini->env);
	}
	else
	{
		str = change_dir3(input_ln, mini->env, ft_get_env(mini->env, "HOME"));
		if (!str)
			chdir(ft_get_env(mini->env, "HOME"));
		else if (chdir(str))
		{
			g_exit_status = 1;
			change_dir2(input_ln);
		}
		else
			ft_update_env(mini->env);
	}
	free(str);
}
