#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

// # define NUM 5
// # define MAX_SLEEP_TIME 5

// enum {THINK, HUNGRY, EAT} state[NUM];

// pthread_mutex_t		mutex_lock;
// pthread_cond_t 		cond_vars[NUM];
// int					thread_id[NUM];
// pthread_t 			tid[NUM];

// void	init()
// {
// 	int i = 0;
// 	for (i = 0; i < NUM; i++)
// 	{
// 		state[i] = THINK;
// 		thread_id[i] = i;
// 		pthread_cond_init(&cond_vars[i], NULL);
// 	}
// 	pthread_mutex_init(&mutex_lock,NULL);
// }

// int 	left_f(int num)
// {
// 	if (!num)
// 		return NUM - 1;
// 	return num - 1;
// }

// int right_f(int num)
// {
// 	if (num == NUM - 1)
// 		return 0;
// 	return num + 1;
// }

// void	test(int i)
// {
// 	if (state[left_f(i)] != EAT && state[i] == HUNGRY && state[right_f(i)] != EAT)
// 	{
// 		state[i] = EAT;
// 		pthread_cond_signal(&cond_vars[i]);
// 	}
// }

// void	pickup_forks(int num) {
// 	pthread_mutex_lock(&mutex_lock);

// 	state[num] = HUNGRY;
// 	test(num);
// 	while (state[num] != EAT)
// 		pthread_cond_wait(&cond_vars[num], &mutex_lock);
// 	pthread_mutex_unlock(&mutex_lock);
// }

// void	return_forks(int num) {
// 	pthread_mutex_lock(&mutex_lock);

// 	state[num] = THINK;
// 	test(left_f(num));
// 	test(right_f(num));

// 	pthread_mutex_unlock(&mutex_lock);
// }

// void	eating(int s_time)
// {
// 	sleep(s_time);
// }

// void	thinking(int s_time)
// {
// 	sleep(s_time);
// }

// void	*philosoper(void *arg)
// {
// 	int *lnum = (int *)arg;
// 	int num = *lnum;
// 	int s_time;
// 	int t_loop = 0;

// 	srandom((unsigned)time(NULL));
// 	while (t_loop < 5)
// 	{
// 		s_time = (int)((random() % MAX_SLEEP_TIME) + 1);
// 		// s_time = 1;
// 		thinking(s_time);
// 		pickup_forks(num);
// 		printf("Philosopher %d is eating\n", num);
// 		s_time = (int)((random() % MAX_SLEEP_TIME) + 1);
// 		eating(s_time);
// 		printf("Philosopher %d is thinking\n", num);
// 		return_forks(num);
// 		++t_loop;
// 	}
// 	return NULL;
// }

// void	create_philo()
// {
// 	int 	i;

// 	for (i = 0;i < NUM; i++)
// 		pthread_create(&tid[i], NULL, philosoper, (void *)&thread_id[i]);
// }

// int 	main()
// {
// 	int 	i;
// 	init();
// 	create_philo();

// 	for (i = 0; i < NUM; i++)
// 		pthread_join(tid[i], NULL);
// 	return 0;
// }

pthread_t 	g_thread;
pthread_mutex_t *g_lock;
pthread_mutex_t *p_lock;


void	*routine(void *arg)
{
	int 	i = 0;
	// pthread_mutex_lock(g_lock);
	while (i < 5)
	{
		pthread_mutex_lock(g_lock);
		printf("%d Start\n", i);
		sleep(1);
		// pthread_mutex_unlock(p_lock);
		// pthread_mutex_lock(p_lock);
		printf("%d End\n", i);
		// pthread_mutex_unlock(p_lock);
		pthread_mutex_unlock(g_lock);
		i++;
	}
	return (NULL);
}

int 	main()
{
	g_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	// p_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(g_lock, NULL);
	// pthread_mutex_init(p_lock, NULL);
	// pthread_mutex_lock(g_lock);

	pthread_create(&g_thread, NULL, routine, NULL);
	pthread_detach(g_thread);
	usleep(100);

	pthread_mutex_lock(g_lock);
	// pthread_mutex_unlock(g_lock);
}