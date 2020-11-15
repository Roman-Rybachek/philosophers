/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 02:52:05 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/15 22:04:37 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		right_hand(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	philo->print_time = get_time() - ((t_data*)philo->data)->start_time;
	timestamp(philo->index, "has taken a right fork", (t_data*)philo->data);
}

static void		left_hand(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	philo->print_time = get_time() - ((t_data*)philo->data)->start_time;
	timestamp(philo->index, "has taken a left fork", (t_data*)philo->data);
}

static void		left_or_right(t_philo *philo)
{
	if (philo->index % 2 > 0)
	{
		left_hand(philo);
		right_hand(philo);
	}
	else
	{
		right_hand(philo);
		left_hand(philo);
	}
}

static void		wait_for(size_t time_to_wait)
{
	size_t time;

	time = get_time();
	while (get_time() < time + time_to_wait)
		usleep(100);
}

void			*live(void *p)
{
	t_philo		*philo;

	philo = (t_philo*)p;
	while (1)
	{
		if (((t_data*)philo->data)->exit_status == 1)
			return ((void*)0);
	/*	if (((t_data*)philo->data)->eating_now >= ((t_data*)philo->data)->philo_nbr / 2)
			pthread_mutex_lock(((t_data*)philo->data)->self_eating);
		((t_data*)philo->data)->eating_now++;*/
		left_or_right(philo);
		timestamp(philo->index, "is eating", (t_data*)philo->data);
		philo->last_eat = get_time();
		wait_for(((t_data*)philo->data)->eating_time);
		philo->count_of_eating++;
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	/*	if (((t_data*)philo->data)->eating_now >= ((t_data*)philo->data)->philo_nbr / 2)
			pthread_mutex_unlock(((t_data*)philo->data)->self_eating);
		((t_data*)philo->data)->eating_now--;*/
		philo->print_time = get_time() - ((t_data*)philo->data)->start_time;
		timestamp(philo->index, "is sleeping", (t_data*)philo->data);
		wait_for(((t_data*)philo->data)->sleeping_time);
		philo->print_time = get_time() - ((t_data*)philo->data)->start_time;
		timestamp(philo->index, "is thinking", (t_data*)philo->data);
	}
	return ((void*)0);
}
