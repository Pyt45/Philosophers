/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:57:24 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/12 15:22:56 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

void	*check_health(void *arg)
{
	t_philo	*checker;
	long	t;

	checker = (t_philo *)arg;
	while (1)
	{
		if (pthread_mutex_lock(checker->philo_mutex))
			return (NULL);
		if (get_time() > checker->t_limit)
		{
			t = get_time() - checker->content.s_start;
			print_status(t, DIED, checker, 0);
			if (pthread_mutex_unlock(checker->philo_mutex))
				return (NULL);
			if (pthread_mutex_unlock(checker->content.die_mutex))
				return (NULL);
			return (NULL);
		}
		if (pthread_mutex_unlock(checker->philo_mutex))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

void	*check_count(void *arg)
{
	t_philo	*checker;
	int		i;

	checker = (t_philo *)arg;
	i = 0;
	while (1)
	{
		if (g_must_eat == checker->num_of_philo)
		{
			pthread_mutex_lock(checker->content.msg_mutex);
			printf("%ld\t%s\n", get_time() - checker->content.start, END_EAT);
			pthread_mutex_unlock(checker->content.die_mutex);
		}
	}
	return (NULL);
}
