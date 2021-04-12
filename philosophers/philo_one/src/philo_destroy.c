/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:25:42 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/12 15:43:30 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

static	void	ft_free(t_philo *philo)
{
	if (philo)
	{
		free(philo->philo_mutex);
		free(philo->content.msg_mutex);
		free(philo->content.die_mutex);
		free(philo->content.fork_mutex);
		free(philo);
	}
}

void	destroy_env(t_philo *philo)
{
	if (philo)
	{
		pthread_mutex_destroy(philo->philo_mutex);
		pthread_mutex_destroy(philo->content.msg_mutex);
		pthread_mutex_destroy(philo->content.die_mutex);
		pthread_mutex_destroy(philo->content.fork_mutex);
	}
	ft_free(philo);
}
