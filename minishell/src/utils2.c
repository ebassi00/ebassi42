/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:13:53 by mpatrini          #+#    #+#             */
/*   Updated: 2022/04/27 17:14:04 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_list(t_tok *x)
{
	while (x)
	{
		printf("TYPE:%d DATA:%s ID: %d\n", x->type, x->data, x->id);
		x = x->next;
	}
}
