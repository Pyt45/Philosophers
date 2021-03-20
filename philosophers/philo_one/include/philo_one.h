/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:15:23 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/03/20 20:58:28 by ayoub            ###   ########.fr       */
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

typedef struct			s_content
{
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_eat;	
}						t_content;

typedef struct			s_thread
{
	t_content			content;
	int					num_of_philo;
	struct timeval		start;
	struct timeval		end;
	pthread_t			thread[5];
	int					id;
	int					l_fork;
	int					r_fork;
	long int 			t_limit;
	pthread_mutex_t		*philo_mutex;
	// struct	s_thread	*next;
	// struct	s_thread	*prev;
}						t_thread;

int						*g_forks;
int						g_die;
int						g_action;
int						n_philo;
t_thread 				g_philo[5];
pthread_t				th_health;
// pthread_mutex_t			*g_LeftLock;
// pthread_mutex_t			*g_RightLock;
// pthread_mutex_t			*g_PrintLock;
// pthread_mutex_t			g_lock;
pthread_mutex_t			*p_lock;
pthread_mutex_t			eat_lock;
pthread_mutex_t			*g_lock_died;

void					*philo_life(void *arg);
int						is_sleep(int action);
int						is_eat(int action);
int						is_die(int action);
int						is_thinking(int action);
int						is_do_action(int action);
void					create_philo(t_thread *l_thread);
int						ft_atoi(const char *str);

#endif
