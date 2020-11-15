/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:49:28 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/15 19:51:20 by jeldora          ###   ########.fr       */
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
		free(data->philos[i]);
		i++;
	}
	free(data->philos);
	sem_unlink("Forks");
	sem_unlink("Self_eat");
	exit(0);
}

int			check_count_of_eating(int count_of_eating, t_data *data, int i)
{
	size_t cur_time;

	cur_time = get_time();
	if (count_of_eating == data->philo_nbr)
	{
		data->exit_status = 1;
		data->philos[0]->last_eat = get_time();
		timestamp(0, "Exit", data);
		exit(0);
	}
	if (cur_time - data->philos[i]->last_eat > (size_t)data->life_time)
	{
		data->exit_status = 1;
		data->philos[i]->print_time = get_time() - data->start_time;
		timestamp(i, "is dead\n", data);
		clean_all(data);
		return (0);
	}
	return (1);
}

void		*check(void *d)
{
	int		i;
	t_data	*data;
	int		count_of_eating;

	count_of_eating = 0;
	data = (t_data*)d;
	while (1)
	{
		i = 0;
		while (i < data->philo_nbr)
		{
			if (data->eating_nbr != -1 && data->philos[i]->count_of_eating \
			>= data->eating_nbr)
				count_of_eating++;
			if (!check_count_of_eating(count_of_eating, data, i))
				return ((void*)0);
			i++;
		}
		count_of_eating = 0;
	}
}
