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

int		g = 0;

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

void	yourturn()
{
	int		i;

	i = 0;
	while (i < 4)
	{
		usleep((int)pow(10, 4)); // 1 s
		printf("your turn %d\n", i);
		i++;
	}
}
void	*mythreadFun(void *arg)
{
	int			*id;
	static int 	s = 0;

	id = (int *)arg;
	s++; g++;
	sleep(1);
	printf("My thread id %d and static is %d and global is %d\n", *id, s, g);
	return NULL;
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
		yourturn();
		pthread_join(l_thread->newthread, NULL);
	}
	return ;
}
