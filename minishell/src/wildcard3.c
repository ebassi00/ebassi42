/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:36:52 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/04 13:15:41 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_matrix_wild(char **matrix)
{
	int	i;
	int	b;

	i = 1;
	b = ft_strlen_matrix_wild(matrix);
	while (i < b)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	ft_strcmp_end(char *name, char *end)
{
	int	name_len;
	int	ext_len;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(end);
	if (name_len <= ext_len)
		return (0);
	name += name_len - ext_len;
	while (*name)
	{
		if (*name != *end)
			return (0);
		name++;
		end++;
	}
	return (1);
}

int	ft_folder_size(char *dir)
{
	int				i;
	DIR				*folder;
	struct dirent	*entry;

	folder = opendir(dir);
	i = 0;
	while (1)
	{
		entry = readdir(folder);
		if (entry == NULL)
			break ;
		i++;
	}
	return (i);
}

char	**ft_find_files(char *dir, int i)
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
	files = malloc(sizeof(char *) * ft_folder_size(dir) + 3);
	files[0] = "prova";
	while (1)
	{
		entry = readdir(folder);
		if (entry == NULL)
			break ;
		files[++i] = ft_strdup(entry->d_name);
	}
	files[++i] = 0;
	closedir(folder);
	return (files);
}
