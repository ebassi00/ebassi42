/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:47:18 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/13 18:20:49 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_separator(t_tok *input_ln)
{
	// if (!(ft_strncmp(input_ln->data, "|", 1)))
	// 	;
	if (!(ft_strncmp(input_ln->data, "&&", 2)))
	{
		if (g_exit_status == -1)
		{
			return (0);
		}
	}
	/*else if (!(ft_strncmp(">>", input_ln->data, 2)))
		ft_echo(input_ln);
	else if (!(ft_strncmp("<<", input_ln->data, 2)))
		ft_echo(input_ln);
	else if (!(ft_strncmp(">", input_ln->data, 1)))
		ft_echo(input_ln);
	else if (!(ft_strncmp("<", input_ln->data, 1)))
		ft_echo(input_ln);*/
	// printf("%s\n", input_ln->data);
	return (1);
}

void	redir(t_mini *minishell, t_tok *input_ln, int flag, int type)
{
	// int		fd;

	// fd = 0;
	if (!type)
		minishell->output_fd = open(input_ln->next->next->data, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	else
		minishell->output_fd = open(input_ln->next->next->data, O_WRONLY | O_APPEND	, 0664);
	if (!minishell->redir)
	{
		dup2(STDOUT_FILENO, 51);
		minishell->saved_stdout = 51;
		close(STDOUT_FILENO);
	}
	if (!minishell->redir && !minishell->pipe)
	{
		dup2(STDIN_FILENO, 50);
		minishell->saved_stdin = 50;
		close(STDIN_FILENO);
	}
	else
		minishell->pipe = 0;
	minishell->redir = 1;
	minishell->redir_open = 0;
	if (flag)
	{
		minishell->tmpdirections = input_ln->data;
		input_ln->data = ft_strjoin_free(ft_strdup("cat "), input_ln->data);
	}
	dup2(minishell->output_fd, STDOUT_FILENO);
	close(minishell->output_fd);
}

t_tok	change_cmd_redir(t_tok *i_ln, int i, int *flag)
{
	t_tok	*tmp;
	t_tok	*tmp2;
	t_tok	*tmp3;
	int		j;

	tmp = i_ln;
	j = i;
	if (!i)
		return (*i_ln);
	*flag = 1;
	while (i)
	{
		if (i_ln->next)
			i_ln = i_ln->next->next;
		i--;
	}
	tmp2 = 0;
	tmp3 = i_ln;
	if (tmp3)
	{
		tmp2 = tmp3->next;
		tmp3->next = tmp;
	}
	while (j)
	{
		if (i_ln->next)
			i_ln = i_ln->next->next;
		j--;
	}
	i_ln->next = tmp2;
	i_ln = tmp3;
	return (*tmp3);
}

void print_list(t_tok *i_ln)
{
	t_tok *tmp;

	tmp = i_ln;
	while (tmp)
	{
		printf("Nodo lista: %s -> %p\n", tmp->data, tmp->next);
		tmp = tmp->next;
	}
}

int	check_redir(t_tok *i_ln)
{
	int	i;
	int len;
	int j;
	char *tmp2;
	t_tok *tmp;

	i = 0;
	j = -1;
	while (i_ln)
	{
		if (!i_ln->type)
			break ;
		if (i_ln->data && (i_ln->data[0] == '>' || i_ln->data[0] == '<'))
		{
			j = -1;
			while (i_ln->next->data[++j])
			{
				if (i_ln->next->data[j] == ' ')
				{
					tmp = i_ln->next->next;
					tmp2 = ft_strdup(i_ln->next->data);
					len = ft_strlen(i_ln->next->data);
					i_ln->next->data = ft_substr_free(i_ln->next->data, 0, j);
					get_next_lst(i_ln->next);
					i_ln->next->next->data = ft_substr_free(tmp2, j + 1, len);
					i_ln->next->next->next = tmp;
				}
			}
			i++;
		}
		i_ln = i_ln->next->next;
	}
	return (i);
}

void	ft_free_i_ln(t_tok *i_ln)
{
	t_tok	*tmp;

	while(i_ln)
	{
		// free(i_ln->data);
		tmp = i_ln->next;
		free(i_ln);
		i_ln = tmp;
	}
}

void	init_mini(char *envp[])
{
	t_tok	*input_ln;
	t_tok	tmp;
	t_mini	minishell;
	char	*line;
	char	*str;
	int		flag;

	line = 0;
	flag = 0;
	minishell.pipe = 0;
	minishell.saved_stdout = dup(STDOUT_FILENO);
	minishell.saved_stdin = dup(STDIN_FILENO);
	minishell.redir = 0;
	minishell.redir_open = 1;
	minishell.redir_exec = 0;
	minishell.env = envp;
	// init_env(env);
	// take_environ(&env, envp);
	/*----------------------DA DECOMMENTARE-----------------------*/
	signal(SIGINT, &signal_handler);
	// signal(SIGQUIT, &exit_command_signal);
	// signal(SIGTSTP, signal_handler);
	while (42)
	{
		input_ln = malloc(sizeof(t_tok));
		init(input_ln);
		str = set_prompt(minishell.env);
		line = readline(str);
		free(str);
		if (!line)
			return ;
		line = check_readline(line);
		if (ft_strlen(line) > 0)
		{
			minishell.pipe = 0;
			add_history(line);
			get_command(input_ln, line, minishell.env);
			tmp = change_cmd_redir(input_ln, check_redir(input_ln), &flag);
			if (flag)
				tmp.next = input_ln;
			handle_cmd(&minishell, &tmp);
		}
		free(input_ln);
		free(line);
	}
	close(minishell.saved_stdout);
	close(minishell.saved_stdin);
}

char **ft_init_env(char **env, int k)
{
	char **tmp;
	int i;
	int lvl;

	if (k == 1)
		lvl = ft_atoi(ft_get_env(env, "SHLVL")) + 1;
	else
		lvl = ft_atoi(ft_get_env(env, "SHLVL"));
	i = ft_strlen_matrix(env);
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while(env[i])
	{
		if (ft_strncmp(env[i], "SHLVL=", 6) == 0)
			tmp[i] = ft_strjoin_free(ft_strdup("SHLVL="), ft_itoa(lvl));
		else
			tmp[i] = ft_strdup(env[i]);
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	g_exit_status = 0;
	envp = ft_init_env(envp, 1);
	init_mini(envp);
	// ft_free_matrix(envp);
	return (0);
}
