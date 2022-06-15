/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:36:52 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/12 22:24:44 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exec_wild(char *is_exec, char **path, char **files, char **env)
{
	pid_t			pid;

	pid = fork();
	if (pid == 0)
		g_exit_status = execve(is_exec, files, env);
	else
		waitpid(pid, &g_exit_status, 0);
	if (path)
		ft_free_matrix(path);
	(void)path;
}

char	**ft_find_files3(char *dir, char *srch, int i)
{
	DIR				*folder;
	struct dirent	*entry;
	char			**files;

	folder = opendir(dir);
	if (folder == NULL)
	{
		ft_putendl_fd("Unable to read directory", 2);
		exit(1);
	}
	files = malloc(sizeof(char *) * ft_folder_size(dir) + 2);
	while (1)
	{
		entry = readdir(folder);
		if (entry == NULL)
			break ;
		if (!ft_strncmp(srch, entry->d_name, ft_strlen(srch)))
			files[++i] = ft_strdup(entry->d_name);
	}
	files[++i] = 0;
	closedir(folder);
	return (files);
}

char	**ft_findwild_multi3(char *str, char *dir)
{
	char			**files;
	char			*sub_file;

	if (ft_strncmp(" ", ft_strchr(str, '*') - 1, 1) == 0)
		files = ft_find_files(dir, 0);
	else
	{
		sub_file = ft_substr(str, ft_strchr(str, ' ') - str + 1, \
			ft_strchr(str, '*') - ft_strchr(str, ' ') - 1);
		files = ft_find_files3(dir, sub_file, 0);
		free(sub_file);
	}
	return (files);
}

char	**ft_find_multi(char **files, char *find, char *last)
{
	char	**new;
	int		i;
	int		k;

	if (find[0] == 0 || files[1] == 0)
		return (files);
	i = 1;
	k = 1;
	if (!last)
		last = "";
	new = malloc(sizeof(char *) * ft_strlen_matrix_wild(files) + 1);
	new[0] = 0;
	while (files[i])
	{
		if (ft_strnstr(ft_strnstr(files[i], last, ft_strlen(files[i])) + ft_strlen(last), find, ft_strlen(files[i])) != NULL)
		{
			new[k] = ft_strdup(files[i]);
			k++;
		}
		i++;
	}
	new[k] = 0;
	ft_free_matrix_wild(files);
	return (new);
}

char	**ft_check_last(char **files, char *str, int i)
{
	char	**new;
	int		j;

	if (str[ft_strlen(str) - 1] == '*')
		return (files);
	else if  (files[1] == 0)
	{
		new = ft_calloc(3, sizeof(char *));
		return (new);
	}
	else
	{
		new = malloc(sizeof(char *) * ft_strlen_matrix_wild(files) + 1);
		j = i + 1;
		i++;
		while (files[i])
		{
			if (ft_strchr(str, '*') != NULL)
			{
				if (ft_strcmp_end(files[i], ft_strrchr(str, '*') + 1))
				{
					new[j] = ft_strdup(files[i]);
					j++;
				}
			}
			else
			{
				if (ft_strcmp_end(files[i], str))
				{
					new[j] = ft_strdup(files[i]);
					j++;
				}
			}
			i++;
		}
		new[j] = 0;
	}
	ft_free_matrix_wild(files);
	return (new);
}
