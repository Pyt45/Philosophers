/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:14:36 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/11 16:28:05 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

void	parent_process(t_philo *philo)
{
	int		i;

	i = -1;
	while (++i < philo->content.n_philo)
		waitpid(philo[i].pid, NULL, 0);
}

void	run_child_process(t_philo *philo)
{
	philo->content.s_start = get_time();
	philo->t_limit = philo->content.s_start + philo->content.time_to_die;
	if (pthread_create(&philo->content.philo_health, NULL, check_health, (void *)philo))
		return ;
	if (pthread_detach(philo->content.philo_health))
		return ;
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
}

void	start_simulation(t_philo *philo)
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
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			run_child_process(&philo[i]);
			exit(0);
		}
		else if (philo[i].pid < 0)
			break ;
		// else
		// 	parent_process(philo);
		// // break;
	}
	i = -1;
	while (++i < philo->content.n_philo)
		waitpid(philo[i].pid, NULL, 0);
	i = -1;
	while (++i < philo->content.n_philo)
		kill(philo[i].pid, SIGKILL);
	sem_wait(philo->content.die_sem);
	sem_post(philo->content.die_sem);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = NULL;
	philo = ft_HandleData(philo, argv, argc);
	if (!philo)
		return (-1);
	// create_philo(philo);
	start_simulation(philo);
	return (0);
}
