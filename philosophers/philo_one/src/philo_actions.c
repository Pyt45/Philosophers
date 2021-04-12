/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:30:17 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/12 16:40:04 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

void	take_fork(t_philo *philo)
{
	long	t;

	pthread_mutex_lock(&philo->content.fork_mutex[philo->r_fork]);
	t = get_time() - philo->content.start;
	print_status(t, TAKE_FORK, philo, 1);
	pthread_mutex_lock(&philo->content.fork_mutex[philo->l_fork]);
	t = get_time() - philo->content.start;
	print_status(t, TAKE_FORK, philo, 1);
}

void	release_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->content.fork_mutex[philo->r_fork]);
	pthread_mutex_unlock(&philo->content.fork_mutex[philo->l_fork]);
}

void	eat_action(t_philo *philo)
{
	long	t;

	pthread_mutex_lock(philo->philo_mutex);
	philo->content.s_start = get_time();
	philo->t_limit = philo->content.s_start + philo->content.time_to_die;
	t = get_time() - philo->content.start;
	print_status(t, EAT, philo, 1);
	if (philo->content.num_of_eat)
	{
		philo->content.reached_count++;
		philo->content.num_of_eat--;
		if (philo->content.reached_count == philo->content.e_eat)
			g_must_eat += 1;
	}
	usleep(1000 * philo->content.time_to_eat);
	pthread_mutex_unlock(philo->philo_mutex);
}

void	think_action(t_philo *philo)
{
	long	t;

	t = get_time() - philo->content.start;
	print_status(t, THINK, philo, 1);
}

void	sleep_action(t_philo *philo)
{
	long	t;

	t = get_time() - philo->content.start;
	print_status(t, SLEEP, philo, 1);
	usleep(1000 * philo->content.time_to_sleep);
}
