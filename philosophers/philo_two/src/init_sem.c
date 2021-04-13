/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 09:45:59 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/13 15:58:34 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

t_content	init_content(t_content cont)
{
	t_content	c;

	c = cont;
	c.start = get_time();
	sem_unlink(FORK_SEM);
	c.fork_sem = sem_open(FORK_SEM, O_CREAT, 0666, c.n_philo);
	sem_unlink(DIE_SEM);
	c.die_sem = sem_open(DIE_SEM, O_CREAT, 0666, 1);
	sem_unlink(MSG_SEM);
	c.msg_sem = sem_open(MSG_SEM, O_CREAT, 0666, 1);
	return (c);
}

t_philo	*init_sem(t_philo *philo, t_content cont)
{
	int			i;
	t_content	c;
	char		*name;

	i = -1;
	c = init_content(cont);
	philo = (t_philo *)malloc(sizeof(t_philo) * c.n_philo);
	if (!philo)
		return (NULL);
	while (++i < c.n_philo)
	{
		philo[i].content = c;
		philo[i].id = i;
		philo[i].content.done = 0;
		philo[i].content.is_eating = 0;
		philo[i].content.e_c = c.num_of_eat;
		name = ft_itoa(i + 1);
		sem_unlink(name);
		philo[i].philo_sem = sem_open(name, O_CREAT, 0666, 1);
		free(name);
	}
	return (philo);
}

void	print_status(long t, char *msg, t_philo *philo, int bl)
{
	if (sem_wait(philo->content.msg_sem) < 0)
		return ;
	printf("%ld\t%d%s\n", t, philo->id + 1, msg);
	if (bl)
		sem_post(philo->content.msg_sem);
}
