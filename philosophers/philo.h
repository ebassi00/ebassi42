/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:22:35 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/16 16:11:14 by ebassi           ###   ########.fr       */
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
	int			id_philo;
	int			eat;
	int			sleep;
	int			die;
	pthread_t	phil_thread;
}	t_philo;

typedef struct s_table {
	t_philo	*phil;
	int		forks;
}	t_table;

int		ft_exit(char *str);
int		ft_atoi(char *str);
int		is_integer(char *arg);
t_table	*create_thread(t_table *table, char *argv[]);

#endif