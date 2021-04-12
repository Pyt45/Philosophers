/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:30:17 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/12 12:33:01 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_three.h"

void	take_fork(t_philo *philo)
{
	sem_wait(philo->content.fork_sem);
	sem_wait(philo->content.msg_sem);
	printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, TAKE_FORK);
	sem_post(philo->content.msg_sem);
	sem_wait(philo->content.fork_sem);
	sem_wait(philo->content.msg_sem);
	printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, TAKE_FORK);
	sem_post(philo->content.msg_sem);
}

void	release_fork(t_philo *philo)
{
	sem_post(philo->content.fork_sem);
	sem_post(philo->content.fork_sem);
}

void	eat_action(t_philo *philo)
{
	sem_wait(philo->philo_sem);
	philo->content.s_start = get_time();
	philo->t_limit = philo->content.s_start + philo->content.time_to_die;
	sem_wait(philo->content.msg_sem);
	printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, EAT);
	if (philo->content.num_of_eat != -1)
		philo->content.e_eat--;
	sem_post(philo->content.msg_sem);
	usleep(1000 * philo->content.time_to_eat);
	sem_post(philo->philo_sem);
}

void	think_action(t_philo *philo)
{
	sem_wait(philo->content.msg_sem);
	printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, THINK);
	sem_post(philo->content.msg_sem);
}

void	sleep_action(t_philo *philo)
{
	sem_wait(philo->content.msg_sem);
	printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, SLEEP);
	sem_post(philo->content.msg_sem);
	usleep(1000 * philo->content.time_to_sleep);
}
