/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:52:51 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/11/25 14:33:48 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

// int		g = 0;
// void	*mythreadFun(void *arg)
// {
// 	int			*id;
// 	static int 	s = 0;

// 	id = (int *)arg;
// 	s++; g++;
// 	sleep(1);
// 	printf("My thread id %d and static is %d and global is %d\n", *id, s, g);
// 	return NULL;
// }

void	*myturn(void *arg)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		usleep((int)pow(10, 4)); // 10^6 = 1s , 10^4 = 10 milliseconds
		printf("my turn %d\n", i);
		i++;
	}
	return (NULL);
}

void	create_philo(t_thread *l_thread)
{
	int		i;
	int		err;
	// i = 0;
	// while (i < 3)
	// {
	// 	if ((err = pthread_create(&l_thread->newthread, NULL, mythreadFun,
	// 	(void *)&l_thread->newthread)))
	// 		printf("%s\n", strerror(err));
	// 	pthread_join(l_thread->newthread, NULL);
	// 	i++;
	// }
	i = -1;
	while (++i < l_thread->num_philo)
	{
		if ((err = pthread_create(&l_thread->newthread, NULL, myturn, NULL)))
			printf("Error : %s\n", strerror(err));
		// yourturn();
		pthread_join(l_thread->newthread, NULL);
	}
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <pthread.h>
// #include <math.h>
// #include <unistd.h>
// #include <sys/time.h>

// typedef struct			s_thread
// {
// 	int					num_of_philo;
// 	int					time_to_die;
// 	int					time_to_eat;
// 	int					time_to_sleep;
// 	int					num_of_times_each_philo_must_eat;
// 	pthread_t			thread;
// 	struct timeval		start;
// 	struct timeval		end;
// 	struct	s_thread	*next;
// }						t_thread;


// void	*myturn(void *arg)
// {
// 	for (int i = 0; i < 8; i++)
// 	{
// 		usleep((int)pow(10, 0));
// 		printf("My turn %d\n", i);
// 	}
// 	return (NULL);
// }

// void	yourturn()
// {
// 	for (int i = 0; i < 5; i++)
// 	{
// 		usleep((int)pow(10, 0));
// 		printf("Your turn %d\n", i);
// 	}	
// }

// void	*ft_memset(void *ptr, int x, size_t n)
// {
// 	char	*str;

// 	str = (char *)ptr;
// 	while (n--)
// 		*str++ = (unsigned char)x;
// 	return ((void *)ptr);
// }

// unsigned int get_time_of_excute(t_thread *l_thread)
// {
// 	return ((l_thread->end.tv_sec * 1000 + (l_thread->end.tv_usec / 1000)) -
// 	(l_thread->start.tv_sec * 1000 + (l_thread->start.tv_usec / 1000)));
// }

// int		main(int argc, char **argv)
// {
// 	int			i;
// 	t_thread	l_thread;

// 	gettimeofday(&l_thread.start, NULL);
// 	i = -1;
// 	while (++i < atoi(argv[1]))
// 	{
// 		pthread_create(&l_thread.thread, NULL, myturn, NULL);
// 		yourturn();
// 		pthread_join(l_thread.thread, NULL);
// 	}
// 	gettimeofday(&l_thread.end, NULL);
// 	printf("time counted since beginning %ld ms\n", get_time_of_excute(&l_thread));
// 	return (0);
// }