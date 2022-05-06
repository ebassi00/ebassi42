/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:01:15 by ebassi            #+#    #+#             */
/*   Updated: 2022/04/27 17:10:07 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		ft_putstr_fd(tmp->key, STDOUT);
		ft_putchar_fd('=', STDOUT);
		ft_putendl_fd(tmp->value, STDOUT);
		tmp = tmp->next;
	}
}
