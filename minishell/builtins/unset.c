/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:01:08 by ebassi            #+#    #+#             */
/*   Updated: 2022/06/13 18:37:09 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*unset_var2(t_tok *input)
{
	int	i;

	i = 0;
	while (input->data[i] != ' ' && input->data[i])
		i++;
	return (ft_strtrim(&input->data[i], " "));
}

char	**unset_var(char **env, t_tok *input)
{
	int		i;
	char	**tmp;
	char	*name;

	name = unset_var2(input);
	if (ft_get_env(env, name) != NULL)
	{
		i = ft_strlen_matrix(env);
		tmp = (char **)malloc(sizeof(char *) * i);
		i = 0;
		while (env[i])
		{
			if (ft_strncmp(env[i], name, ft_strlen(name)) != 0 \
				&& env[i][ft_strlen(name)] != '=')
				tmp[i] = env[i];
			i++;
		}
		tmp[i] = 0;
		ft_free_matrix(env);
		return (tmp);
	}
	free(name);
	return (env);
}
