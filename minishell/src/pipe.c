/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:45:04 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/12 03:14:19 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	first_pipe(t_mini *minishell)
{
	int			piped[2];

	if (pipe(piped) == -1)
		return ;
	minishell->saved_stdin = dup(STDIN_FILENO);
	minishell->saved_stdout = dup(STDOUT_FILENO);
	close(STDOUT_FILENO);
	minishell->pipe = 1;
	minishell->input_fd = piped[0];
	minishell->output_fd = piped[1];
	dup2(minishell->output_fd, STDOUT_FILENO);
	close(minishell->output_fd);
}

void	middle_pipe(t_mini *minishell)
{
	int			piped[2];

	if (pipe(piped) == -1)
		return ;
	minishell->output_fd = piped[1];
	close(STDIN_FILENO);
	dup2(minishell->input_fd, STDIN_FILENO);
	close(minishell->input_fd);
	minishell->input_fd = piped[0];
	dup2(minishell->output_fd, STDOUT_FILENO);
	close(minishell->output_fd);
}

void	last_pipe(t_mini *minishell)
{
	close(STDIN_FILENO);
	dup2(minishell->input_fd, STDIN_FILENO);
	close(minishell->input_fd);
	close(STDOUT_FILENO);
	dup2(minishell->saved_stdout, STDOUT_FILENO);
	close(minishell->saved_stdout);
}

void	reset_fd(t_mini *minishell)
{
	if (minishell->redir)
	{
		close(STDIN_FILENO);
		dup2(minishell->saved_stdin, STDIN_FILENO);
		close(minishell->saved_stdin);
		close(STDOUT_FILENO);
		dup2(minishell->saved_stdout, STDOUT_FILENO);
		close(minishell->saved_stdout);
		minishell->redir_open = 1;
		minishell->redir_exec = 0;
		minishell->redir = 0;
	}
	else if (minishell->pipe)
	{
		minishell->pipe = 0;
		close(STDIN_FILENO);
		dup2(minishell->saved_stdin, STDIN_FILENO);
		close(minishell->saved_stdin);
	}
}
