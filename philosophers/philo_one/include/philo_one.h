/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:15:23 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/13 16:34:07 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <math.h>
# include <errno.h>

# define				TAKE_FORK " has taken a fork"
# define				EAT	" is eating"
# define				SLEEP " is sleeping"
# define				THINK " is thinking"
# define				DIED " died"
# define				END_EAT " reached the limit of eats"

typedef struct s_content
{
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_eat;
	int					e_c;
	int					is_eating;
	int					n_philo;
	int					done;
	long				start;
	long				s_start;
	pthread_mutex_t		*msg_mutex;
	pthread_mutex_t		*die_mutex;
	pthread_mutex_t		*fork_mutex;
	pthread_t			e_th;
	pthread_t			philo_health;
}						t_content;

typedef struct s_philo
{
	t_content			content;
	long int			s_start;
	pthread_t			thread;
	int					id;
	int					l_fork;
	int					r_fork;
	long int			t_limit;
	pthread_mutex_t		*philo_mutex;
}						t_philo;

void					create_philo(t_philo *philo);
int						ft_atoi(const char *str);
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *str);
int						is_valid(char **argv, int argc);
void					*routine(void *arg);
void					sleep_action(t_philo *philo);
void					think_action(t_philo *philo);
void					eat_action(t_philo *philo);
void					release_fork(t_philo *philo);
void					take_fork(t_philo *philo);
void					*check_count(void *arg);
void					*check_health(void *arg);
t_philo					*init(t_philo *philo, t_content cont);
t_philo					*check_data(t_philo *philo, char **argv, int argc);
t_philo					*init_mutex(t_philo *philo, t_content cont);
t_philo					*ft_handle_data(t_philo *philo, char **argv, int argc);
long					get_time(void);
void					destroy_env(t_philo *philo);
void					print_status(long t, char *msg, t_philo *ph, int bl);

#endif
