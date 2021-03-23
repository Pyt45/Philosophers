/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:14:36 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/03/23 13:02:45 by aaqlzim          ###   ########.fr       */
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

t_thread	*init(t_thread *philo, int n_p, int t_d, int t_e, int t_s)
{
	int 	i;

	i = -1;
	g_die = 1;
	n_philo = n_p;
	g_lock_died = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!(p_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n_philo)))
		return (NULL);
	g_start = get_time();
	if (!(philo = (t_thread *)malloc(sizeof(t_thread) * n_p)))
		return (NULL);
	while (++i < n_p)
	{
		philo[i].msg_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		philo[i].philo_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		philo[i].num_of_philo = n_p;
		philo[i].content.time_to_die = t_d;
		philo[i].content.time_to_eat = t_e;
		philo[i].content.time_to_sleep = t_s;
		philo[i].id = i;
		philo[i].r_fork = i;
		philo[i].l_fork = (i + 1) % n_p;
		pthread_mutex_init(philo[i].msg_mutex, NULL);
		pthread_mutex_init(philo[i].philo_mutex, NULL);
		pthread_mutex_init(&p_lock[i], NULL);
		pthread_mutex_init(g_lock_died, NULL);
	}
	// i = -1;
	// while (++i < n_p)
	return (philo);
}

void	*check_health(void *arg)
{
	t_thread *checker;
	checker = arg;
	pthread_mutex_lock(g_lock_died);
	while (1)
	{
		if (get_time() > checker->t_limit)
		{
			g_die = 0;
			pthread_mutex_lock(checker->msg_mutex);
			printf("%d is died\n", checker->id + 1);
			pthread_mutex_lock(checker->msg_mutex);
			// pthread_mutex_unlock(g_lock_died);
			break ;
		}
	}
	pthread_mutex_unlock(g_lock_died);
	return NULL;
}

void	*ft_routine(void *arg)
{
	t_thread	*philo;
	philo = arg;
	philo->t_limit = get_time() + philo->content.time_to_die;
	pthread_create(&th_health, NULL, check_health, arg);
	pthread_detach(th_health);
	pthread_mutex_lock(g_lock_died);
	pthread_mutex_lock(philo->philo_mutex);
	while (g_die)
	{
		pthread_mutex_lock(&p_lock[philo->r_fork]);
		pthread_mutex_lock(&p_lock[philo->l_fork]);
		printf("%ld %d has take r fork\n", get_time() - g_start, philo->id + 1);
		printf("%ld %d has take l fork\n", get_time() - g_start, philo->id + 1);
		
		pthread_mutex_lock(philo->msg_mutex);
		printf("%ld %d is eating\n", get_time() - g_start, philo->id + 1);
		usleep(1000 * philo->content.time_to_eat);
		philo->t_limit = get_time() + philo->content.time_to_die;
		pthread_mutex_unlock(philo->msg_mutex);
		
		pthread_mutex_unlock(&p_lock[philo->r_fork]);
		pthread_mutex_unlock(&p_lock[philo->l_fork]);

		pthread_mutex_lock(philo->msg_mutex);
		printf("%ld %d is sleeping\n", get_time() - g_start, philo->id + 1);
		usleep(1000 * philo->content.time_to_sleep);
		pthread_mutex_unlock(philo->msg_mutex);
		pthread_mutex_lock(philo->msg_mutex);
		printf("%ld %d is thinking\n", get_time() - g_start, philo->id + 1);
		pthread_mutex_unlock(philo->msg_mutex);
	}
	pthread_mutex_unlock(philo->philo_mutex);
	return NULL;
}

void 	create_philod(t_thread *philo)
{
	int		i;

	i = -1;
	while (++i < n_philo)
	{
		pthread_create(&philo[i].thread, NULL, ft_routine, (void *)&philo[i]);
		pthread_detach(philo[i].thread);
		usleep(100);
	}
	i = -1;
	while (++i < n_philo)
		pthread_mutex_lock(philo[i].philo_mutex);
}

t_thread	*ft_HandleData(t_thread *philo, char **argv, int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("\033[1;31mError wrong number of argumenst\033[0m\n");
		return (NULL);
	}
	else if (!is_valid(argv, argc))
	{
		printf("\033[1;31mError data must be valid\033[0m\n");
		return (NULL);
	}
	else if (!(philo = check_data(philo, argv, argc)))
	{
		printf("\033[1;31mError out of range\033[0m\n");
		return (NULL);
	}
	return (philo);
}

int		main(int argc, char **argv)
{
	t_thread	*philo;

	philo = NULL;
	if (!(philo = ft_HandleData(philo, argv, argc)))
		return (-1);
	// g_die = 1;
	// n_philo = n_p;
	// g_lock_died = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	// init(n_p, t_d, t_e, t_s);
	create_philod(philo);
	// pthread_mutex_lock(g_lock_died);
}