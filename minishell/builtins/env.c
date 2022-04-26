/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:01:15 by ebassi            #+#    #+#             */
/*   Updated: 2022/04/26 18:43:03 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp->next)
	{
		ft_putstr_fd(tmp->key, STDOUT);
		ft_putchar_fd('=', STDOUT);
		ft_putendl_fd(tmp->value, STDOUT);
		tmp = tmp->next;
	}
}