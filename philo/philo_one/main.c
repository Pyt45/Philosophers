/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:09:42 by yslati            #+#    #+#             */
/*   Updated: 2021/03/20 12:36:54 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

int		g_n;
int		g_die;
int		g_eat;
int		g_sleep;
int		g_eatc;

int		g_dead;
pthread_mutex_t *g_forks;
pthread_mutex_t *g_philo;
pthread_mutex_t *g_dies;



typedef struct		s_philo
{
	pthread_t		*th;
	pthread_t		hl;
	int				id;
	long int		limit;
	int				fork;
	int				l_fork;
	int				r_fork;
}					t_philo;

t_philo		*g_ps;

int			is_degit(int n)
{
	return (n >= '0' && n <= '9');
}


static	int	ft_help(long a, int sign)
{
	if (a < 0 && sign > 0)
		return (-1);
	if (a > 0 && sign < 0)
		return (0);
	return (a);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	a;

	a = 0;
	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] > '9' || str[i] < 48)
			break ;
		a = (a * 10) + str[i] - 48;
		i++;
	}
	a = a * sign;
	return (ft_help(a, sign));
}

int			args_isnumeric(char **av, int ac)
{
	int i;
	int j;

	j = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			if (!is_degit(av[i][j++]))
			{
				printf("wrong argument !\n");
				return (0);
			}
		i++;
	}
	return (1);
}

int			get_value(char **av, int ac)
{
	g_n = ft_atoi(av[1]);
	g_die = ft_atoi(av[2]);
	g_eat = ft_atoi(av[3]);
	g_sleep = ft_atoi(av[4]);
	g_eatc = (ac == 6) ? ft_atoi(av[5]) : -1;
	if (g_n < 2 || g_n > 200 || g_die < 60 || g_eat < 60 || g_sleep < 60)
	{
		printf("wrong argument !\n");
		return (0);
	}
	return (1);
}

long int	get_time()
{
	struct	timeval	tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec) / 1000);
}

void	*health(void *data)
{
	t_philo *p = data;
	while (1)
	{
		if (get_time() >= p->limit)
		{
			g_dead = 0;
			printf("%d is died\n", p->id + 1);
			break;
		}
	}
	return (NULL);
}

void		*routine(void *data)
{
	t_philo		*p;
	int			l_fork;
	int			r_fork;

	p = data;
	// r_fork = p->id;
	// l_fork = (p->id + 1) % g_n;
	p->limit = get_time() + g_die;
	// pthread_create(&p->hl, NULL, health, p);
	// pthread_detach(p->hl);
	while (1)
	{
		pthread_mutex_lock(&g_forks[p->r_fork]);
		printf("%d has taken the right Fork\n", p->id + 1);
		pthread_mutex_lock(&g_forks[p->l_fork]);
		printf("%d has taken the left Fork\n", p->id + 1);
		
		pthread_mutex_lock(g_philo);
		p->limit = get_time() + g_eat;
		printf("%d is eating\n", p->id + 1);
		usleep(1000 * g_eat);
		pthread_mutex_unlock(g_philo);
		pthread_mutex_unlock(&g_forks[p->r_fork]);
		pthread_mutex_unlock(&g_forks[p->l_fork]);
		
		printf("%d is sleeping\n", p->id + 1);
		usleep(1000 * g_sleep);
		printf("%d is thinking\n", p->id + 1);
	}
	return(NULL);
}

void		init_philo()
{
	int i;
// g_pd[5]
// while (i < 5)
// {  }
	i = -1;
	g_ps = malloc(sizeof(t_philo) * g_n);
	g_forks = malloc(sizeof(pthread_mutex_t) * g_n);
	g_ps->th = malloc(sizeof(pthread_t) * g_n);
	while (++i < g_n)
		pthread_mutex_init(&g_forks[i], NULL);
}
void		fun(int ac, char ** av)
{
	g_n = ft_atoi(av[1]);
	g_die = ft_atoi(av[2]);
	g_eat = ft_atoi(av[3]);
	g_sleep = ft_atoi(av[4]);
	g_eatc = (ac == 6) ? ft_atoi(av[5]) : -1;
}
int			main(int ac,char **av)
{
	int	i;

	i = -1;
	g_philo = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	g_dies = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	// while (++i < 5)
	// 	pthread_mutex_init(&g_philo[i], NULL);
	g_dead = 1;
	if ((ac < 5 || ac > 6) && printf("wrong argument !\n"))
		return (1);
	else
	{
		if (!args_isnumeric(av, ac) || !get_value(av, ac))
			return (1);
		if (g_eatc == 0)
			return (0);
		init_philo();
	}
	i = -1;
	pthread_mutex_init(g_philo, NULL);
	while (++i < g_n)
	{
		g_ps[i].id = i;
		g_ps[i].r_fork = i;
		g_ps[i].l_fork = (i + 1) % g_n;
	}
	i = -1;
	// pthread_mutex_lock(g_dies);
	while (++i < g_n)
	{
		pthread_create(&g_ps->th[i], NULL, routine, &g_ps[i]);
		// pthread_detach(g_ps->th[i]);
		usleep(10);
	}
	 i = -1;
	 while (++i < g_n)
	 	pthread_join(g_ps->th[i], NULL);
	// pthread_mutex_lock(g_dies);
	// pthread_mutex_unlock(g_dies);
	return (0);
}

// pthread_mutex_t mutex;

// void	*routine(void* p)
// {
// 	pthread_mutex_lock(&mutex);
// 	puts("start");
// 	sleep(3);
// 	puts("end");
// 	pthread_mutex_unlock(&mutex);
// 	return NULL;
// }


// int main()
// {
// 	pthread_mutex_init(&mutex, NULL);
// 	pthread_t thr;

	
// 	pthread_create(&thr, NULL, routine, NULL);
// 	pthread_create(&thr, NULL, routine, NULL);
// 	sleep(1);
// 	pthread_mutex_lock(&mutex);
// 	// pthread_join(thr, NULL);
// 	puts("finish");

// }