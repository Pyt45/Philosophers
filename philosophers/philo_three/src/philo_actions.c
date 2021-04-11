/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:30:17 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/11 22:08:38 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

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
	philo->is_eating = 1;
	printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, EAT);
	/*int 	doneeat = philo->content.done;
	sem_t  donee = sem_post()
	sem_unlink(ft_itoa(philo))
	sem_wait(&doneeat);*/
	if (philo->content.num_of_eat)
	{
		philo->content.reached_count++;
		philo->content.num_of_eat--;
		if (philo->content.reached_count == philo->content.e_eat)
		{
			philo->content.done++;
			// g_must_eat += 1;
		}
	}
	// sem_post(&doneeat);
	// printf("r = %d\n", philo->content.done);
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
