/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:54:34 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/13 19:15:22 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_cmd(t_mini *mini, t_tok *i_ln)
{
	int		i;
	char	*str;
	char	**builtin;
	int		fd;
	t_tok	*head;

	i = 0;
	str = 0;
	builtin = ft_split("cd echo env exit export pwd unset", ' ');
	mini->tmpdirections = 0;
	head = i_ln;
	while (i_ln)
	{
		i = 0;
		while (1 && !i_ln->type)
		{
			if (i_ln->data[i] == ' ' || !i_ln->data[i])
			{
				str = ft_substr(i_ln->data, 0, i);
				if (i_ln->next && !(ft_strncmp("|", i_ln->next->data, 1)) \
					&& !mini->pipe)
					first_pipe(mini);
				else if (mini->pipe && i_ln->next \
					&& !ft_strncmp("|", i_ln->next->data, 1))
					middle_pipe(mini);
				else if (mini->pipe)
					last_pipe(mini);
				if (!mini->redir && i_ln->next && !(ft_strncmp(">>", i_ln->next->data, 2)))
					redir(mini, i_ln, 0, 1);
				else if (!mini->redir && i_ln->next && !(ft_strncmp(">", i_ln->next->data, 1)))
					redir(mini, i_ln, 0, 0);
				else if (mini->redir && (!i_ln->next || (ft_strncmp(">", i_ln->next->data, 1) && ft_strncmp(">>", i_ln->next->data, 2))))
					mini->redir_exec = 1;
				else if (mini->redir && (!(ft_strncmp(">", i_ln->next->data, 1) || !(ft_strncmp(">>", i_ln->next->data, 2)))))
					redir(mini, i_ln, 1, 0);
				if (ft_find(builtin, str))
				{
					if (!(ft_strncmp("pwd", str, 3)))
						get_pwd();
					else if (!(ft_strncmp("cd", str, 2)))
						change_dir(i_ln, mini);
					else if (!(ft_strncmp("echo", str, 4)))
						ft_echo(i_ln, mini->env);
					else if (!(ft_strncmp("env", str, 3)))
						get_env(mini->env);
					else if (!(ft_strncmp("exit", str, 4)))
						exit_command(mini, head); // aggiungere i free
					else if (!(ft_strncmp("export", str, 6)))
						mini->env = export_command(mini->env, i_ln);
					else if (!(ft_strncmp("unset", str, 5)))
						mini->env = unset_var(mini->env, i_ln);
				}
				else if (!mini->redir_exec)
					ft_wildcard(i_ln->data, !i_ln->next, mini->env);
				if (mini->tmpdirections)
				{
					fd = open(mini->tmpdirections, O_TRUNC, 0664);
					close(fd);
					mini->tmpdirections = 0;
				}
				// else
				// 	mini->redir_open = 0;
				if ((mini->pipe && mini->redir_open && (!i_ln->next || ft_strncmp("|", i_ln->next->data, 1))))
					reset_fd(mini);
				else if (!mini->redir_open && (!i_ln->next || (ft_strncmp(">", i_ln->next->data, 1) && ft_strncmp(">>", i_ln->next->data, 2))))
					reset_fd(mini);
				break ;
				free(str);
			}
			i++;
		}
		if (i_ln->type)
		{
			if (!handle_separator(i_ln))
			{
				return ;
			}
		}
		i_ln = i_ln->next;
	}
	ft_free_matrix(builtin);
	// while (waitpid(-1, NULL, 0) > 0)
	// 	;
}
