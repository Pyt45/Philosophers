/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:57:13 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/03/21 12:00:57 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

static void	ft_free(char **data, int argc)
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

int			is_valid(char **argv, int argc)
{
	int		i;
	int		j;
	char	**tmp;

	if (!(tmp = (char **)malloc(sizeof(char *) * argc)))
		return (0);
	i = -1;
	while (++i < argc - 1)
		tmp[i] = strdup(argv[i + 1]);
	tmp[i] = NULL;
	j = -1;
	while (++j < argc - 1)
	{
		i = -1;
		while (++i < strlen(tmp[j]))
		{
			if (tmp[j][i] < '0' || tmp[j][i] > '9')
				return (0);
		}
	}
	ft_free(tmp, argc);
	return (1);
}

int			check_data(char **argv, int argc)
{
	int n_p;
	int	t_d;
	int	t_e;
	int	t_s;
	int n_e;

	n_p = atoi(argv[1]);
	t_d = atoi(argv[2]);
	t_e = atoi(argv[3]);
	t_s = atoi(argv[4]);
	n_e = (argc == 6) ? atoi(argv[5]) : 0;
	if (n_p < 2 || t_d < 60 || t_e < 60
	|| t_s < 60)
		return (0);
	init(n_p, t_d, t_e, t_s);
	return (1);
}
