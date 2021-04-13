/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 09:45:59 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/13 16:26:17 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_three.h"

t_content	init_content(t_content cont)
{
	cont.start = get_time();
	sem_unlink(FORK_SEM);
	cont.fork_sem = sem_open(FORK_SEM, O_CREAT, 0666, cont.n_philo);
	sem_unlink(DIE_SEM);
	cont.die_sem = sem_open(DIE_SEM, O_CREAT, 0666, 1);
	sem_unlink(MSG_SEM);
	cont.msg_sem = sem_open(MSG_SEM, O_CREAT, 0666, 1);
	return (cont);
}

t_philo	*init_sem(t_philo *philo, t_content cont)
{
	int			i;
	char		*name;
	t_content	c;

	i = -1;
	c = init_content(cont);
	philo = (t_philo *)malloc(sizeof(t_philo) * c.n_philo);
	if (!philo)
		return (NULL);
	while (++i < c.n_philo)
	{
		philo[i].content = c;
		philo[i].id = i;
		philo[i].content.is_eating = 0;
		name = ft_itoa(i + 1);
		sem_unlink(name);
		philo[i].philo_sem = sem_open(name, O_CREAT, 0666, 1);
		free(name);
		sem_unlink(EAT_COUNT);
		philo[i].eat_count_sem = sem_open(EAT_COUNT, O_CREAT, 0666, 0);
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
