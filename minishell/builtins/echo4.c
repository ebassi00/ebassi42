/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:57:11 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/13 19:56:19 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_echo_wild2_help(char **files, char *str, char *find, char **last)
{
	int	i;
	int	k;

	i = 0;
	k = -1;
	while (1)
	{
		if (str[i] == '*' || str[i] == 0)
		{
			find[++k] = 0;
			files = ft_find_multi_echo(files, find, *last);
			if (find)
				*last = ft_strdup(find);
			k = -1;
		}
		else
			find[++k] = str[i];
		if (str[i] == 0)
			break ;
		i++;
	}
	return (files);
}
