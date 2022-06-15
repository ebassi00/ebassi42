/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:01:00 by ebassi            #+#    #+#             */
/*   Updated: 2022/06/13 18:33:22 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char **ft_copy_env(char **env)
{
	char **tmp;
	int i;
	
	i = ft_strlen_matrix(env);
	tmp = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while(env[i])
	{
		tmp[i] = ft_strdup(env[i]);
		i++;
	}
	tmp[i] = 0;
	tmp[i + 1] = 0;
	return (tmp);
}

void	ft_replace_env(char *env, char *name, char *value)
{
	char	*new;
	
	free(env);
	new = ft_strjoin(name, "=");
	env = ft_strjoin_free(new, ft_strdup(value));
}

void	ft_print_export(char **env2)
{
	int i;
	
	i = 0;
	while(env2[i])
	{
		ft_putstr_fd("declare -x ", STDOUT);
		write(STDOUT, env2[i], ft_strchr(env2[i],'=') - env2[i] + 1);
		ft_putchar_fd(34, STDOUT);
		ft_putstr_fd(ft_strchr(env2[i],'=') + 1, STDOUT);
		ft_putendl_fd("\"", STDOUT);
		i++;
	}
}

void	ft_export_alone(char **env)
{
	int		i;
	int		j;
	char	*tmp;
	char	**env2;

	i = 0;
	env2 = ft_init_env(env, 0);
	while(env2[i])
	{
		j = i +1;
		while(env2[j])
		{
			if (ft_strncmp(env2[i], env2[j], ft_strlen(env2[i])) > 0)
			{
				tmp = env2[i];
				env2[i] = env2[j];
				env2[j] = tmp;
			}
			j++;
		}
		i++;
	}
	ft_print_export(env2);
	ft_free_matrix(env2);
}

char	**export_command(char **env, t_tok *input)
{
	int		i;
	char	*env_n;
	char	**tmp;
	
	if (ft_strncmp(input->data, "export", ft_strlen(input->data)) == 0)
	{
		ft_export_alone(env);
		return (env);
	}
	env_n = ft_substr(ft_strchr(input->data, ' ') + 1, 0, ft_strchr(input->data, '=') - ft_strchr(input->data, ' ') - 1);
	if (env_n[ft_strlen(env_n) - 1] == '+')
		env_n[ft_strlen(env_n) - 1] = 0;
	if (ft_get_env(env, env_n) == NULL)
	{
		i = ft_strlen_matrix(env);
		tmp = ft_copy_env(env);
		ft_free_matrix(env);
		tmp[i] = ft_substr(ft_strchr(input->data, ' ') + 1, 0, ft_strlen(input->data));
		return (tmp);
	}
	else
	{
		i = -1;
		while(env[++i])
		{
			if (ft_strncmp(env[i], env_n, ft_strlen(env_n)) == 0 &&  env[i][ft_strlen(env_n)] == '=')
			{
				if (input->data[ft_strchr(input->data, ' ') - input->data + 1 + ft_strlen(env_n)] == '=')
					ft_replace_env(env[i], env_n, ft_strchr(input->data, '=') + 1);
				else
					env[i] = ft_strjoin_get(env[i], ft_strchr(input->data, '=') + 1);
			}
		}
	}
	free(env_n);
	return (env);
}
