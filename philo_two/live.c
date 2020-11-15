/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 02:52:05 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/15 19:55:00 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		take_fork(t_philo *philo)
{
	sem_wait(((t_data*)philo->data)->self_eat);
	sem_wait(((t_data*)philo->data)->forks);
	sem_wait(((t_data*)philo->data)->forks);
	philo->print_time = get_time() - ((t_data*)philo->data)->start_time;
	timestamp(philo->index, "has taken a fork", (t_data*)philo->data);
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
		take_fork(philo);
		timestamp(philo->index, "is eating", (t_data*)philo->data);
		philo->last_eat = get_time();
		wait_for(((t_data*)philo->data)->eating_time);
		philo->count_of_eating++;
		sem_post(((t_data*)philo->data)->self_eat);
		sem_post(((t_data*)philo->data)->forks);
		sem_post(((t_data*)philo->data)->forks);
		philo->print_time = get_time() - ((t_data*)philo->data)->start_time;
		timestamp(philo->index, "is sleeping", (t_data*)philo->data);
		wait_for(((t_data*)philo->data)->sleeping_time);
		philo->print_time = get_time() - ((t_data*)philo->data)->start_time;
		timestamp(philo->index, "is thinking", (t_data*)philo->data);
	}
	return ((void*)0);
}
