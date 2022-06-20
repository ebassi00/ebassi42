/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:54:34 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/12 03:49:02 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	qquotes(char c, int q)
{

	if (c == '"' && !q)
		q = 2;
	else if (c == '"' && q == 2)
		q = 0;
	else if (c == '\'' && !q)
		q = 1;
	else if (c == '\'' && q == 1)
		q = 0;
	return (q);
}

void	expand_envars(t_tok *input_ln, char **env)
{
	// (void)input_ln;
	int		i;
	int		j;
	int		quotes;
	char	*current_env;
	char	*new_data;

	i = 0;
	j = 0;
	current_env = 0;
	new_data = 0;
	quotes = 0;
	while (input_ln)
	{
		i = 0;
		if (ft_strncmp(input_ln->data, "echo ", 5))
		{
			while (input_ln->data[i])
			{
				quotes = qquotes(input_ln->data[i], quotes);
				if (input_ln->data[i] == '$' && quotes != 1)
				{
					j = i++;
					if (input_ln->data[i++] == '?')
						current_env = ft_itoa(g_exit_status);
					else
					{						while (input_ln->data[i] >= 63 && input_ln->data[i] <= 125)
							i++;
						current_env = ft_substr_free(input_ln->data, j + 1, i - j - 1);
						if (!current_env || !current_env[0])
							current_env = ft_strdup("");
						else
						{
							current_env = ft_get_env(env, current_env);
							if (!current_env)
								current_env = ft_strdup("");
						}
					}
					new_data = ft_substr(input_ln->data, 0, j);
					new_data = ft_strjoin_free(new_data, current_env);
					new_data = ft_strjoin_get(new_data, &input_ln->data[i]);
					input_ln->data = new_data;
					if (!input_ln->data[i])
						return ;
				}
				if (input_ln->data[i] == '~' && !quotes)
				{
					new_data = ft_substr(input_ln->data, 0, i);
					new_data = ft_strjoin_free(new_data, ft_strdup(ft_get_env(env, "HOME")));
					new_data = ft_strjoin_get(new_data, &input_ln->data[i + 1]);
					input_ln->data = new_data;
				}
				// if (!ft_strncmp(&input_ln->data[i],"./", 2) && !quotes)
				// {
				// 	new_data = ft_substr(input_ln->data, 0, i);
				// 	new_data = ft_strjoin(new_data, ft_strdup(getcwd(NULL, 0)));
				// 	new_data = ft_strjoin_get(new_data, &input_ln->data[i + 1]);
				// 	input_ln->data = new_data;
				// }
				i++;
			}
		}
		// if (!input_ln->next)
		// 	printf("%s\n", input_ln->data);
		input_ln = input_ln->next;
	}
}
