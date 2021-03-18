/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:14:36 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/03/18 16:39:02 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

t_thread	*new_thread(int num_philo, t_content *content)
{
	t_thread 	*l_thread;

	if (!(l_thread = (t_thread *)malloc(sizeof(t_thread))))
		return (NULL);
	l_thread->num_of_philo = num_philo;
	l_thread->content.time_to_die = content->time_to_die;
	l_thread->content.time_to_eat = content->time_to_eat;
	l_thread->content.time_to_sleep = content->time_to_sleep;
	l_thread->thread = (pthread_t *)malloc(sizeof(pthread_t) * l_thread->num_of_philo);
	// thread->next = NULL;
	// thread->prev = prev;
	// if (prev)
	// 	prev->next = thread;
	return (l_thread);
}

void	print_content(t_thread *l_thread)
{
	t_thread 	*tmp;
	int			i;

	tmp = l_thread;
	i = 0;
	// while (tmp->next)
	// {
		printf("--> num = %d t_die = %d t_eat = %d t_sleep = %d\n",
		tmp->num_of_philo,
		tmp->content.time_to_die,
		tmp->content.time_to_eat,
		tmp->content.time_to_sleep);
	// 	tmp = tmp->next;
	// 	i++;
	// }
}

t_thread	*create_threads(t_content *content, int num_philo, t_thread *l_thread)
{
	int			i;
	t_thread	*tmp;
	// t_thread	*head;
	
	// head = NULL;
	i = -1;
	tmp = l_thread;
	// while (++i < num_philo)
	// {
		tmp = new_thread(num_philo, content);
	// 	if (!head)
	// 		head = tmp;
	// }
	// head->prev = tmp;
	// tmp->next = head;
	return (tmp);
}

void 	*philosopher(void *arg)
{
	int *i = (int *)arg;
	int right = *i;
	int left = (*i + 1) % g_philo_num;
	int locked;

	while (1) {
		pthread_mutex_lock(&g_lock);
		locked = 0;
		while (!locked) {
			// pthread_mutex_lock(&g_lock);
			if (g_forks[right] || g_forks[left])
			{
				pthread_mutex_unlock(&g_lock);
				usleep(100000000);
				continue ;
			}
			g_forks[right] = 1;
			g_forks[left] = 1;

			pthread_mutex_unlock(&g_lock);
			locked = 1;
		}
		printf("philosopher %d took both forks. Now Eating\n", *i);
		usleep(100000000);
		printf("philosopher %d done Eating. Giving up forks\n", *i);
		g_forks[right] = 0;
		g_forks[left] = 0;
		pthread_mutex_unlock(&g_lock);
		usleep(100000000);
	}
	return NULL;
}

void	create_philos(t_thread *l_thread)
{
	g_action = EAT_ACTION;
	int i = 0;
	while (i < l_thread->num_of_philo)
	{
		pthread_create(&l_thread->thread[i], NULL, philosopher, (void *)&i);
		i++;
	}
	i = -1;
	while (++i < l_thread->num_of_philo)
		pthread_join(l_thread->thread[i], NULL);
	return ;
}

int		main(int argc, char **argv)
{
	pthread_mutex_init(&g_lock, NULL);
	t_thread 	*l_thread;
	t_content	content;
	int			num_philo;
	g_action = 0;

	if (argc > 6 || argc < 4)
	{
		printf("Error occured!\n");
		return 0;
	}
	l_thread = NULL;
	num_philo = ft_atoi(argv[1]);
	content.time_to_die = ft_atoi(argv[2]);
	content.time_to_eat = ft_atoi(argv[3]);
	content.time_to_sleep = ft_atoi(argv[4]);
	content.num_of_eat = (argc == 6) ? ft_atoi(argv[5]) : 0;
	g_forks = (int *)malloc(sizeof(int) * num_philo);
	g_philo_num = num_philo;
	for (int i = 0; i < num_philo; i++)
		g_forks[i] = 0;
	l_thread = create_threads(&content, num_philo, l_thread);
	// print_content(l_thread);
	// printf("%d\n", l_thread->num_of_philo);
	create_philos(l_thread);
	pthread_mutex_destroy(&g_lock);
	return (0);	
}
