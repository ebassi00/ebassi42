/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:57:11 by ebassi            #+#    #+#             */
/*   Updated: 2022/04/15 16:19:44 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		prev_echo(char *data, int i)
{
	int	j;

	j = 0;
	while (data[j] && j < i)
	{
		if (data[j] == 'e' && data[j + 1] == 'c' && data[j + 2] == 'h' && data[j + 3] == 'o' && data[j + 4] == ' ')
			return (1);
		j++;
	}
	return (0);
}

int		find_flag(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[i] == '-' && data[i + 1]  == 'n' && prev_echo(&data[i - 5], i))
			return (1);
		i++;
	}
	return (0);
}

char	*trim_all(char *str, char op)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = 0;
	while (str[j])
	{
		if (str[j] == op)
			i++;
		j++;
	}
	if (i % 2 != 0)
		return (0);
	res = malloc (sizeof(char *) * ft_strlen(str) - i + 1);
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
	res = trim_all(input_ln->data, '\"');
	if (!res)
	{
		ft_putendl_fd("error: quotes not closed", STDOUT);
		return ;
	}
	res = trim_all(res, '\'');
	if (!res)
	{
		ft_putendl_fd("error: quotes not closed", STDOUT);
		return ;
	}
	if (!flag)
		ft_putendl_fd(&res[5], STDOUT);
	else
		ft_putstr_fd(&res[8], STDOUT);
}