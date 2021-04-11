/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 09:46:15 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/11 10:53:08 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

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