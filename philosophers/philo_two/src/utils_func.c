/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:02:26 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/12 16:47:36 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

char	*ft_itoa(int n)
{
	char	*ptr;
	long	nbr;
	int		len;

	len = 1;
	nbr = n;
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	nbr = n;
	while (nbr > 9)
	{
		ptr[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	ptr[--len] = nbr + '0';
	return (ptr);
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
