/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:25:42 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/13 16:38:48 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_three.h"

static void	ft_free(t_philo *philo, char *str)
{
	if (philo)
		free(philo);
	else if (str)
		free(str);
}

void	destroy_philo(t_philo *philo)
{
	int		i;
	char	*name;

	i = -1;
	name = NULL;
	i = -1;
	while (++i < philo->content.n_philo)
	{
		name = ft_itoa(i + 1);
		sem_unlink(name);
		ft_free(NULL, name);
	}
	sem_unlink(MSG_SEM);
	sem_unlink(FORK_SEM);
	sem_unlink(DIE_SEM);
	ft_free(philo, NULL);
}
