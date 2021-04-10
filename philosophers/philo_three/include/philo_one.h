/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:15:23 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/10 21:09:14 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_ONE
# define PHILO_ONE

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <math.h>
# include <semaphore.h>
# include <fcntl.h>
# include <errno.h>

# define				SLEEP_ACTION 1
# define				EAT_ACTION 2
# define				DIE_ACTION 3
# define				THINK_ACTION 4
# define				TAKE_FORK " has taken a fork"
# define				EAT	" is eating"
# define				SLEEP " is sleeping"
# define				THINK " is thinking"

# define				FORK_SEM "fork_sem"
# define				MSG_SEM "msg_sem"
# define				DIE_SEM "die_sem"

typedef struct			s_content
{
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_eat;
	int 				e_eat;
	int 				r_eat;
	int 				must_eat;
	int 				n_philo;
	int 				reached_count;
	int 				*e_arr;
	long 				start;
	// Sem
	long 				s_start;
	sem_t				*msg_sem;
	sem_t				*die_sem;
	sem_t				*fork_sem;
	sem_t 				*eat_sem;
	pthread_t 			eat_thread;
	pthread_t 			philo_health;
}						t_content;

typedef struct			s_philo
{
	t_content			content;
	int					num_of_philo;
	long int 			s_start;
	pthread_t			thread;
	int					id;
	long int 			t_limit;
	sem_t 				*philo_sem;
	int 				is_eating;
}						t_philo;
int 	g_must_eat;
void					*philo_life(void *arg);
void					create_philo(t_philo *philo);
int						ft_atoi(const char *str);
char					*ft_itoa(int n);
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *str);
int						is_valid(char **argv, int argc);
t_philo					*check_data(t_philo *philo, char **argv, int argc);
t_philo					*init_sem(t_philo *philo, t_content cont);
t_philo					*ft_HandleData(t_philo *philo, char **argv, int argc);
long					get_time();
#endif
