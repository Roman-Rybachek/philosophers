/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 02:52:05 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/13 02:58:58 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*live(void *d)
{
	int		nbr;
	t_data	*data;

	// Уточнить у Лехи насчет индеков
	data = (t_data*)d;
	nbr = data->i;
	while (1)
	{
		pthread_mutex_lock(data->philos[nbr]->l_fork);
		timestamp(nbr, "get left fork\n");

		pthread_mutex_lock(data->philos[nbr]->r_fork);
		timestamp(nbr, "get right fork\n");

		usleep(data->eating_time);
		data->philos[nbr]->last_eat = get_time();

		pthread_mutex_unlock(data->philos[nbr]->l_fork);
		timestamp(nbr, "put on left fork\n");
		
		pthread_mutex_unlock(data->philos[nbr]->r_fork);
		timestamp(nbr, "put on right fork\n");

		timestamp(nbr, "go to sleep\n");

		usleep(data->sleeping_time);
		timestamp(nbr, "wake up\n");
	}
	
	return ((void*)0);
}