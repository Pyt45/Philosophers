/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:14:36 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/12 12:35:36 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_three.h"

void	run_child_process(t_philo *philo)
{
	philo->content.s_start = get_time();
	philo->t_limit = philo->content.s_start + philo->content.time_to_die;
	pthread_create(&philo->content.philo_health, NULL, check_health, (void *)philo);
	pthread_detach(philo->content.philo_health);
	while (1)
	{
		take_fork(philo);
		eat_action(philo);
		release_fork(philo);
		sleep_action(philo);
		think_action(philo);
		if (philo->content.e_eat == 0)
		{
			sem_post(philo->eat_count_sem);
			break ;
		}
	}
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = NULL;
	philo = ft_HandleData(philo, argv, argc);
	if (!philo)
		return (-1);
	start_simulation(philo);
	return (0);
}
