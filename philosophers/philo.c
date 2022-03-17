/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:21:56 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/17 19:09:08 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_args(char *arg)
{
	if (!is_integer(arg))
		return (0);
	return (1);
}

void	*func(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	pthread_mutex_lock(&philo->table->forks[philo->id_philo]);
	pthread_mutex_lock(&philo->table->forks[philo->id_philo + 1 % philo->table->nbr_philo]);
	printf("%d has taken left fork!\n", philo->id_philo);
	printf("%d has taken right fork!\n", philo->id_philo);
	pthread_mutex_unlock(&philo->table->forks[philo->id_philo]);
	pthread_mutex_unlock(&philo->table->forks[philo->id_philo + 1 % philo->table->nbr_philo]);
	printf("%d has finished eating!\n", philo->id_philo);
	return (NULL);
}

int main(int argc, char *argv[])
{
	t_table	*table;
	int		i;

	i = 1;
	table = malloc (sizeof(t_table));
	if (argc < 4 || argc > 5)
		return (ft_exit("Wrong number of arguments"));
	// if (!check_arguments(&argv[1]))
	// 	return (ft_exit("Wrong arguments"));
	table->nbr_philo = ft_atoi(argv[1]);
	table->die = ft_atoi(argv[2]);
	table->eat = ft_atoi(argv[3]);
	table->sleep = ft_atoi(argv[4]);
	table = create_philo(table, &argv[1]);
	table->forks = malloc (sizeof(pthread_mutex_t) * table->nbr_philo);
	i = -1;
	while (++i < table->nbr_philo)
		pthread_mutex_init(&table->forks[i], NULL);
	i = -1;
	while (++i < table->nbr_philo)
	{
		pthread_create(&table->phil[i]->phil_thread, NULL, func, table->phil[i]);
		usleep(100);
	}
	return (1);
}