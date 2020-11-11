/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:10:27 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/11 20:26:12 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		init(t_data *data, char **args, int argc)
{
	data->philo_nbr = (size_t)ft_atoi(args[1]); // number of philosophers
	data->life_time = (size_t)ft_atoi(args[2]); // время до смерти
	data->eating_time = (size_t)ft_atoi(args[3]);  
	data->sleeping_time = (size_t)ft_atoi(args[4]);
	if (argc == 6)
		data->eating_nbr = (size_t)ft_atoi(args[5]);


}