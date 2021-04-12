/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:16:02 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/12 15:28:53 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

static	int	ft_max(long int res, int sign)
{
	if (res < 0 && sign > 0)
		return (-1);
	if (res > 0 && sign < 0)
		return (0);
	return (res);
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			rst;

	sign = 1;
	rst = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		rst *= 10;
		rst += *str - '0';
		str++;
	}
	rst = rst * sign;
	return (ft_max(rst, sign));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	char	*rptr;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str) + 1;
	ptr = (char *)malloc(sizeof(char) * len);
	if (!ptr)
		return (NULL);
	rptr = ptr;
	while (*str)
		*ptr++ = *str++;
	*ptr = '\0';
	return (rptr);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + tv.tv_usec / 1000);
}
