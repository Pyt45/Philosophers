/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:25:42 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/10 11:27:57 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

void	destroy_mutex(t_philo *philo)
{
	int 	i;

	i = 0;
	if (philo)
	{
		pthread_mutex_destroy(philo->philo_mutex);
		pthread_mutex_destroy(philo->content.msg_mutex);
		pthread_mutex_destroy(philo->content.die_mutex);
		while (i++ < philo->content.n_philo)
			pthread_mutex_destroy(philo->content.fork_mutex[i]);
	}
}