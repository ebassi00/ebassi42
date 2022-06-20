/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:36:52 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/12 22:06:21 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_findwild_multi2(char *str, char *dir)
{
	char			**files;
	char			*find;
	int				i;
	int				k;
	char			*last;

	files = ft_findwild_multi3(str, dir);
	str = ft_substr(str, ft_strchr(str, '*') - str + 1, ft_strlen(str));
	find = malloc(ft_strlen(str) + 1);
	i = 0;
	k = -1;
	last = NULL;
	while (1)
	{
		if (str[i] == '*' || str[i] == 0)
		{
			find[++k] = 0;
			files = ft_find_multi(files, find, last);
			if (find)
				last = ft_strdup(find);
			k = -1;
		}
		else
			find[++k] = str[i];
		if (str[i] == 0)
			break ;
		i++;
	}
	files = ft_check_last(files, str, 0);
	if (last)
		free(last);
	free(find);
	free(str);
	return (files);
}

void	ft_findwild_multi(char *str, char *dir, char **path, char **env)
{
	char			**files;
	int				i;
	char			*is_exec;
	int				j;

	files = ft_findwild_multi2(str, dir);
	if (files[1] == 0)
	{
		files[1] = ft_substr(str, ft_strchr_int(str, ' ') + 1, ft_strlen(str));
		files[2] = 0;
	}
	files[0] = ft_substr(str, 0, ft_strchr_int(str, ' '));
	i = 0;
	j = ft_strlen_matrix(files);
	while (path[i])
	{
		is_exec = find_exec(opendir(path[i]), str, path[i]);
		if (is_exec)
			break ;
		i++;
	}
	if (!is_exec)
	{
		my_exec2(str, env);
		return ;
	}
	files[j] = 0;
	ft_exec_wild(is_exec, path, files, env);
	ft_free_matrix(files);
}

char	*ft_wild_singolo(char *str, char *dir)
{
	DIR				*folder;
	struct dirent	*entry;
	char			*srch;

	folder = opendir(dir);
	srch = ft_substr(str, 0, ft_strchr_int(str, '*'));
	if (folder == NULL)
	{
		ft_putendl_fd("Unable to read directory", 2);
		exit(1);
	}
	while (1)
	{
		entry = readdir(folder);
		if (entry == NULL)
			break ;
		if (!ft_strncmp(srch, entry->d_name, ft_strlen(srch)))
		{
			free(str);
			str = ft_strdup(entry->d_name);
			break ;
		}
	}
	closedir(folder);
	free(srch);
	return (str);
}

void	ft_wildcard(char *str, int i, char **env)
{
	char	*dir;
	char	**path;

	path = ft_split(ft_get_env(env, "PATH"), ':');
	dir = getcwd(NULL, 0);
	if (!dir)
		exit(1);
	if (!ft_strchr(str, '*'))
			execute_command_from_system(str, i, env);
	else if (ft_strchr(str, '*'))
	{
		if (ft_strchr(str, '*') && !ft_strchr(str, ' '))
			execute_command_from_system(ft_wild_singolo(str, dir), i, env);
		else
			ft_findwild_multi(str, dir, path, env);

	}
	else if (ft_strchr(str, '*') != NULL && ft_strchr(str, '/') != NULL)
		ft_putendl_fd("Wildcards works only in current dir", 2);
	else
		execute_command_from_system(str, i, env);
	free(dir);
}
