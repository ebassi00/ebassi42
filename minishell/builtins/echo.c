/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dripanuc <dripanuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:57:11 by ebassi            #+#    #+#             */
/*   Updated: 2022/05/06 11:40:50 by dripanuc         ###   ########.fr       */
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

int	trim_all2(char *str, char op)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] == op)
			i++;
		j++;
	}
	if (i % 2 != 0)
		return (-1);
	return (i);
}

char	*trim_all(char *str, char op)
{
	char	*res;
	int		i;
	int		j;

	i = trim_all2(str, op);
	if (i == -1)
		return (NULL);
	res = malloc (ft_strlen(str) - i + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == op)
			i++;
		else
		{
			res[j] = str[i];
			j++;
			i++;
		}
	}
	res[j] = '\0';
	return (res);
}

void	ft_echo(t_tok *input_ln)
{
	int		i;
	int		flag;
	char	*res;

	i = 0;
	flag = 0;
	res = 0;
	flag = find_flag(input_ln->data);
	res = ft_strtrim(&(input_ln->data[4]), " ");
	if (flag)
		res = ft_strtrim(&res[3], " ");
	res = trim_all(res, '\"');
	res = trim_all(res, '\'');
	if (flag)
		ft_putstr_fd(res, STDOUT);
	else
		ft_putendl_fd(res, STDOUT);
	free(res);
}
