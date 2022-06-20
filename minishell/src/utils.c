/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:44:40 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/12 04:43:56 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	signal_handler(int sig)
{
	if (sig == SIGINT)
		return ;
}

char	*set_prompt(char **env)
{
	char	*str;
	char	*tmp;

	//I colori del cazzo bugguno tutta la history
	str = 0;
	tmp = 0;
	// str = ft_strdup(GREEN);
	tmp = ft_strdup(ft_get_env(env, "USER"));
	if (!tmp)
		tmp = ft_strdup("guest");
	tmp = ft_strjoin_free(tmp, ft_strdup("@minishell$ "));
	// str = ft_strjoin_free(str, tmp);
	// tmp = ft_strdup(RESET);
	// str = ft_strjoin_free(str, tmp);
	str = tmp;
	return (str);
}

void	get_next_lst(t_tok *input_ln)
{
	t_tok	*next_lst;

	next_lst = malloc(sizeof(t_tok));
	next_lst->id = input_ln->id + 1;
	input_ln->next = next_lst;
}

void	init(t_tok *x)
{
	x->type = 0;
	x->data = NULL;
	x->exit = 0;
	x->next = NULL;
}
