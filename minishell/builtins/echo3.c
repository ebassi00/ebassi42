/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:57:11 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/13 19:56:07 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_check_last_echo(char **files, char *str, int i, int j)
{
	char	**new;

	if (str[ft_strlen(str) - 1] == '*')
		return (files);
	else
	{
		new = malloc(sizeof(char *) * ft_strlen_matrix(files) + 1);
		j = i;
		while (files[++i])
		{
			if (ft_strchr(str, '*') != NULL)
			{
				if (ft_strcmp_end(files[i], ft_strrchr(str, '*') + 1))
					new[++j] = ft_strdup(files[i]);
			}
			else
			{
				if (ft_strcmp_end(files[i], str))
					new[++j] = ft_strdup(files[i]);
			}
		}
		new[++j] = 0;
	}
	ft_free_matrix_wild(files);
	return (new);
}

char	*ft_get_env(char **env, char *str)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], str, ft_strlen(str)) == 0 \
			&& env[i][ft_strlen(str)] == '=')
			return (ft_substr(env[i], ft_strlen(str) + 1, ft_strlen(env[i])));
		i++;
	}
	return (NULL);
}

int	ft_echo_env2(char *echo, int i, char **env)
{
	char	*str;
	char	*echo_env;
	int		j;

	j = i + 1;
	while (echo[j])
	{
		if (echo[j] == 34 || echo[j] == 39)
			break ;
		else if (ft_isdigit(echo[j]))
		{
			i++;
			break ;
		}
		j++;
	}
	str = ft_substr(echo, i + 1, j - i - 1);
	echo_env = ft_get_env(env, str);
	if (echo_env)
		ft_putstr_fd(echo_env, STDOUT);
	free(str);
	return (j - 1);
}

void	ft_echo(t_tok *input_ln, char **env)
{
	int		flag;
	char	*res;
	char	**echo;

	flag = 0;
	res = 0;
	flag = find_flag(input_ln->data);
	res = ft_strtrim(&(input_ln->data[4]), " ");
	if (flag)
		res = ft_strtrim(&res[3], " ");
	echo = ft_split(res, ' ');
	ft_echo2(echo, env);
	if (!flag)
		write(STDOUT, "\n", 1);
	free(res);
	ft_free_matrix(echo);
}

void	ft_echo_helper(char echo, int *flag34, int *flag39)
{
	if (echo == 39 && flag34 == 0)
		ft_echo_flag(flag39);
	else if (echo == 34 && flag39 == 0)
		ft_echo_flag(flag34);
	else
		write(STDOUT, &echo, 1);
}
