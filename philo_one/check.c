/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:49:28 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/12 22:09:40 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check(t_data *data)
{
	int		i;
	int		cur_time;

	i = 0;
	while (1)
	{
		while (i < data->philo_nbr)
		{
			cur_time = get_time()
			if (cur_time - data->philos[i]->last_eat > data->life_time)
			{
				timestamp(i, "is dead\n");
				// остановка мьютексов и потоков
			}
		}
		
	}
}