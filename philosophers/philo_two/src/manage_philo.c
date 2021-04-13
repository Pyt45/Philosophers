/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:57:24 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/13 16:33:35 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

void	*check_health(void *arg)
{
	t_philo	*checker;
	long	t;

	checker = (t_philo *)arg;
	while (1)
	{
		if (sem_wait(checker->philo_sem) < 0)
			return (NULL);
		if (!checker->content.done && !checker->content.is_eating
			&& get_time() > checker->t_limit)
		{
			t = get_time() - checker->content.s_start;
			print_status(t, DIED, checker, 0);
			sem_post(checker->philo_sem);
			sem_post(checker->content.die_sem);
			return (NULL);
		}
		sem_post(checker->philo_sem);
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
	sem_wait(checker->content.msg_sem);
	printf("%ld\t%s\n", get_time() - checker->content.start, END_EAT);
	sem_post(checker->content.die_sem);
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
		if (philo->content.e_c == 0)
		{
			philo->content.done = 1;
			break ;
		}
	}
	return (NULL);
}

void 	create_philo(t_philo *philo)
{
	int		i;

	i = -1;
	if (philo->content.e_c > 0)
	{
		pthread_create(&philo->content.e_th, NULL, check_count, (void *)philo);
		pthread_detach(philo->content.e_th);
	}
	if (sem_wait(philo->content.die_sem) < 0)
		return ;
	while (++i < philo->content.n_philo)
	{
		pthread_create(&philo[i].thread, NULL, ft_routine, (void *)&philo[i]);
		pthread_detach(philo[i].thread);
		usleep(100);
	}
	if (sem_wait(philo->content.die_sem) < 0)
		return ;
	sem_post(philo->content.die_sem);
}
