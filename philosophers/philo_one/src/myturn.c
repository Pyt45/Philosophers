#include "../include/philo_one.h"

void	*myturn(void *arg)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		usleep((int)pow(10, 4)); // 10^6 = 1s , 10^4 = 10 milliseconds
		printf("my turn %d\n", i);
		i++;
	}
	return (NULL);
}
