/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:25:36 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/13 15:17:58 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

t_content	init_content(t_content cont)
{
	t_content	c;

	c = cont;
	c.start = get_time();
	c.msg_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	c.die_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	c.fork_mutex = malloc(sizeof(pthread_mutex_t) * c.n_philo);
	pthread_mutex_init(c.die_mutex, NULL);
	pthread_mutex_init(c.msg_mutex, NULL);
	return (c);
}

t_philo	*init_mutex(t_philo *philo, t_content cont)
{
	int			i;
	t_content	content;

	i = -1;
	content = init_content(cont);
	philo = (t_philo *)malloc(sizeof(t_philo) * content.n_philo);
	if (!philo)
		return (NULL);
	while (++i < content.n_philo)
	{
		philo[i].philo_mutex = malloc(sizeof(pthread_mutex_t));
		if (!philo[i].philo_mutex)
			return (NULL);
		philo[i].content = content;
		philo[i].id = i;
		philo[i].content.done = 0;
		philo[i].content.is_eating = 0;
		philo[i].content.e_c = content.num_of_eat;
		philo[i].r_fork = i;
		philo[i].l_fork = (i + 1) % content.n_philo;
		pthread_mutex_init(philo[i].philo_mutex, NULL);
		pthread_mutex_init(&philo[i].content.fork_mutex[i], NULL);
	}
	return (philo);
}

void	print_status(long t, char *msg, t_philo *philo, int bl)
{
	pthread_mutex_lock(philo->content.msg_mutex);
	printf("%ld\t%d%s\n", t, philo->id + 1, msg);
	if (bl)
		pthread_mutex_unlock(philo->content.msg_mutex);
}
