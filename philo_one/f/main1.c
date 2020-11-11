/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 00:17:01 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/11 20:01:06 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		eating()
{
	pthread_mutex_lock(data->philo[i]->l_hand);
	print("I has a fork");
	pthread_mutex_lock(data->philo[i]->r_hand);
	print("I has a fork");
	
	gettimeofday(struct timeval las_eat);
	time = las_eat.ms / 1000 + las_eat.sec * 1000;
	print(time [i] "I am eating");
	usleep(time_to_eating);
	pthread_mutex_unlock(data->philo[i]->r_hand);
	pthread_mutex_unlock(data->philo[i]->l_hand);
	
}

void *live(t_data *data)
{
	las_eat = start_time;
	while (1)
	{
		if (eating())
			break ;
		if (sleeping())
			break ;
		write("thinking");
	}
	return (NULL);
}

int	start_live()
{
	ptread_t id;
	int i= 0;
	while(i < data->philo_nbr)
	{
		gettimeofday(start_time);
		pthread_create(&id, NULL, &live, data);
		i++;
	} 
}

int		check_death(t_philo)
{
	int time;
	struct timeval now_time;
	gettimeofday(&now_time);
	time = (now_time.tv_sec - philo.las_eat.tv_sec) * 1000 + (now_time.tv_usec - philo.las_eat.tv_usec) / 1000;
	if (time > dime_to_dead)
		return (1);
}

int		check_live()
{
	while (1)
	{
		int i = 0;
		while (i < data->philo_nbr)
		{
			check_death();
			if (data->philo[i]->ret)
				return (clear && str_error);
		}
	}
}

int		main(int argc, char **argv)
{
	t_data data;

	if(init())
		return (str_error);
	if (start_live())
		return (str_error);
	if (check_live())
		return (0);
	

	// Проверяем аргументы на некорректный ввод
	if (argc < 5 || argc > 6)
		exit_with_message("Invalid arguments number\n");
	// Инициализируем всю хуйню
	// Запускаем симуляцию

	// Что нужно сделать для начала?
	/*
		Для начала нужно понять, что такое вилки,
		в виде чего они должны присутствовать в программе,
		как философы будут брать эти вилки.


		Философ должен брать сразу две вилки. Нельзя, чтобы
		каждый философ взял по одной вилки. Тогда не один не сможет поесть.

		Мы поочереди запускаем новый поток философа с циклом жизни поесть-поспать-думать
	*/


	return (0);
}