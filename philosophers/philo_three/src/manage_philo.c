/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:57:24 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/12 12:35:38 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_three.h"

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
	int		n = checker->content.n_philo;
	i = 0;
	while (1)
	{
		sem_wait(checker[i].eat_count_sem);
		i++;
		if (i == n)
			break;			
	}
	sem_wait(checker->content.msg_sem);
	printf("%ld\treached the limit of eats\n", get_time() - checker->content.start);
	sem_post(checker->content.die_sem);
	return (NULL);
}

void	start_simulation(t_philo *philo)
{
	int		i;

	i = -1;
	sem_wait(philo->content.die_sem);
	if (philo->content.num_of_eat > 0)
	{
		pthread_create(&philo->content.eat_thread, NULL, count_eating_times, (void *)philo);
		pthread_detach(philo->content.eat_thread);
	}
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
	// i = -1;
	// while (++i < philo->content.n_philo)
	// 	waitpid(philo[i].pid, NULL, 0);
	sem_wait(philo->content.die_sem);
	sem_post(philo->content.die_sem);
	i = -1;
	while (++i < philo->content.n_philo)
		kill(philo[i].pid, SIGKILL);
}