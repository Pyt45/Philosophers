#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

pthread_mutex_t lock;
int j;
pthread_t tid[2];
int c;

// void 	*try_this(void *arg)
// {
// 	pthread_mutex_lock(&lock);
// 	unsigned int i = 0;
// 	c += 1;
// 	printf("\n Job %d has started\n", c);

// 	for (i = 0; i < 0xFFFFFFFF; i++)
// 		;
// 	printf("\n Job %d has finished\n", c);
// 	pthread_mutex_unlock(&lock);
// 	return NULL;
// }

// int		main(void)
// {
// 	int i = 0;
// 	int err;
// 	pthread_mutex_init(&lock, NULL);
// 	while (i < 2) {
// 		err = pthread_create(&tid[i], NULL, &try_this, NULL);
// 		if (err)
// 			printf("\nThread can't be created : [%s]", strerror(err));
// 		i++;
// 	}

// 	pthread_join(tid[0], NULL);
// 	pthread_join(tid[1], NULL);
// 	pthread_mutex_destroy(&lock);
// 	return 0;
// }




typedef struct 	s_time
{
	struct timeval start;
	struct timeval end;
}				t_time;
unsigned int get_time_of_excute(t_time *t)
{
	return ((t->end.tv_sec * 1000 + (t->end.tv_usec / 1000)) -
	(t->start.tv_sec * 1000 + (t->start.tv_usec / 1000)));
}

void	yourTurn() {
	int i = 0;
	while (i < 5) {
		usleep((int)pow(10, 6));
		printf("you turn %d\n", i);
		i++;
	}
}

void	*myturn(void *arg) {
	pthread_mutex_lock(&lock);
	int i = 0;
	while (i < 8) {
		usleep((int)pow(10, 6));
		printf("my turn %d\n", i);
		i++;
	}
	pthread_mutex_unlock(&lock);
	return (NULL);
}

void	*do_process(void *arg)
{
	pthread_mutex_lock(&lock);
	int i = 0;
	j++;
	while (i < 5) {
		printf("%d", j);
		// for (unsigned int i = 0; i < 0xFFFFFFFF; i++)
		// 	;
		sleep(1);
		i++;
	}
	printf("...Done\n");
	pthread_mutex_unlock(&lock);
	return NULL;
}

int		main(void) {
	t_time	time;
	pthread_mutex_init(&lock, NULL);
	j = 0;
	gettimeofday(&time.start, NULL);
	for (int i =0; i < 2; i++)
		pthread_create(&tid[i], NULL, do_process, NULL);
	// yourTurn();
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&lock);
	gettimeofday(&time.end, NULL);
	printf("%u ms\n", get_time_of_excute(&time));
} 