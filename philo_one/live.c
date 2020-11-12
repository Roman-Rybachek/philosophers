/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 02:52:05 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/12 22:37:48 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*live(t_data *data, int index)
{
	int		cur_time;
	int		nbr;

	// Уточнить у Лехи насчет индеков
	nbr = data->i;
	while (1)
	{
		cur_time = get_time();
		pthread_mutex_lock(data->philos[nbr]->l_fork);
		timestamp(nbr, "get left fork\n");

		pthread_mutex_lock(data->philos[nbr]->r_fork);
		timestamp(nbr, "get right fork\n");

		usleep(data->eating_time);
		pthread_mutex_unlock(data->philos[nbr]->l_fork);

		timestamp(nbr, "put on left fork\n");
		pthread_mutex_unlock(data->philos[nbr]->r_fork);

		timestamp(nbr, "put on right fork\n");
		timestamp(nbr, "go to sleep\n");

		usleep(data->sleeping_time);
		timestamp(nbr, "wake up\n");
	}
	// Ест
	/* берем время,  */
	// Спит
	// Конец (ждет пока не освободятся вилки снова, и в это время думает)

	
	return ;
}