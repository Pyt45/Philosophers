/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:52:51 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/03/19 12:28:09 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

unsigned int get_time_of_excute(t_thread *l_thread)
{
	return ((l_thread->end.tv_sec * 1000 + (l_thread->end.tv_usec / 1000)) -
	(l_thread->start.tv_sec * 1000 + (l_thread->start.tv_usec / 1000)));
}

// void	*try_this(void *arg)
// {
// 	pthread_mutex_lock(&g_lock);

// 	unsigned long i = 0;
// 	g_forks += 1;
// 	printf("\nJob %d has started\n", g_forks);
// 	sleep(1);
// 	printf("\nJob %d has finished\n", g_forks);
// 	pthread_mutex_unlock(&g_lock);
// 	// pthread_mutex_destroy(&g_lock);
// 	return (NULL);
// }

void	*philo_life(void *arg)
{
	// pthread_mutex_lock(&g_lock);
	int		life;
	int *myId = (int *)arg;

	life = 1;
	// while (life)
	// {
		// life = is_do_action(g_action);
		// if (life == -1)
		// 	break ;
		printf("%d\n", *myId);
		sleep(1);
	// }
	// pthread_mutex_unlock(&g_lock);
	return (NULL);
}

void	create_philo(t_thread *l_thread)
{
	int			i;
	i = -1;
	// g_forks = 2;
	// g_action = 2;
	// pthread_mutex_init(&g_lock, NULL);
	while (++i < l_thread->num_of_philo)
	{
		pthread_create(&l_thread->thread[i], NULL, philo_life, (void *)&l_thread->thread[i]);
		// l_thread = l_thread->next;
	}
	i = -1;
	while (++i < l_thread->num_of_philo)
		pthread_join(l_thread->thread[i], NULL);
	// pthread_mutex_destroy(&g_lock);
	pthread_exit(NULL);
}