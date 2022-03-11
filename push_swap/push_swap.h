/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:38:48 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/11 17:12:53 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

# define MAX(a, b) a > b ? a : b

typedef struct s_game {
	int	*stack_a;
	int	*stack_b;
	int	len_a;
	int	len_b;
}	t_game;

int		ft_exit(char *str);
void	ft_sa(t_game *game);
void	ft_sb(t_game *game);
void	ft_ss(t_game *game);
void	ft_pb(t_game *game);
void	ft_pa(t_game *game);
void	ft_ra(t_game *game);
void	ft_rb(t_game *game);
void	ft_rr(t_game *game);
void	ft_rra(t_game *game);
void	ft_rrb(t_game *game);
void	ft_rrr(t_game *game);
void	find_smallest(t_game *game);
void	exec_swap(t_game *game, int min);
void	sort_100(t_game *game);
void	sort_500(t_game *game);
int		isInteger(char *arg);
int		check_duplicates(t_game *game);
int		check_args(int argc, char *argv[]);

#endif