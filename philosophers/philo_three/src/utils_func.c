/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:02:26 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/12 10:22:10 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_three.h"

char	*ft_itoa(int n)
{
	char	*ptr;
	long	nbr;
	int		len;

	len = 1;
	n < 0 ? ++len : 0;
	nbr = n < 0 ? -(long)n : n;
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr[len] = '\0';
	n < 0 ? *ptr = '-' : 0;
	nbr = n < 0 ? -(long)n : n;
	while (nbr > 9)
	{
		ptr[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	ptr[--len] = nbr + '0';
	return (ptr);
}

char		*ft_strdup(const char *str)
{
	char	*ptr;
	char	*rptr;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str) + 1;
	if (!(ptr = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	rptr = ptr;
	while (*str)
		*ptr++ = *str++;
	*ptr = '\0';
	return (rptr);
}

long	get_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + tv.tv_usec / 1000);
}
