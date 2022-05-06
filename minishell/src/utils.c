/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dripanuc <dripanuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:44:40 by ebassi            #+#    #+#             */
/*   Updated: 2022/05/06 12:49:23 by dripanuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	signal_handler(int sig)
{
	if (sig == SIGINT)
		return ;
}

char	*set_prompt( void )
{
	char	*str;
	char	*tmp;

	// I colori del cazzo bugguno tutta lla history
	str = 0;
	tmp = 0;
	str = ft_strdup("\1"GREEN"\2");
	tmp = getenv("USER");
	if (!tmp)
		tmp = ft_strdup("guest");
	tmp = ft_strjoin(tmp, "@minishell$ ");
	str = ft_strjoin(str, tmp);
	free(tmp);
	tmp = ft_strdup("\1"RESET"\2");
	str = ft_strjoin(str, tmp);
	return (str);
}

void	get_next_lst(t_tok *input_ln)
{
	t_tok	*next_lst;

	next_lst = malloc(sizeof(t_tok));
	next_lst->id = input_ln->id + 1;
	input_ln->next = next_lst;
}

void	init_env(t_env *env)
{
	env = malloc (sizeof(t_env));
	env->key = 0;
	env->value = 0;
	env->next = 0;
}

void	init(t_tok *x)
{
	x->type = 0;
	x->data = NULL;
	x->exit = 0;
	x->next = NULL;
}
