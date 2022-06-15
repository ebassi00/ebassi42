/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:58:36 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/12 02:01:20 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	here_doc(char *lim)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		; // pipe error
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (1)
		{
			line = get_next_line(0);
			if (ft_strncmp(line, lim, ft_strlen(lim)) == 0 && ft_strlen(line) == ft_strlen(lim))
			{
				free(line);
				exit(0);
			}
			write(fd[1], line, ft_strlen(line));
			free(line);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN);
		wait(NULL);
	}
}