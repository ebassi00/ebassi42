/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:57:09 by ebassi            #+#    #+#             */
/*   Updated: 2022/06/03 22:49:55 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_pwd( void )
{
	char	*wd;

	wd = getcwd(NULL, 0);
	ft_putendl_fd(wd, 1);
	free(wd);
}
