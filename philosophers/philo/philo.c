/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:21:56 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/23 18:39:07 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_args(char *arg)
{
	if (!is_integer(arg))
		return (0);
	return (1);
}

// void	*is_dead(void *data)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *) data;
// 	pthread_mutex_lock(&philo->table->finish);
// 	if (philo->table->nbr_phil_finish == philo->table->nbr_philo)
// 	{
// 		pthread_mutex_unlock(&philo->table->finish);
// 		philo->table->exec_finish = 1;
// 		return (NULL);
// 	}
// 	if ((get_time() - philo->table->time) - philo->last_meal >= philo->table->die)
// 	{
// 		pthread_mutex_lock(&philo->table->death);
// 		pthread_mutex_unlock(&philo->table->finish);
// 		pthread_mutex_lock(&philo->table->message);
// 		printf("[%llu] %d died\n", get_time() - philo->table->time, philo->id_philo);
// 		philo->table->is_dead = 1;
// 		return (NULL);
// 	}
// 	pthread_mutex_unlock(&philo->table->finish);
// 	return (NULL);
// }

void	*monitoring(void *data)
{
	t_table	*table;
	int		i;

	i = 0;
	table = (t_table *) data;
	while (!table->is_dead)
	{
		i = -1;
		while (++i < table->nbr_philo)
		{
			if (table->nbr_phil_finish == table->nbr_philo)
			{
				// pthread_mutex_unlock(&table->finish);
				table->is_dead = 1;
				return (NULL);
			}
			if ((get_time() - table->time) - table->phil[i]->last_meal >= table->die && !table->phil[i]->philo_eating)
			{
				// printf("last_meal: %llu\n", table->phil[i]->last_meal);
				pthread_mutex_lock(&table->death);
				// pthread_mutex_unlock(&table->finish);
				pthread_mutex_lock(&table->message);
				printf("[%llu] %d died\n", get_time() - table->time, table->phil[i]->id_philo);
				table->is_dead = 1;
				return (NULL);
			}
		}
	}
	return (NULL);
}

void	*func(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	while (!philo->table->is_dead)
	{
		// if (pthread_mutex_lock(&philo->table->forks[philo->id_philo - 1]) == 0 && pthread_mutex_lock(&philo->table->forks[(philo->id_philo) % philo->table->nbr_philo]) == 0)
		// {
		pthread_mutex_lock(&philo->table->forks[philo->id_philo - 1]);
		pthread_mutex_lock(&philo->table->message);
		printf("[%llu] %d has taken a fork\n", get_time() - philo->table->time, philo->id_philo);
		pthread_mutex_unlock(&philo->table->message);
		pthread_mutex_lock(&philo->table->forks[(philo->id_philo) % philo->table->nbr_philo]);
		pthread_mutex_lock(&philo->table->message);
		printf("[%llu] %d has taken a fork\n", get_time() - philo->table->time, philo->id_philo);
		pthread_mutex_unlock(&philo->table->message);
		philo->philo_eating = 1;
		pthread_mutex_lock(&philo->table->message);
		printf("[%llu] %d is eating\n", get_time() - philo->table->time, philo->id_philo);
		pthread_mutex_unlock(&philo->table->message);
		pthread_mutex_lock(&philo->table->is_eating);
		philo->last_meal = get_time() - philo->table->time;
		philo->nbr_meals++;
		if (philo->nbr_meals == philo->table->times_to_eat)
			philo->table->nbr_phil_finish++;
		pthread_mutex_unlock(&philo->table->is_eating);
		usleep(philo->table->eat * 1000 - 20000);
		while ((get_time() - philo->table->time) - philo->last_meal < philo->table->eat)
			continue ;
		pthread_mutex_unlock(&philo->table->forks[philo->id_philo - 1]);
		pthread_mutex_unlock(&philo->table->forks[(philo->id_philo) % philo->table->nbr_philo]);
		philo->philo_eating = 0;
		pthread_mutex_lock(&philo->table->message);
		printf("[%llu] %d is sleeping\n", get_time() - philo->table->time, philo->id_philo);
		pthread_mutex_unlock(&philo->table->message);
		usleep(philo->table->sleep * 1000);
		while ((get_time() - philo->table->time) - philo->last_meal < philo->table->sleep)
			continue ;
		pthread_mutex_lock(&philo->table->message);
		printf("[%llu] %d is thinking\n", get_time() - philo->table->time, philo->id_philo);
		pthread_mutex_unlock(&philo->table->message);
		// }
	}
	return (NULL);
}

void	ft_go(t_table *table)
{
	int	i;

	i = 0;
	while (!table->is_dead)
	{
		while (i < table->nbr_philo)
		{
			pthread_create(&table->phil[i]->phil_thread, NULL, func, (void *)table->phil[i]);
			i++;
			usleep(100);
		}
	}
}

int	check_arguments(char *argv[])
{
	int	i;

	i = 0;
	if (ft_atoi(argv[0]) < 1 || ft_atoi(argv[0]) > 2147483647)
		return (0);
	if (ft_atoi(argv[1]) < 60 || ft_atoi(argv[2]) < 60)
		return (0);
	if (ft_atoi(argv[3]) < 60)
		return (0);
	if (argv[4])
	{
		if (ft_atoi(argv[4]) <= 0)
			return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_table	*table;
	pthread_t thread;
	int		i;

	i = 1;
	table = 0;
	if (argc < 4 || argc > 6)
		return (ft_exit("Wrong number of arguments"));
	if (!check_arguments(&argv[1]))
		return (ft_exit("Wrong arguments"));
	table = alloc_table(table, argv);
	i = -1;
	while (++i < table->nbr_philo)
		pthread_mutex_init(&table->forks[i], NULL);
	pthread_create(&thread, NULL, monitoring, table);
	ft_go(table);
	i = 0;
	/*while (!table->is_dead && !table->exec_finish)
	{
		i = 0;
		while (i < table->nbr_philo)
		{
			pthread_create(&table->phil[i]->check_death, NULL, is_dead, (void *)table->phil[i]);
			i++;
			usleep(100);
		}
	}*/
	return (1);
}
