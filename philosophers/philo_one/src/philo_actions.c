/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:30:17 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/11/26 14:56:13 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

int		is_sleep(int action)
{
	if (action == SLEEP_ACTION)
	{
		g_forks -= 2;
		return (1);
	}
	return (0);
}

int		is_eat(int action)
{
	if (action == EAT_ACTION)
	{
		g_forks += 2;
		return (1);
	}
	return (0);
}

int		is_die(int action)
{
	if (action == DIE_ACTION)
	{
		g_forks -= 2;
		return (1);
	}
	return (0);
}

int		is_thinking(int action)
{
	if (action == THINK_ACTION)
	{
		g_forks -= 2;
		return (1);
	}
	return (0);
}

int		is_do_action(int action)
{
	if (action == SLEEP_ACTION)
		return (is_sleep(action) && (g_action += 3));
	else if (action == EAT_ACTION)
		return (is_eat(action) && (g_action -= 1));
	else if (action == DIE_ACTION)
		return (is_die(action) && (g_action = 0));
	else if (action == THINK_ACTION)
		return (is_thinking(action) && (g_action -= 2));
	return (-1);
}