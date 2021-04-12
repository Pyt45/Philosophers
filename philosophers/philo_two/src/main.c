/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:14:36 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/12 17:57:22 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

t_philo	*ft_handle_data(t_philo *philo, char **argv, int argc)
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
	else
	{
		philo = check_data(philo, argv, argc);
		if (!philo)
		{
			printf("\033[1;31mError out of range\033[0m\n");
			return (NULL);
		}
	}
	return (philo);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = NULL;
	philo = ft_handle_data(philo, argv, argc);
	if (!philo)
		return (-1);
	create_philo(philo);
	destroy_philo(philo);
	return (0);
}
