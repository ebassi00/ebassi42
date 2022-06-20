/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_environ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:58:36 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/11 22:45:48 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// int	is_valid_env(const char *env)
// {
// 	int		i;

// 	i = 0;
// 	if (ft_isdigit(env[i]) == 1)
// 		return (0);
// 	while (env[i] && (env[i] != '=' && ft_strncmp(&env[i], "+=", 2)))
// 	{
// 		if (ft_isalnum(env[i]) == 0)
// 			return (-1);
// 		i++;
// 	}
// 	if (env[i] != '=' && ft_strncmp(&env[i], "+=", 2))
// 		return (2);
// 	return (1);
// }

// void	take_elem_env(t_env *env, int i, char *envp[])
// {
// 	int	j;

// 	j = 0;
// 	while (envp[i][j])
// 	{
// 		if (envp[i][j] == '=')
// 		{
// 			env->key = ft_substr(envp[i], 0, j);
// 			env->value = ft_substr(envp[i], j + 1, ft_strlen(envp[i]) + 1);
// 			break ;
// 		}
// 		j++;
// 	}
// }

// void	take_environ(t_env **env, char *envp[])
// {
// 	int		i;
// 	t_env	*prev;
// 	t_env	*curr;

// 	i = 0;
// 	curr = NULL;
// 	while (envp[i])
// 	{
// 		prev = curr;
// 		curr = malloc (sizeof(t_env));
// 		if (prev)
// 			prev->next = curr;
// 		take_elem_env(curr, i, envp);
// 		if (!*env)
// 			*env = curr;
// 		i++;
// 	}
// 	curr->next = NULL;
// }
