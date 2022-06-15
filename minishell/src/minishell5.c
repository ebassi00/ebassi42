/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:54:34 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/12 04:27:00 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
	return ;
}

void	my_exec2(char *str, char **env)
{
	char	*tmp;
	char	*tmp2;
	
	tmp = trim_all(str, 34);
	tmp = trim_all(str, 39);
	tmp2 = last_field(ft_get_env(env, "SHELL"));
	ft_putstr_fd(tmp2, 1);
	ft_putstr_fd(": command not found: ", 1);
	ft_putendl_fd(tmp, 1);
	free(tmp);
	free(tmp2);
	free(str);
	g_exit_status = -1;
}

void	my_exec(char **path, char *is_exec, char **flags, char **env)
{
	g_exit_status = execve(is_exec, flags, env);
	if (path)
		ft_free_path(path);
}
