/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:56:26 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/15 18:18:37 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "push_swap.h"

int		ordered_stack(t_game *game);
int		check_args(int argc, char *argv[]);
void	handle_arg(t_game *game, char **nums, char *argv[], int i);
void	fill_args(t_game *game, char *argv[], int argc);
void	free_all2(t_game *game);
void	free_nbrs(char **nbrs);

#endif