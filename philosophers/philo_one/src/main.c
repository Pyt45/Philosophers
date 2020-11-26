/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:14:36 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/11/26 14:22:27 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

t_thread	*new_thread(t_thread *prev, int num_philo, int t_die, int t_eat, int t_sleep)
{
	t_thread 	*thread;

	if (!(thread = (t_thread *)malloc(sizeof(t_thread))))
		return (NULL);
	thread->num_of_philo = num_philo;
	thread->content.time_to_die = t_die;
	thread->content.time_to_eat = t_eat;
	thread->content.time_to_sleep = t_sleep;
	thread->next = NULL;
	thread->prev = prev;
	if (prev)
		prev->next = thread;
	return (thread);
}

void	print_content(t_thread *l_thread)
{
	t_thread 	*tmp;
	int			i;

	tmp = l_thread;
	i = 0;
	while (tmp)
	{
		printf("--> num = %d t_die = %d t_eat = %d t_sleep = %d\n",
		tmp->num_of_philo,
		tmp->content.time_to_die,
		tmp->content.time_to_eat,
		tmp->content.time_to_sleep);
		tmp = tmp->next;
		i++;
	}
}

t_thread	*create_threads(int num_philo, int t_die, int t_eat, int t_sleep, t_thread *l_thread)
{
	int			i;
	t_thread	*tmp;
	t_thread	*head;
	
	head = NULL;
	i = -1;
	tmp = l_thread;
	while (++i < num_philo)
	{
		tmp = new_thread(tmp, num_philo, t_die, t_eat, t_sleep);
		if (!head)
			head = tmp;
	}
	head->prev = tmp;
	tmp->next = head;
	return (head);
}

int		main(int argc, char **argv)
{
	t_thread 	*l_thread;
	int			num_philo;
	int			t_die;
	int			t_eat;
	int			t_sleep;

	l_thread = NULL;
	num_philo = atoi(argv[1]);
	t_die = atoi(argv[2]);
	t_eat = atoi(argv[3]);
	t_sleep = atoi(argv[4]);
	l_thread = create_threads(num_philo, t_die, t_eat, t_sleep, l_thread);
	// print_content(l_thread);
	create_philo(l_thread);
	return (0);	
}