/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dripanuc <dripanuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 03:27:17 by mpatrini@st       #+#    #+#             */
/*   Updated: 2022/05/23 03:35:42 by dripanuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(char **matrix)
{
	int	i;
	int d;

	d = ft_strlen_matrix(matrix);
	i = 0;
	while (i < d)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
