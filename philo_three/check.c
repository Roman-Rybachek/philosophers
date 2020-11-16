/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:49:28 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/16 23:12:59 by jeldora          ###   ########.fr       */
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

void		*check(void *p)
{
	t_philo		*philo;
	int			count_of_eating;
	t_data		*data;

	count_of_eating = 0;
	philo = (t_philo*)p;
	data = (t_data*)philo->data;
	if (!check_count_of_eating(count_of_eating, data, philo->index))
		return ((void*)0);
	i++;

	count_of_eating = 0;
}
