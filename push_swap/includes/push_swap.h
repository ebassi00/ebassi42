/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:38:48 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/15 18:23:57 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

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
void	fill_args(t_game *game, char *argv[], int argc);
int		*fill_args_char(int *tmp_arr, char *argv[], int argc);
void	change_nm(t_game *game, int argc, char *argv[]);
int		check_ordered(t_game *game);
void	find_smallest(t_game *game);
void	exec_swap(t_game *game, int min);
void	sort_100(t_game *game);
void	sort_500(t_game *game);
int		is_integer(char *arg);
int		check_duplicates(t_game *game);
int		check_args(int argc, char *argv[]);
void	sort_u6(t_game *game);
void	sort_others(t_game *game);
int		get_hold_second(t_game *game, int nbr_min, int nbr_max);
int		get_hold_first(int nbr_max, int nbr_min, t_game *game, int hold_first);
void	chunk_decision(int i, int j, int split, t_game *game);
void	free_all(t_game *game);

#endif