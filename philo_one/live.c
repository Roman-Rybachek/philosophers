/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 02:52:05 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/13 22:34:35 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*live(void *p)
{
	t_philo		*philo;

	// Уточнить у Лехи насчет индеков
	philo = (t_philo*)p;
	while (1)
	{
		pthread_mutex_lock(philo->l_fork);

		philo->print_time = get_time() - ((t_data*)philo->data)->start_time;	
		timestamp(philo->index, "has taken a fork", (t_data*)philo->data);
		pthread_mutex_lock(philo->r_fork);

		philo->print_time = get_time() - ((t_data*)philo->data)->start_time;	
		timestamp(philo->index, "has taken a fork", (t_data*)philo->data);
		timestamp(philo->index, "is eating", (t_data*)philo->data);
		philo->last_eat = get_time(); 
		usleep(((t_data*)philo->data)->eating_time * 1000);
 
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);

		philo->print_time = get_time() - ((t_data*)philo->data)->start_time;	
		timestamp(philo->index, "is sleeping", (t_data*)philo->data);

		usleep(((t_data*)philo->data)->sleeping_time * 1000);
		philo->print_time = get_time() - ((t_data*)philo->data)->start_time;	
		timestamp(philo->index, "is thinking", (t_data*)philo->data);
	}
	
	return ((void*)0);
}