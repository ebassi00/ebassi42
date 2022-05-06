/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dripanuc <dripanuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:57:13 by ebassi            #+#    #+#             */
/*   Updated: 2022/05/02 18:14:02 by dripanuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_path(char *data)
{
	int	i;

	i = 0;
	if (data[0] == 'c' && data[1] == 'd' && data[2] == ' ' && data[3])
		return (&data[3]);
	return (0);
}

void	change_dir(t_tok *input_ln)
{
	char	*str;
	char	*home_path;
	char	*tmp;

	str = 0;
	tmp = 0;
	home_path = getenv("HOME");
	if (!ft_strncmp(input_ln->data, "cd", ft_strlen(input_ln->data)))
		chdir(home_path);
	else
	{
		str = ft_strtrim(get_path(input_ln->data), " ");
		if (str[0] == '~')
			str = ft_strjoin(home_path, &str[1]);
		else
		{
			str = ft_strjoin_free(ft_strdup("/"), str);
			str = ft_strjoin_free(ft_strdup(getcwd(NULL, 0)), str);
		}
		if (chdir(str))
		{
			g_exit_status = 1;
			ft_putstr_fd("cd: no such file or directory: ", STDERR);
			ft_putendl_fd(get_path(input_ln->data), STDERR);
		}
	}
}
