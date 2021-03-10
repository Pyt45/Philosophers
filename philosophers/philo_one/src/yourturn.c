#include "../include/philo_one.h"

void	yourturn(void *arg)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		usleep((int)pow(10, 5)); // 1 s
		printf("your turn %d\n", i);
		i++;
	}
}