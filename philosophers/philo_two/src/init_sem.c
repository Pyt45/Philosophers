/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 09:45:59 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/11 10:53:16 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

// t_content	init_content(t_content cont)
// {
// 	char	**cmd;
// }

t_philo		*init_sem(t_philo *philo, t_content cont)
{
	int 	i;
	char	*name;

	i = -1;
	cont.start = get_time();
	if (!(cont.msg_sem = (sem_t *)malloc(sizeof(sem_t))))
		return (NULL);
	if (!(cont.die_sem = (sem_t *)malloc(sizeof(sem_t))))
		return (NULL);
	if (!(cont.fork_sem = (sem_t *)malloc(sizeof(sem_t))))
		return (NULL);
	sem_unlink(FORK_SEM);
	cont.fork_sem = sem_open(FORK_SEM, O_CREAT, 0666, cont.n_philo);
	sem_unlink(DIE_SEM);
	cont.die_sem = sem_open(DIE_SEM, O_CREAT, 0666, 1);
	sem_unlink(MSG_SEM);
	cont.msg_sem = sem_open(MSG_SEM, O_CREAT, 0666, 1);
	if (!(philo = (t_philo *)malloc(sizeof(t_philo) * cont.n_philo)))
		return (NULL);
	while (++i < cont.n_philo)
	{
		if (!(philo[i].philo_sem = (sem_t *)malloc(sizeof(sem_t))))
			return (NULL);
		philo[i].num_of_philo = cont.n_philo;
		philo[i].content = cont;
		philo[i].id = i;
		philo[i].is_eating = 0;
		name = ft_itoa(i + 1);
		sem_unlink(name);
		philo[i].philo_sem = sem_open(name, O_CREAT, 0666, 1);
		free(name);
	}
	return (philo);
}