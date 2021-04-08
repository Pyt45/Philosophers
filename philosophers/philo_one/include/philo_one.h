/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:15:23 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/08 23:20:04 by ayoub            ###   ########.fr       */
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
# include <errno.h>

# define				SLEEP_ACTION 1
# define				EAT_ACTION 2
# define				DIE_ACTION 3
# define				THINK_ACTION 4
# define				TAKE_FORK " has taken a fork"
# define				EAT	" is eating"
# define				SLEEP " is sleeping"
# define				THINK " is thinking"

typedef struct			s_content
{
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_eat;
	int 				e_eat;
	int 				r_eat;
	int 				n_philo;
	int 				reached_count;
	long 				start;
	long 				s_start;
	pthread_mutex_t		*msg_mutex;
	pthread_mutex_t		*die_mutex;
	pthread_mutex_t		*fork_mutex;
	pthread_mutex_t 	*eat_mutex;
	pthread_t 			eat_thread;
	pthread_t 			philo_health;
}						t_content;

typedef struct			s_philo
{
	t_content			content;
	int					num_of_philo;
	struct timeval		start;
	struct timeval		end;
	long int 			s_start;
	pthread_t			thread;
	int					id;
	int					l_fork;
	int					r_fork;
	long int 			t_limit;
	pthread_mutex_t		*msg_mutex;
	pthread_mutex_t		*philo_mutex;
	int 				is_eating;
}						t_philo;


void					*philo_life(void *arg);
void					create_philo(t_philo *philo);
int						ft_atoi(const char *str);
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *str);
int						is_valid(char **argv, int argc);
t_philo					*check_data(t_philo *philo, char **argv, int argc);
t_philo					*init(t_philo *philo, t_content cont);
t_philo					*ft_HandleData(t_philo *philo, char **argv, int argc);
long					get_time();
#endif
