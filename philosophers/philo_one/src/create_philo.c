/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:52:51 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/12 14:09:21 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->content.s_start = get_time();
	philo->t_limit = philo->content.s_start + philo->content.time_to_die;
	pthread_create(&philo->content.philo_health, NULL, check_health, arg);
	pthread_detach(philo->content.philo_health);
	while (1)
	{
		take_fork(philo);
		eat_action(philo);
		release_fork(philo);
		sleep_action(philo);
		think_action(philo);
		if (philo->content.e_eat)
		{
			if (philo->content.reached_count == philo->content.e_eat)
				break ;
		}
	}
	return (NULL);
}

void	create_philo(t_philo *philo)
{
	int		i;

	i = -1;
	pthread_mutex_lock(philo->content.die_mutex);
	if (philo->content.num_of_eat)
	{
		pthread_create(&philo->content.eat_th, NULL, check_count, philo);
		pthread_detach(philo->content.eat_th);
	}
	while (++i < philo->content.n_philo)
	{
		pthread_create(&philo[i].thread, NULL, routine, (void *)&philo[i]);
		pthread_detach(philo[i].thread);
		usleep(100);
	}
	pthread_mutex_lock(philo->content.die_mutex);
	pthread_mutex_unlock(philo->content.die_mutex);
}
