/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:49:28 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/13 02:30:13 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
}

void		*check(void *d)
{
	int		i;
	int		cur_time;
	t_data	*data;

	data = (t_data*)d;
	i = 0;
	while (1)
	{
		while (i < data->philo_nbr)
		{
			cur_time = get_time();
			if (cur_time - data->philos[i]->last_eat > data->life_time)
			{
				timestamp(i, "is dead\n");
				clean_all(data);
				return ((void*)0);
			}
		}
	}
}