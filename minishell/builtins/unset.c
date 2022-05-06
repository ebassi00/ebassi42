/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:01:08 by ebassi            #+#    #+#             */
/*   Updated: 2022/04/27 16:25:14 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_env(t_env *env)
{
	free(env->key);
	free(env->value);
	free(env);
}

char	*unset_var2(t_tok *input)
{
	int i;

	i = 0;
	while (input->data[i] != ' ' && input->data[i])
		i++;
	return (ft_strtrim(&input->data[i], " "));
}

void	unset_var(t_env **env, t_tok *input)
{
	t_env	*prev;
	t_env	*head;
	t_env	*curr;

	input->data = unset_var2(input);
	head = *env;
	curr = head;
	prev = NULL;
	while (curr)
	{
		if (ft_strncmp(curr->key, input->data, ft_strlen(curr->key)) == 0)
		{
			if (!prev)
				head = head->next;
			else if (curr->next != NULL)
				prev->next = curr->next;
			else
				prev->next = NULL;
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
	ft_free_env(curr);
	*env = head;
}
