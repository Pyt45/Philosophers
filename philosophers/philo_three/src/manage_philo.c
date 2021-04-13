/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:57:24 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/13 16:32:34 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_three.h"

void	*check_health(void *arg)
{
	t_philo	*checker;
	long	t;

	checker = (t_philo *)arg;
	while (1)
	{
		sem_wait(checker->philo_sem);
		if (!checker->content.is_eating
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
	int		n;

	checker = (t_philo *)arg;
	n = checker->content.n_philo;
	i = 0;
	while (1)
	{
		sem_wait(checker[i].eat_count_sem);
		i++;
		if (i == n)
			break ;
	}
	sem_wait(checker->content.msg_sem);
	printf("%ld\t%s\n", get_time() - checker->content.start, END_EAT);
	sem_post(checker->content.die_sem);
	return (NULL);
}

void	start_simulation(t_philo *philo)
{
	int		i;

	i = -1;
	if (philo->content.num_of_eat > 0)
	{
		pthread_create(&philo->content.e_th, NULL, check_count, (void *)philo);
		pthread_detach(philo->content.e_th);
	}
	sem_wait(philo->content.die_sem);
	while (++i < philo->content.n_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			run_child_process(&philo[i]);
			exit(0);
		}
		else if (philo[i].pid < 0)
			break ;
	}
	sem_wait(philo->content.die_sem);
	sem_post(philo->content.die_sem);
	i = -1;
	while (++i < philo->content.n_philo)
		kill(philo[i].pid, SIGKILL);
}
