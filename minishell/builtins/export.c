/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:01:00 by ebassi            #+#    #+#             */
/*   Updated: 2022/04/26 18:40:55 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_envadd_back(t_env *lst, t_env *new)
{
	while (lst)
	{
		if (lst->next == NULL)
		{
			lst->next = new;
			break ;
		}
		lst = lst->next;
	}
}

t_env	*ft_newenv(char *content)
{
	t_env	*res;
	int		j;

	j = 0;
	res = (t_env *) malloc (sizeof(t_env));
	while (content[j])
	{
		if (content[j] == '=')
		{
			res->key = ft_substr(content, 0, j);
			res->value = ft_substr(content, j + 1, ft_strlen(&content[j]) + 1);
			res->next = NULL;
			break ;
		}
		j++;
	}
	return (res);
}

void	export_command(t_env *env, t_tok *input)
{
	t_env	*new;
	char	*res;
	int		i;

	i = 0;
	while (input->data[i] != ' ' && input->data[i])
		i++;
	input->data = ft_strtrim(&input->data[i], " ");
	if (is_valid_env(input->data) != 1)
		return ;
	while (input->data[i] != '=' && input->data[i])
		i++;
	res = trim_all(input->data, '\"');
	if (!res)
	{
		ft_putendl_fd("Error: quotes not closed", STDOUT);
		return ;
	}
	res = trim_all(res, '\'');
	if (!res)
	{
		ft_putendl_fd("Error: quotes not closed", STDOUT);
		return ;
	}
	new = ft_newenv(input->data);
	// printf("%s\n",new->key);
	// printf("%s\n",new->value);
	// printf("%p\n",new->next);
	ft_envadd_back(env, new);
}