/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:52:51 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/13 16:36:16 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->content.s_start = get_time();
	philo->t_limit = philo->content.s_start + philo->content.time_to_die;
	pthread_create(&philo->content.philo_health, NULL,
		check_health, (void *)philo);
	pthread_detach(philo->content.philo_health);
	while (1)
	{
		take_fork(philo);
		eat_action(philo);
		release_fork(philo);
		sleep_action(philo);
		think_action(philo);
		if (philo->content.e_c == 0)
		{
			philo->content.done = 1;
			break ;
		}
	}
	return (NULL);
}

void	create_philo(t_philo *philo)
{
	int		i;

	i = -1;
	if (philo->content.e_c > 0)
	{
		pthread_create(&philo->content.e_th, NULL, check_count, (void *)philo);
		pthread_detach(philo->content.e_th);
	}
	pthread_mutex_lock(philo->content.die_mutex);
	while (++i < philo->content.n_philo)
	{
		pthread_create(&philo[i].thread, NULL, routine, (void *)&philo[i]);
		pthread_detach(philo[i].thread);
		usleep(100);
	}
	pthread_mutex_lock(philo->content.die_mutex);
	pthread_mutex_unlock(philo->content.die_mutex);
}
