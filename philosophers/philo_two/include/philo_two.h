/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:15:23 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/11 11:01:13 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_TWO
# define PHILO_TWO

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
	int 				index_p;
	int					l_fork;
	int					r_fork;
	long int 			t_limit;
	sem_t 				*philo_sem;
	int 				is_eating;
}						t_philo;

int 					g_must_eat;

void					create_philo(t_philo *philo);
void					*ft_routine(void *arg);
int						ft_atoi(const char *str);
char					*ft_itoa(int n);
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *str);
int						is_valid(char **argv, int argc);
t_philo					*check_data(t_philo *philo, char **argv, int argc);
long					get_time();
t_philo					*ft_HandleData(t_philo *philo, char **argv, int argc);
void					*check_health(void *arg);
void					*count_eating_times(void *arg);
void					take_fork(t_philo *philo);
void					release_fork(t_philo *philo);
void					eat_action(t_philo *philo);
void					think_action(t_philo *philo);
void					sleep_action(t_philo *philo);
t_philo					*init_sem(t_philo *philo, t_content cont);
void					clean_all(t_philo *philo);
void					destroy_philo(t_philo *philo);
#endif
