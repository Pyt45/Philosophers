#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/time.h>

// sem_t	*sem_test;

// void	*thread(void *arg)
// {
// 	sem_wait(sem_test);
// 	printf("\nEntered..\n");
  
//     //critical section
//     sleep(2);
      
//     //signal
//     printf("\nJust Exiting...\n");
//     sem_post(sem_test);
// 	return (NULL);
// }
// int main(){
// 	const char *name = "FORK";
// 	sem_unlink(name);
// 	sem_test = sem_open(name, O_CREAT, 0660, 2);
// 	pthread_t t[2];
// 	sem_wait(sem_test);
// 	for (int i = 0; i < 2; i++)
// 	{
// 		pthread_create(&t[i], NULL, thread, NULL);
// 		pthread_detach(t[i]);
// 		sleep(2);
// 	}
// 	sem_wait(sem_test);
// 	sem_post(sem_test);
// 	// sem_destroy(&sem_test);
// 	return 0;
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	j;
	size_t	k;
	size_t	size;

	j = 0;
	k = start;
	if (!s)
		return (NULL);
	if (!s[start])
		return (strdup(""));
	// size = strlen(s);
	// if (len > size)
	// 	len = size;
	if (!(ptr = (char *)malloc(((len - start) + 1) * sizeof(char))))
		return (NULL);
	while (j < (len - start))
	{
		ptr[j] = s[k++];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}


int main()
{
	int found = 0;
	int p = 0;
	int len = 1;
	char *line = strdup("echo hello k>     world|again okey;okey moha;zabaniyat");
	while (line[p])
	{
		if ((line[p] == ' ' || line[p] == '>' || line[p] == '|' || line[p] == ';' ))
			len++;
		p++;
	}
	printf("len = %d\n", len);
	char	**cmd = (char **)malloc(sizeof(char *) * len);
	int i = 0;
	int j = 0;
	int k = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != ';'  && line[i] != '|' && line[i] != '>' && line[i + 1] != '\0')
			i++;
		else
		{
			if (line[i + 1] == '\0')
				cmd[k] = ft_substr(line, j, i + 1);
			else
				cmd[k] = ft_substr(line, j, i);
			printf("j = %d i = %d s = |%s|\n", j, i, cmd[k]);
			j = i + 1;
			i++;
			k++;
		}
	}
	cmd[i] = NULL;
	// int k = 0;
	k = 0;
	while (k < len)
	{
		printf("%s\n", cmd[k]);
		k++;
	}
}