/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:01:19 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/13 18:38:46 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_command( t_mini *mini, t_tok *i_ln )
{
	(void)i_ln;
	free(mini->tmpdirections);
	ft_free_matrix(mini->env);
	printf("exit\n");
	exit(0);
}

void	exit_command_signal( int sig )
{
	if (sig == SIGQUIT)
	{
		printf("exit\n");
		exit(0);
	}
}
