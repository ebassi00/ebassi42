/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:54:34 by mpatrini          #+#    #+#             */
/*   Updated: 2022/06/13 18:30:11 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    get_command(t_tok *input_ln, char *line, char **env)
{
    int     i;
    int     j;
    int     quotes;
    t_tok   *copy;
    char    *tmp;
    i = 0;
    j = 0;
    quotes = 0;
    copy = input_ln;
    input_ln->data = 0;
    input_ln->id = 0;
    while (line[i] && line[i] == ' ')
        i++;
    copy = input_ln;
    while (line[i])
    {
        quotes = qquotes(line[i], quotes);
        if ((line[i] == '|' || line[i] == '>' || line[i] == '<' || \
            (line[i] == '&' && line[i + 1] == '&')) && !quotes)
        {
            if (i != 0)
            {
                get_next_lst(input_ln);
                input_ln = input_ln->next;
                input_ln->data = 0;
            }
            if (line[i] == line[i + 1])
            {
                tmp = ft_substr(line, i, 2);
                handle_op(input_ln, tmp);
                get_next_lst(input_ln);
                input_ln = input_ln->next;
                input_ln->data = 0;
                j = i + 2;
                i++;
            }
            else
            {
                tmp = ft_substr(line, i, 1);
                handle_op(input_ln, tmp);
                get_next_lst(input_ln);
                input_ln = input_ln->next;
                input_ln->data = 0;
                j = i + 1;
            }
            // free(tmp);
        }
        input_ln->type = 0;
        // if (input_ln->data)
        //     free(input_ln->data);
        tmp = ft_substr(line, j, i - j + 1);
        // input_ln->data = tmp;
        // tmp = input_ln->data;
        input_ln->data = ft_strtrim(tmp, " ");
        free(tmp);
        input_ln->exit = 0;
        i++;
    }
    input_ln->next = 0;
    // printf("%s\n", input_ln->data);
    expand_envars(copy, env);
}
