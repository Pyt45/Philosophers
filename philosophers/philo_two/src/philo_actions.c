/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:30:17 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/13 15:55:55 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

void	take_fork(t_philo *philo)
{
	long	t;

	if (sem_wait(philo->content.fork_sem) < 0)
		return ;
	t = get_time() - philo->content.start;
	print_status(t, TAKE_FORK, philo, 1);
	if (sem_wait(philo->content.fork_sem) < 0)
		return ;
	t = get_time() - philo->content.start;
	print_status(t, TAKE_FORK, philo, 1);
}

void	release_fork(t_philo *philo)
{
	sem_post(philo->content.fork_sem);
	sem_post(philo->content.fork_sem);
}

void	eat_action(t_philo *philo)
{
	long	t;

	if (sem_wait(philo->philo_sem) < 0)
		return ;
	philo->content.is_eating = 1;
	philo->content.s_start = get_time();
	philo->t_limit = philo->content.s_start + philo->content.time_to_die;
	t = get_time() - philo->content.start;
	print_status(t, EAT, philo, 1);
	usleep(1000 * philo->content.time_to_eat);
	if (philo->content.e_c != 0)
		philo->content.e_c--;
	philo->content.is_eating = 0;
	sem_post(philo->philo_sem);
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
