/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:06:44 by ebassi            #+#    #+#             */
/*   Updated: 2022/04/04 17:44:32 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_prompt()
{
	write(1, GREEN, ft_strlen(GREEN));
	write(1, "minishell$ ", ft_strlen("minishell$ "));
	write(1, GREEN, ft_strlen(GREEN));
}

char	*get_command(char *line)
{
	int		index;
	int		prev_index;
	char	*command;

	index = -1;
	prev_index = 0;
	command = 0;
	while (line[++index])
	{
		if (index == ' ')
		{
			command = ft_substr(line, prev_index, index);
			prev_index = index;
		}
		index++;
	}
	return (command);
}

void	init_mini(char *envp[])
{
	(void)envp;
	char	*command;
	char	*line;

	line = 0;
	command = 0;
	/*----------------------DA DECOMMENTARE-----------------------*/
	// signal(SIGINT, signal_handler);
	// signal(SIGQUIT, signal_handler);
	// signal(SIGTSTP, signal_handler);
	while (42)
	{
		set_prompt();
		line = readline("");
		if (line)
			command = get_command(line);
		// printf("%s\n", command);
		// pause();
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	init_mini(envp);
	return (0);
}