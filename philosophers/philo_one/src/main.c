/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:14:36 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/03/24 12:10:07 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"


// t_philo	*new_thread(int num_philo, t_content *content)
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

// long	get_time()
// {
// 	struct timeval tv;
// 	gettimeofday(&tv, NULL);
// 	return ((tv.tv_sec * 1000) + tv.tv_usec / 1000);
// }

t_philo	*init(t_philo *philo, t_content cont)
{
	int 	i;
	t_content content;

	i = -1;
	content = cont;
	// printf("e_of_t = %d\n", cont.num_of_eat);
	content.start = get_time();
	if (!(content.msg_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t))))
		return (NULL);
	if (!(content.die_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t))))
		return (NULL);
	if (!(content.fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * content.n_philo)))
		return (NULL);
	if (pthread_mutex_init(content.die_mutex, NULL))
		return (NULL);
	if (pthread_mutex_init(content.msg_mutex, NULL))
		return (NULL);
	if (!(philo = (t_philo *)malloc(sizeof(t_philo) * content.n_philo)))
		return (NULL);
	while (++i < content.n_philo)
	{
		if (!(philo[i].philo_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t))))
			return (NULL);
		philo[i].num_of_philo = content.n_philo;
		philo[i].content = content;
		philo[i].id = i;
		philo[i].r_fork = i;
		philo[i].l_fork = (i + 1) % content.n_philo;
		philo[i].is_eating = 0;
		if (pthread_mutex_init(philo[i].philo_mutex, NULL))
			return (NULL);
		if (pthread_mutex_init(&philo[i].content.fork_mutex[i], NULL))
			return (NULL);
	}
	return (philo);
}

void	*check_health(void *arg)
{
	t_philo *checker;
	checker = (t_philo *)arg;
	while (1)
	{
		if (pthread_mutex_lock(checker->philo_mutex))
			return (NULL);
		if (!checker->is_eating && get_time() > checker->t_limit)
		{
			// if (checker->content.r_eat == 1)
			// 	checker->content.r_eat = 0;
			if (pthread_mutex_lock(checker->content.msg_mutex))
				return (NULL);
			printf("%ld\t%d is died\n",get_time() - checker->content.s_start, checker->id + 1);
			if (pthread_mutex_unlock(checker->philo_mutex))
				return (NULL);
			if (pthread_mutex_unlock(checker->content.die_mutex))
				return (NULL);
			return (NULL);
		}
		if (pthread_mutex_unlock(checker->philo_mutex))
			return (NULL);
		usleep(1000);
	}
	return NULL;
}


void	*ft_routine(void *arg)
{
	t_philo	*philo;
	philo = (t_philo *)arg;
	philo->content.s_start = get_time();
	philo->t_limit = philo->content.s_start + philo->content.time_to_die;
	if (pthread_create(&philo->content.philo_health, NULL, check_health, arg))
		return (NULL);
	if (pthread_detach(philo->content.philo_health))
		return (NULL);
	
	while (1)
	{
		pthread_mutex_lock(&philo->content.fork_mutex[philo->r_fork]);
		pthread_mutex_lock(philo->content.msg_mutex);
		printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, TAKE_FORK);
		pthread_mutex_unlock(philo->content.msg_mutex);

		pthread_mutex_lock(&philo->content.fork_mutex[philo->l_fork]);
		pthread_mutex_lock(philo->content.msg_mutex);
		printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, TAKE_FORK);
		pthread_mutex_unlock(philo->content.msg_mutex);
		
		pthread_mutex_lock(philo->philo_mutex);
		philo->is_eating = 1;
		philo->content.s_start = get_time();
		philo->t_limit = philo->content.s_start + philo->content.time_to_die;
		pthread_mutex_lock(philo->content.msg_mutex);
		printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, EAT);
		pthread_mutex_unlock(philo->content.msg_mutex);
		usleep(1000 * philo->content.time_to_eat);
		philo->is_eating = 0;
		// if (philo->content.num_of_eat)
		// philo->content.num_of_eat--;
		// if (!philo->content.num_of_eat)
		// 	philo->content.r_eat = 1;
		pthread_mutex_unlock(philo->philo_mutex);
		pthread_mutex_unlock(&philo->content.fork_mutex[philo->r_fork]);
		pthread_mutex_unlock(&philo->content.fork_mutex[philo->l_fork]);

		pthread_mutex_lock(philo->content.msg_mutex);
		printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, SLEEP);
		pthread_mutex_unlock(philo->content.msg_mutex);
		usleep(1000 * philo->content.time_to_sleep);
		pthread_mutex_lock(philo->content.msg_mutex);
		printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, THINK);
		pthread_mutex_unlock(philo->content.msg_mutex);
	}
	return NULL;
}

void 	create_philod(t_philo *philo)
{
	int		i;

	i = -1;
	pthread_mutex_lock(philo->content.die_mutex);
	while (++i < philo->content.n_philo)
	{
		pthread_create(&philo[i].thread, NULL, ft_routine, (void *)&philo[i]);
		pthread_detach(philo[i].thread);
		usleep(100);
	}
	pthread_mutex_lock(philo->content.die_mutex);
	pthread_mutex_unlock(philo->content.die_mutex);
}

t_philo	*ft_HandleData(t_philo *philo, char **argv, int argc)
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
	t_philo	*philo;

	philo = NULL;
	if (!(philo = ft_HandleData(philo, argv, argc)))
		return (-1);
	create_philod(philo);
}