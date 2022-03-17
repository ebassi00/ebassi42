/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:22:35 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/17 19:03:47 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

#define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo {
	int				id_philo;
	int				left_fork;
	int				right_fork;
	int				last_meal;
	struct s_table	*table;
	pthread_t	phil_thread;
}	t_philo;

typedef struct s_table {
	int				nbr_philo;
	uint64_t		eat;
	uint64_t		sleep;
	uint64_t		die;
	t_philo			**phil;
	pthread_mutex_t	*forks;
}	t_table;

int		ft_exit(char *str);
int		ft_atoi(char *str);
int		is_integer(char *arg);
t_table	*create_philo(t_table *table, char *argv[]);

#endif