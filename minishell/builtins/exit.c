/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dripanuc <dripanuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:01:19 by ebassi            #+#    #+#             */
/*   Updated: 2022/05/02 16:59:53 by dripanuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_command(void)
{
	printf("exit\n");
	exit(0);
}

void	exit_command_signal(int sig)
{
	if (sig == SIGQUIT)
	{
		printf("exit\n");
		exit(0);
	}
}
