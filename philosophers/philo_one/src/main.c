/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:14:36 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/03/20 18:03:10 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"


// t_thread	*new_thread(int num_philo, t_content *content)
// {
// 	t_thread 	*l_thread;

// 	if (!(l_thread = (t_thread *)malloc(sizeof(t_thread))))
// 		return (NULL);
// 	l_thread->id = 0;
// 	l_thread->num_of_philo = num_philo;
// 	l_thread->content.time_to_die = content->time_to_die;
// 	l_thread->content.time_to_eat = content->time_to_eat;
// 	l_thread->content.time_to_sleep = content->time_to_sleep;
// 	l_thread->thread = (pthread_t *)malloc(sizeof(pthread_t) * l_thread->num_of_philo);
// 	// thread->next = NULL;
// 	// thread->prev = prev;
// 	// if (prev)
// 	// 	prev->next = thread;
// 	return (l_thread);
// }

// void	print_content(t_thread *l_thread)
// {
// 	t_thread 	*tmp;
// 	int			i;

// 	tmp = l_thread;
// 	i = 0;
// 	// while (tmp->next)
// 	// {
// 		printf("--> num = %d t_die = %d t_eat = %d t_sleep = %d\n",
// 		tmp->num_of_philo,
// 		tmp->content.time_to_die,
// 		tmp->content.time_to_eat,
// 		tmp->content.time_to_sleep);
// 	// 	tmp = tmp->next;
// 	// 	i++;
// 	// }
// }

// t_thread	*create_threads(t_content *content, int num_philo, t_thread *l_thread)
// {
// 	int			i;
// 	t_thread	*tmp;
// 	// t_thread	*head;
	
// 	// head = NULL;
// 	// i = -1;
// 	// tmp = l_thread;
// 	// while (++i < num_philo)
// 	// {
// 		tmp = new_thread(num_philo, content);
// 	// 	if (!head)
// 	// 		head = tmp;
// 	// }
// 	// head->prev = tmp;
// 	// tmp->next = head;
// 	return (tmp);
// }

// void 	*philosopher(void *arg)
// {
// 	t_thread *philo = arg;
// 	printf("%d\n", philo->id);

// 	while (1) {
// 		pthread_mutex_lock(&p_lock[philo->r_fork]);
// 		printf("%d take right fork\n", philo->id + 1);
// 		pthread_mutex_lock(&p_lock[philo->l_fork]);
// 		printf("%d take left fork\n", philo->id + 1);
// 		pthread_mutex_lock(&eat_lock);
// 		printf("%d is eating\n", philo->id + 1);
// 		usleep(1000 * philo->content.time_to_eat);
// 		pthread_mutex_unlock(&eat_lock);
// 		pthread_mutex_unlock(&p_lock[philo->l_fork]);
// 		pthread_mutex_unlock(&p_lock[philo->r_fork]);
// 		printf("%d is sleeping\n", philo->id + 1);
// 		usleep(1000 * philo->content.time_to_sleep);
// 		printf("%d is thinking\n", philo->id + 1);
// 	}
// 	return NULL;
// }

// void	create_philos(t_content *content, int num_philo)
// {
// 	// g_action = EAT_ACTION;
// 	t_thread *l_thread = new_thread(num_philo, content);
// 	int i = -1;
// 	while (++i < l_thread->num_of_philo)
// 	{
// 		l_thread->id = i;
// 		l_thread->r_fork = i;
// 		l_thread->l_fork = (i + 1) % l_thread->num_of_philo;
// 	}
// 	i = -1;
// 	while (++i < l_thread->num_of_philo)
// 	{
// 		l_thread->id = i;
// 		l_thread->r_fork = i;
// 		l_thread->l_fork = (i + 1) % l_thread->num_of_philo;
// 		pthread_create(&l_thread->thread[i], NULL, philosopher, &l_thread[i]);
// 		// pthread_detach(l_thread->thread[i]);
// 		usleep(10);
// 	}
// 	i = -1;
// 	while (++i < l_thread->num_of_philo)
// 		pthread_join(l_thread->thread[i], NULL);
// 	return ;
// }

// int		is_valid(t_thread *l_thread)
// {
// 	return 1;
// }

// void	check_data(t_thread *l_thread)
// {
// 	if (l_thread->num_of_philo < 2 || l_thread->content.time_to_eat < 60
// 	|| l_thread->content.time_to_die < 60 || l_thread->content.time_to_sleep < 60)
// 	{
// 		printf("Error Out of Range\n");
// 		return ;
// 	}
// 	else if (!is_valid(l_thread))
// 	{
// 		printf("Error arg must be number\n");
// 		return ;
// 	}
// 	return ;
// }

