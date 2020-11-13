/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:49:28 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/13 21:46:11 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

static void	clean_all(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_mutex_destroy(data->forks[i]);
		free(data->philos[i]);
		free(data->forks[i]);
		i++;
	}
	free(data->forks);
	free(data->philos);
	exit(0);
}

void		*check(void *d)
{
	int		i;
	size_t	cur_time;
	t_data	*data;

	data = (t_data*)d;
	while (1)
	{
		i = 0;
		while (i < data->philo_nbr)
		{
			cur_time = get_time();
			if (cur_time - data->philos[i]->last_eat > (size_t)data->life_time)
			{
				timestamp(i, "is dead\n", data);
				clean_all(data);
				return ((void*)0);
			}
			i++;
		}
	}
}
