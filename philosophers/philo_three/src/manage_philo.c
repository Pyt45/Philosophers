/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:57:24 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/11 16:48:49 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

void	*check_health(void *arg)
{
	t_philo *checker;
	checker = (t_philo *)arg;
	while (1)
	{
		sem_wait(checker->philo_sem);
		if (get_time() > checker->t_limit)
		{
			sem_wait(checker->content.msg_sem);
			printf("%ld\t%d died\n",get_time() - checker->content.s_start, checker->id + 1);
			sem_post(checker->philo_sem);
			sem_post(checker->content.die_sem);
			return (NULL);
		}
		sem_post(checker->philo_sem);
		usleep(1000);
	}
	return NULL;
}

void	*count_eating_times(void *arg)
{
	t_philo *checker;
	int 	i;

	checker = (t_philo *)arg;
	i = 0;
	while (1)
	{
		if (checker->content.done == checker->num_of_philo)
		{
			sem_wait(checker->content.msg_sem);
			printf("%ld\treached the limit of eats\n", get_time() - checker->content.start);
			sem_post(checker->content.die_sem);
		}
	}
	return (NULL);
}


void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->content.s_start = get_time();
	philo->t_limit = philo->content.s_start + philo->content.time_to_die;
	if (pthread_create(&philo->content.philo_health, NULL, check_health, arg))
		return (NULL);
	if (pthread_detach(philo->content.philo_health))
		return (NULL);
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

void 	create_philo(t_philo *philo)
{
	int		i;

	i = -1;
	sem_wait(philo->content.die_sem);
	if (philo->content.num_of_eat)
	{
		pthread_create(&philo->content.eat_thread, NULL, count_eating_times, (void *)philo);
		pthread_detach(philo->content.eat_thread);
	}
	while (++i < philo->content.n_philo)
	{
		philo->index_p = i;
		pthread_create(&philo[i].thread, NULL, ft_routine, (void *)&philo[i]);
		pthread_detach(philo[i].thread);
		usleep(100);
	}
	sem_wait(philo->content.die_sem);
	sem_post(philo->content.die_sem);
}
