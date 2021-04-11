/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:57:13 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/11 16:44:53 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

void	ft_free(char **data, int argc)
{
	int		i;

	i = -1;
	while (++i < argc - 1)
	{
		if (data[i])
			free(data[i]);
	}
	free(data);
}

int 	is_valid(char **argv, int argc)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * argc);
	if (!tmp)
		return (0);
	i = -1;
	while (++i < argc - 1)
		tmp[i] = ft_strdup(argv[i + 1]);
	tmp[i] = NULL;
	j = -1;
	while (++j < argc - 1)
	{
		i = -1;
		while (++i < (int)ft_strlen(tmp[j]))
		{
			if (tmp[j][i] < '0' || tmp[j][i] > '9')
				return (0);
		}
	}
	ft_free(tmp, argc);
	return (1);
}

t_philo	*check_data(t_philo *philo, char **argv, int argc)
{
	t_content	content;

	content.e_eat = 0;
	content.done = 0;
	content.num_of_eat = 0;
	content.n_philo = ft_atoi(argv[1]);
	content.time_to_die = ft_atoi(argv[2]);
	content.time_to_eat = ft_atoi(argv[3]);
	content.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		content.num_of_eat = ft_atoi(argv[5]);
	if (content.num_of_eat)
		content.e_eat = content.num_of_eat;
	content.reached_count = 0;
	g_must_eat = 0;
	content.must_eat = 0;
	if (content.n_philo < 2 || content.time_to_die < 60)
		return (NULL);
	else if (content.time_to_eat < 60 || content.time_to_sleep < 60)
		return (NULL);
	philo = init_sem(philo, content);
	return (philo);
}