// // t_die <= 60 || t_eat <= 60 | t_sleep <= 
// // l_thread = NULL;
// int		main(int argc, char **argv)
// {
// 	// pthread_mutex_init(&g_lock, NULL);
// 	// t_thread 	l_thread;
// 	t_content	content;
// 	int			num_philo;

// 	if (argc > 6 || argc < 4)
// 	{
// 		printf("Error occured!\n");
// 		return 0;
// 	}
// 	num_philo = ft_atoi(argv[1]);
// 	content.time_to_die = ft_atoi(argv[2]);
// 	content.time_to_eat = ft_atoi(argv[3]);
// 	content.time_to_sleep = ft_atoi(argv[4]);
// 	content.num_of_eat = (argc == 6) ? ft_atoi(argv[5]) : 0;
// 	g_forks = (int *)malloc(sizeof(int) * num_philo);
// 	p_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num_philo);
// 	int j = -1;
// 	while (++j < num_philo)
// 		pthread_mutex_init(&p_lock[j], NULL);
// 	// l_thread = create_threads(&content, num_philo, l_thread);
// 	// print_content(l_thread);
// 	// printf("%d\n", l_thread->num_of_philo);
// 	pthread_mutex_init(&eat_lock, NULL);
// 	create_philos(&content, num_philo);
// 	// pthread_mutex_destroy(&g_lock);
// 	return (0);	
// }

long int get_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + tv.tv_sec / 1000);
}

void	init(int n_p, int t_d, int t_e, int t_s)
{
	int 	i;

	i = -1;
	if (!(p_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 5)))
		return ;
	while (++i < n_p)
	{
		g_philo[i].num_of_philo = n_p;
		g_philo[i].content.time_to_die = t_d;
		g_philo[i].content.time_to_eat = t_e;
		g_philo[i].content.time_to_sleep = t_s;
		g_philo[i].id = i;
		g_philo[i].r_fork = i;
		g_philo[i].l_fork = (i + 1) % n_p;
	}
	i = -1;
	while (++i < n_p)
		pthread_mutex_init(&p_lock[i], NULL);
}

void	*check_health(void *arg)
{
	t_thread *checker;
	checker = arg;
	printf("%ld\n", checker->t_limit);
	while (1)
	{
		if (get_time() > checker->t_limit)
		{
			g_die = 0;
			printf("%d is died\n", checker->id + 1);
			break ;
		}
	}
	return NULL;
}

void	*ft_routine(void *arg)
{
	t_thread	*philo;
	philo = arg;
	pthread_create(&th_health, NULL, check_health, (void *)philo);
	pthread_detach(th_health);
	philo->t_limit = get_time() + philo->content.time_to_die;
	// pthread_mutex_init(&eat_lock, NULL);
	while (g_die)
	{
		pthread_mutex_lock(&p_lock[philo->r_fork]);
		pthread_mutex_lock(&p_lock[philo->l_fork]);
		printf("%d has take r fork\n", philo->id + 1);
		printf("%d has take l fork\n", philo->id + 1);
		
		pthread_mutex_lock(&eat_lock);
		philo->t_limit = get_time() + philo->content.time_to_die;
		printf("%d is eating\n", philo->id + 1);
		usleep(1000 * philo->content.time_to_eat);
		pthread_mutex_unlock(&eat_lock);
		
		pthread_mutex_unlock(&p_lock[philo->r_fork]);
		pthread_mutex_unlock(&p_lock[philo->l_fork]);

		printf("%d is sleeping\n", philo->id + 1);
		usleep(1000 * philo->content.time_to_sleep);
		printf("%d is thinking\n", philo->id + 1);
	}
	return NULL;
}

void 	create_philod()
{
	int		i;

	i = -1;
	while (++i < n_philo)
	{
		pthread_create(&g_philo[i].thread[i], NULL, ft_routine, (void *)&g_philo[i]);
		pthread_detach(g_philo[i].thread[i]);
		usleep(100000);
	}
	// i = -1;
	// while (++i < n_philo)
	// 	pthread_join(g_philo[i].thread[i], NULL);
	
}

int		main(int argc, char **argv)
{
	int n_p = ft_atoi(argv[1]);
	int t_d = ft_atoi(argv[2]);
	int t_e = ft_atoi(argv[3]);
	int t_s = ft_atoi(argv[4]);
	g_die = 1;
	n_philo = n_p;
	init(n_p, t_d, t_e, t_s);
	create_philod();
	pthread_mutex_init(&eat_lock, NULL);
}