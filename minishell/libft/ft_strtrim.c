/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:45:18 by mpatrini          #+#    #+#             */
/*   Updated: 2022/01/19 01:19:06 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	s;
	size_t	e;

	if (!s1 || !set)
		return (NULL);
	s = 0;
	e = ft_strlen(s1);
	while (s1[s] && ft_check_set(s1[s], set))
		s++;
	while (e > s && ft_check_set(s1[e - 1], set))
		e--;
	str = (char *)malloc(e - s + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s < e)
	{
		str[i] = s1[s];
		s++;
		i++;
	}
	str[i] = 0;
	return (str);
}
