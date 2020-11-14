/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:49:28 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/14 03:22:12 by jeldora          ###   ########.fr       */
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
	int		count_of_eating;
	
	count_of_eating = 0;
	data = (t_data*)d;
	while (1)
	{
		i = 0;
		while (i < data->philo_nbr)
		{
			cur_time = get_time();
			if (data->eating_nbr != -1 && data->philos[i]->count_of_eating >= data->eating_nbr)
				count_of_eating++;
			if (count_of_eating == data->philo_nbr)
			{
				data->philos[0]->last_eat = get_time(); 
				timestamp(0, "Exit", data);
				exit(0);
			}
				
			if (cur_time - data->philos[i]->last_eat > (size_t)data->life_time)
			{
				data->philos[i]->print_time = get_time() - data->start_time;	
				timestamp(i, "is dead\n", data);
				clean_all(data);
				return ((void*)0);
			}
			i++;
		}
		count_of_eating = 0;
	}
}
