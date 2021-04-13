/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:57:24 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/13 15:18:42 by aaqlzim          ###   ########.fr       */
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
		if (!checker->content.done && !checker->content.is_eating
			&& get_time() > checker->t_limit)
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
	int		num;

	checker = (t_philo *)arg;
	i = 0;
	num = 0;
	while (1)
	{
		if (i == checker->content.n_philo)
			i = 0;
		if (checker[i].content.done == 1
			&& checker[i].content.e_c == 0)
		{
			num++;
			checker[i].content.e_c = -1;
		}
		if (num == checker->content.n_philo)
			break ;
		i++;
	}
	pthread_mutex_lock(checker->content.msg_mutex);
	printf("%ld\t%s\n", get_time() - checker->content.start, END_EAT);
	pthread_mutex_unlock(checker->content.die_mutex);
	return (NULL);
}
