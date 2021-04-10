#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <semaphore.h>
#include <sys/time.h>

sem_t	*sem_test;

void	*thread(void *arg)
{
	sem_wait(sem_test);
	printf("\nEntered..\n");
  
    //critical section
    sleep(2);
      
    //signal
    printf("\nJust Exiting...\n");
    sem_post(sem_test);
	return (NULL);
}
int main(){
	const char *name = "FORK";
	sem_unlink(name);
	sem_test = sem_open(name, O_CREAT, 0660, 2);
	pthread_t t[2];
	sem_wait(sem_test);
	for (int i = 0; i < 2; i++)
	{
		pthread_create(&t[i], NULL, thread, NULL);
		pthread_detach(t[i]);
	}
	sem_wait(sem_test);
	sem_post(sem_test);
	// sem_destroy(&sem_test);
	return 0;
}