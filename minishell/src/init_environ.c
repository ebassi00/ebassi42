/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_environ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dripanuc <dripanuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:58:36 by ebassi            #+#    #+#             */
/*   Updated: 2022/04/20 17:22:27 by dripanuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		is_valid_env(const char *env)
{
	int		i;

	i = 0;
	if (ft_isdigit(env[i]) == 1)
		return (0);
	while (env[i] && env[i] != '=')
	{
		if (ft_isalnum(env[i]) == 0)
			return (-1);
		i++;
	}
	if (env[i] != '=')
		return (2);
	return (1);
}

void	take_elem_env(t_env *env, int i, char *envp[])
{
	int	j;

	j = 0;
	while (envp[i][j])
	{
		if (envp[i][j] == '=')
		{
			env->key = ft_substr(envp[i], 0, j);
			env->value = ft_substr(envp[i], j + 1, ft_strlen(envp[i]) + 1);
			break ;
		}
		j++;
	}
}

void	take_environ(t_env *env, char *envp[])
{
	int		i;
	t_env	*next;

	i = 0;
	while (envp[i])
	{
		next = malloc (sizeof(t_env));
		take_elem_env(env, i, envp);
		env->next = next;
		env = env->next;
		i++;
	}
	env->next = NULL;
}