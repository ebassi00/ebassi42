/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:13:53 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/02 15:34:09 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strlen_matrix_wild(char **matrix)
{
	int	i;

	i = 1;
	while (matrix[i])
		i++;
	return (i);
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
