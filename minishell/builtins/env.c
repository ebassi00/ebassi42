/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:01:15 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/13 18:39:24 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strchr(env[i], '='))
			ft_putendl_fd(env[i], STDOUT);
		i++;
	}
}
