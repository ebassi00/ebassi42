/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:06:44 by ebassi            #+#    #+#             */
/*   Updated: 2022/04/08 18:12:32 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_prompt()
{
	write(1, GREEN, ft_strlen(GREEN));
	write(1, "minishell$ ", ft_strlen("minishell$ "));
	write(1, GREEN, ft_strlen(GREEN));
}

void	get_next_lst(t_tok *input_ln)
{
	t_tok	*next_lst;

	next_lst = malloc(sizeof(t_tok));
	input_ln->next = next_lst;
}

void handle_op(t_tok *input_ln, char *op)
{
	input_ln->type = 1;
	input_ln->data = op;
	input_ln->flag = 0;
}

void	get_command(t_tok *input_ln, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '|' || line[i] == '>' || line[i] == '<')
		{
			get_next_lst(input_ln);
			input_ln = input_ln->next;
			handle_op(input_ln, ft_substr(line, i, 1));
			get_next_lst(input_ln);
			input_ln = input_ln->next;
			j = i + 1;
		}
		input_ln->type = 0;
		input_ln->data = ft_substr(line, j, i - j + 1);
		input_ln->flag = 0;
		i++;
	}
	input_ln->next = 0;
}

void	init_mini(char *envp[])
{
	(void)envp;
	t_tok	*input_ln;
	char	*command;
	char	*line;

	line = 0;
	command = 0;
	input_ln = malloc (sizeof(t_tok));
	/*----------------------DA DECOMMENTARE-----------------------*/
	// signal(SIGINT, signal_handler);
	// signal(SIGQUIT, signal_handler);
	// signal(SIGTSTP, signal_handler);
	while (42)
	{
		set_prompt();
		line = readline("");
		if (line)
		{
			get_command(input_ln, line);
			while (input_ln)
			{
				printf("TYPE:%d DATA:%s\n", input_ln->type, input_ln->data);
				input_ln = input_ln->next;
			}
		}
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	init_mini(envp);
	return (0);
}