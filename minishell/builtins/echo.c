/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:57:11 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/13 19:54:06 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_echo_wild(char *str)
{
	char			**files;
	char			*dir;
	int				flag_h;

	dir = getcwd(NULL, 0);
	files = ft_echo_wild2(str, dir);
	if (files[0] == 0)
	{
		files[0] = ft_strdup(str);
		files[1] = 0;
	}
	flag_h = 0;
	if (str[0] == '.')
		flag_h = 1;
	ft_echo_wild_h(files, flag_h);
	ft_free_matrix(files);
	free(dir);
}

void	ft_echo_env(char *echo, int *flag34, int *flag39, char **env)
{
	int	i;

	i = 0;
	while (echo[i])
	{
		if (echo[i] == '$' && *flag39 == 0)
		{
			if (ft_strlen(echo) == 1)
				write(STDOUT, "$", 1);
			else if (echo[i + 1] == '?')
				ft_putnbr_fd(g_exit_status, STDOUT);
			else if (echo[i + 1] == '$')
				ft_putnbr_fd(getpid(), STDOUT);
			else
				i = ft_echo_env2(echo, i, env);
			if (echo[i] == '$')
				i++;
		}
		else
		{
			ft_echo_helper(echo[i], flag34, flag39);
		}
		i++;
	}
}

void	ft_echo2(char **echo, char **env)
{
	int		i;
	int		flag39;
	int		flag34;
	int		j;

	i = -1;
	flag39 = 0;
	flag34 = 0;
	while (echo[++i])
	{
		if (i > 0)
			write(STDOUT, " ", 1);
		if (ft_strchr(echo[i], '*') && !ft_strrchr(echo[i], 34) \
			&& !ft_strrchr(echo[i], 39) && flag34 == 0 && flag39 == 0)
			ft_echo_wild(echo[i]);
		else if (ft_strchr(echo[i], '$') && flag39 == 0)
			ft_echo_env(echo[i], &flag34, &flag39, env);
		else
		{
			j = -1;
			while (echo[i][++j])
				ft_echo_helper(echo[i][j], &flag34, &flag39);
		}
	}
}

char	**ft_echo_wild2(char *str, char *dir)
{
	char			**files;
	char			*find;
	char			*last;

	files = ft_echo_wild3(str, dir);
	str = ft_substr(str, ft_strchr(str, '*') - str + 1, ft_strlen(str));
	find = malloc(ft_strlen(str) + 1);
	last = NULL;
	files = ft_echo_wild2_help(files, str, find, &last);
	files = ft_check_last_echo(files, last, -1, 0);
	if (!last)
		free(last);
	free(find);
	free(str);
	return (files);
}

void	ft_echo_wild_h(char **files, int flag_h)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen_matrix(files);
	files[j] = 0;
	while (i < j)
	{
		if ((i > 0 && files[i - 1][0] != '.' && flag_h == 0) || \
			(i > 0 && files[i - 1][0] == '.' && flag_h == 1))
			write(STDOUT, " ", 1);
		if ((files[i][0] != '.' && flag_h == 0) || \
			(files[i][0] == '.' && flag_h == 1))
			ft_putstr_fd(files[i], STDOUT);
		i++;
	}
}
