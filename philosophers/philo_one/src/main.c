/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:14:36 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/03/19 12:27:02 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"


t_thread	*new_thread(int num_philo, t_content *content)
{
	t_thread 	*l_thread;

	if (!(l_thread = (t_thread *)malloc(sizeof(t_thread))))
		return (NULL);
	l_thread->id = 0;
	l_thread->num_of_philo = num_philo;
	// l_thread->content.time_to_die = content->time_to_die;
	// l_thread->content.time_to_eat = content->time_to_eat;
	// l_thread->content.time_to_sleep = content->time_to_sleep;
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
	// i = -1;
	// tmp = l_thread;
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
	t_thread *tmp = arg;
	// printf("%d\n", tmp->id);
	int right = tmp->id;
	int left = (tmp->id + 1) % tmp->num_of_philo;
	int locked;

	while (1) {
		// pthread_mutex_lock(&g_lock);
		locked = 0;
		while (!locked) {
			pthread_mutex_lock(&p_lock[right]);
			// printf("Philo %d has take a right fork\n", right);
			// pthread_mutex_lock(&p_lock[left]);
			// printf("Philo %d has take a left fork\n", right);
			if (g_forks[right] || g_forks[left])
			{
				pthread_mutex_unlock(&p_lock[right]);
				// pthread_mutex_unlock(&p_lock[left]);
				usleep(100000);
				continue ;
			}
			g_forks[right] = 1;
			g_forks[left] = 1;

			pthread_mutex_unlock(&p_lock[right]);
			// pthread_mutex_unlock(&p_lock[left]);
			locked = 1;
		}
		printf("philosopher %d took both forks. Now Eating\n", tmp->id);
		usleep(100000);
		printf("philosopher %d done Eating. Giving up forks\n", tmp->id);
		g_forks[right] = 0;
		g_forks[left] = 0;
		pthread_mutex_unlock(&p_lock[right]);
		// pthread_mutex_unlock(&p_lock[left]);
		usleep(100000);
	}
	return NULL;
}

void	create_philos(t_content *content, int num_philo)
{
	// g_action = EAT_ACTION;
	t_thread *l_thread = new_thread(num_philo, content);
	int i = -1;

	while (++i < l_thread->num_of_philo)
	{
		l_thread->id = i;
		pthread_create(&l_thread->thread[i], NULL, philosopher, &l_thread[i]);
		// usleep(10);
	}
	i = -1;
	while (++i < l_thread->num_of_philo)
		pthread_join(l_thread->thread[i], NULL);
	return ;
}

int		is_valid(t_thread *l_thread)
{
	return 1;
}

void	check_data(t_thread *l_thread)
{
	if (l_thread->num_of_philo < 2 || l_thread->content.time_to_eat < 60
	|| l_thread->content.time_to_die < 60 || l_thread->content.time_to_sleep < 60)
	{
		printf("Error Out of Range\n");
		return ;
	}
	else if (!is_valid(l_thread))
	{
		printf("Error arg must be number\n");
		return ;
	}
	return ;
}

int		main(int argc, char **argv)
{
	// pthread_mutex_init(&g_lock, NULL);
	// t_thread 	l_thread;
	t_content	content;
	int			num_philo;
	// g_action = 0;

	if (argc > 6 || argc < 4)
	{
		printf("Error occured!\n");
		return 0;
	}
	// t_die <= 60 || t_eat <= 60 | t_sleep <= 
	// l_thread = NULL;
	num_philo = ft_atoi(argv[1]);
	content.time_to_die = ft_atoi(argv[2]);
	content.time_to_eat = ft_atoi(argv[3]);
	content.time_to_sleep = ft_atoi(argv[4]);
	content.num_of_eat = (argc == 6) ? ft_atoi(argv[5]) : 0;
	g_forks = (int *)malloc(sizeof(int) * num_philo);
	p_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num_philo);
	// g_philo_num = num_philo;
	int j = -1;
	while (++j < num_philo)
		pthread_mutex_init(&p_lock[j], NULL);
	// l_thread = create_threads(&content, num_philo, l_thread);
	// print_content(l_thread);
	// printf("%d\n", l_thread->num_of_philo);
	create_philos(&content, num_philo);
	// pthread_mutex_destroy(&g_lock);
	return (0);	
}
