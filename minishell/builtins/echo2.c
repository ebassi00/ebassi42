/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:57:11 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/13 19:45:24 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	prev_echo(char *data, int i)
{
	int	j;

	j = 0;
	while (data[j] && j < i)
	{
		if (data[j] == 'e' && data[j + 1] == 'c' && data[j + 2] == 'h' \
			&& data[j + 3] == 'o' && data[j + 4] == ' ')
			return (1);
		j++;
	}
	return (0);
}

int	find_flag(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[i] == '-' && data[i + 1] == 'n' && prev_echo(data, i))
			return (1);
		i++;
	}
	return (0);
}

void	ft_echo_flag(int *i)
{
	if (*i == 0)
		*i = 1;
	else
		*i = 0;
}

char	**ft_echo_wild3(char *str, char *dir)
{
	char			**files;
	char			*sub_file;

	if (str[0] == '*')
		files = ft_find_files(dir, -1);
	else
	{
		sub_file = ft_substr(str, 0, ft_strchr(str, '*') - str);
		files = ft_find_files3(dir, sub_file, -1);
		free(sub_file);
	}
	return (files);
}

char	**ft_find_multi_echo(char **files, char *find, char *last)
{
	char	**new;
	int		i;
	int		k;

	if (find[0] == 0)
		return (files);
	i = 0;
	k = -1;
	if (!last)
		last = "";
	new = malloc(sizeof(char *) * ft_strlen_matrix(files) + 1);
	new[0] = 0;
	while (files[i])
	{
		if (ft_strnstr(ft_strnstr(files[i], last, \
			ft_strlen(files[i])) + ft_strlen(last), find, \
			ft_strlen(files[i])) != NULL)
			new[++k] = ft_strdup(files[i]);
		i++;
	}
	new[++k] = 0;
	ft_free_matrix(files);
	return (new);
}
