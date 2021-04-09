/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:14:36 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/09 17:22:54 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

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
	// if (!(content.eat_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t))))
	// 	return (NULL);
	if (!(content.e_arr = (int *)malloc(sizeof(int) * content.n_philo)))
		return (NULL);
	memset(content.e_arr, 0, content.n_philo);
	if (pthread_mutex_init(content.die_mutex, NULL))
		return (NULL);
	// if (pthread_mutex_init(content.eat_mutex, NULL))
	// 	return (NULL);
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
		if (get_time() > checker->t_limit)
		{
			// if (checker->content.r_eat == 1)
			// 	checker->content.r_eat = 0;
			if (pthread_mutex_lock(checker->content.msg_mutex))
				return (NULL);
			printf("%ld\t%d died\n",get_time() - checker->content.s_start, checker->id + 1);
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

// void _do(){
	
// }

void	*check_each_times(void *arg)
{
	t_philo *checker;
	int 	i;

	checker = (t_philo *)arg;
	i = 0;
	while (1)
	{
		// 	i++;
		if (g_must_eat == checker->num_of_philo)
		{
			// g_must_eat = 0;
			pthread_mutex_lock(checker->content.msg_mutex);
			printf("%ld\treached the limit of eats\n", get_time() - checker->content.s_start);
			pthread_mutex_unlock(checker->content.die_mutex);
		}
		// i++;
	}
	// if (i == checker->content.reached_count)
	// 	checker->content.reached_count = 0;
	return (NULL);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->content.fork_mutex[philo->r_fork]);
	pthread_mutex_lock(philo->content.msg_mutex);
	printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, TAKE_FORK);
	pthread_mutex_unlock(philo->content.msg_mutex);

	pthread_mutex_lock(&philo->content.fork_mutex[philo->l_fork]);
	pthread_mutex_lock(philo->content.msg_mutex);
	printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, TAKE_FORK);
	pthread_mutex_unlock(philo->content.msg_mutex);
}

void	release_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->content.fork_mutex[philo->r_fork]);
	pthread_mutex_unlock(&philo->content.fork_mutex[philo->l_fork]);
}

void	eat_action(t_philo *philo)
{
	pthread_mutex_lock(philo->philo_mutex);
	philo->content.s_start = get_time();
	philo->t_limit = philo->content.s_start + philo->content.time_to_die;
	pthread_mutex_lock(philo->content.msg_mutex);
	philo->is_eating = 1;
	printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, EAT);
	if (philo->content.num_of_eat)
	{
		// philo->content.e_arr[philo->index_p]++;
		philo->content.reached_count++;
		// philo->content.num_of_eat--;
			// philo->content.r_eat++;
		if (philo->content.reached_count == philo->content.e_eat)
			g_must_eat += 1;
		// if (g_must_eat == philo->content.e_eat)
		// {
		// 	// philo->content.num_of_eat = philo->content.e_eat;
		// 	philo->is_eating = 0;
		// }
	}
	printf("g = %d\n", g_must_eat);
	pthread_mutex_unlock(philo->content.msg_mutex);
	usleep(1000 * philo->content.time_to_eat);
	// philo->is_eating = 0;
	// if (philo->content.e_eat)
	// 	philo->content.e_eat--;
	// if (!philo->content.e_eat)
	// 	philo->content.r_eat = 1;
	pthread_mutex_unlock(philo->philo_mutex);
}

void	think_action(t_philo *philo)
{
	pthread_mutex_lock(philo->content.msg_mutex);
	printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, THINK);
	pthread_mutex_unlock(philo->content.msg_mutex);
}

void	sleep_action(t_philo *philo)
{
	pthread_mutex_lock(philo->content.msg_mutex);
	printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, SLEEP);
	pthread_mutex_unlock(philo->content.msg_mutex);
	usleep(1000 * philo->content.time_to_sleep);
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
		take_fork(philo);
		eat_action(philo);
		// if (philo->content.reached_count == philo->content.e_eat)
		// 	break;
		release_fork(philo);
		sleep_action(philo);
		think_action(philo);
	}
	return (NULL);
}

void 	create_philod(t_philo *philo)
{
	int		i;

	i = -1;
	pthread_mutex_lock(philo->content.die_mutex);
	if (philo->content.num_of_eat)
	{
		// g_must_eat = 0;
		pthread_create(&philo->content.eat_thread, NULL, check_each_times, (void *)philo);
		pthread_detach(philo->content.eat_thread);
	}
	while (++i < philo->content.n_philo)
	{
		philo->index_p = i;
		pthread_create(&philo[i].thread, NULL, ft_routine, (void *)&philo[i]);
		pthread_detach(philo[i].thread);
		usleep(100);
	}

	// while ((philo->content.num_of_eat != -1 && g_must_eat < philo->content.num_of_eat) && )
	// printf("r_eat = %d\n", philo->content.reached_count);
	
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










// void	*ft_routine(void *arg)
// {
// 	t_philo	*philo;
// 	philo = (t_philo *)arg;
// 	philo->content.s_start = get_time();
// 	philo->t_limit = philo->content.s_start + philo->content.time_to_die;
// 	if (pthread_create(&philo->content.philo_health, NULL, check_health, arg))
// 		return (NULL);
// 	if (pthread_detach(philo->content.philo_health))
// 		return (NULL);
	
// 	while (1)
// 	{
// 		// pthread_mutex_lock(&philo->content.fork_mutex[philo->r_fork]);
// 		// pthread_mutex_lock(philo->content.msg_mutex);
// 		// printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, TAKE_FORK);
// 		// pthread_mutex_unlock(philo->content.msg_mutex);

// 		// pthread_mutex_lock(&philo->content.fork_mutex[philo->l_fork]);
// 		// pthread_mutex_lock(philo->content.msg_mutex);
// 		// printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, TAKE_FORK);
// 		// pthread_mutex_unlock(philo->content.msg_mutex);
// 		take_fork(philo);
		
// 		// pthread_mutex_lock(philo->philo_mutex);
// 		// philo->is_eating = 1;
// 		// philo->content.s_start = get_time();
// 		// philo->t_limit = philo->content.s_start + philo->content.time_to_die;
// 		// pthread_mutex_lock(philo->content.msg_mutex);
// 		// printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, EAT);
// 		// pthread_mutex_unlock(philo->content.msg_mutex);
// 		// usleep(1000 * philo->content.time_to_eat);
// 		// philo->is_eating = 0;
// 		// // if (philo->content.num_of_eat)
// 		// // philo->content.num_of_eat--;
// 		// // if (!philo->content.num_of_eat)
// 		// // 	philo->content.r_eat = 1;
// 		// pthread_mutex_unlock(philo->philo_mutex);

// 		eat_action(philo);
// 		// pthread_mutex_unlock(&philo->content.fork_mutex[philo->r_fork]);
// 		// pthread_mutex_unlock(&philo->content.fork_mutex[philo->l_fork]);
// 		release_fork(philo);

// 		// pthread_mutex_lock(philo->content.msg_mutex);
// 		// printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, SLEEP);
// 		// pthread_mutex_unlock(philo->content.msg_mutex);
// 		// usleep(1000 * philo->content.time_to_sleep);
// 		sleep_action(philo);
// 		// pthread_mutex_lock(philo->content.msg_mutex);
// 		// printf("%ld\t%d%s\n", get_time() - philo->content.start, philo->id + 1, THINK);
// 		// pthread_mutex_unlock(philo->content.msg_mutex);
// 		think_action(philo);
// 	}
// 	return NULL;
// }
