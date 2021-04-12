/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:25:42 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/12 17:58:12 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

void	destroy_philo(t_philo *philo)
{
	int		i;

	i = 0;
	if (philo)
	{
		sem_post(philo->content.msg_sem);
		sem_close(philo->content.msg_sem);
		// sem_post(philo->content.die_sem);
		// sem_close(philo->content.die_sem);
		sem_post(philo->content.eat_sem);
		sem_close(philo->content.eat_sem);
		sem_post(philo->philo_sem);
		sem_close(philo->philo_sem);
		while (i++ < philo->content.n_philo)
			sem_post(philo[i].content.fork_sem);
		// i = 0;
		// while (i++ < philo->content.n_philo)
		// 	sem_close(philo[i].content.fork_sem);
		sem_close(philo->content.fork_sem);
		free(philo);
	}
}
