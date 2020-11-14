/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 02:52:05 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/14 20:12:40 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	right_hand(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	philo->print_time = get_time() - ((t_data*)philo->data)->start_time;	
	timestamp(philo->index, "has taken a right fork", (t_data*)philo->data);
}

void	left_hand(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	philo->print_time = get_time() - ((t_data*)philo->data)->start_time;	
	timestamp(philo->index, "has taken a left fork", (t_data*)philo->data);
}

void	check_left(t_data *data, int i)
{
	if (data->philos[i - 1]->last_eat < data->philos[i]->last_eat)
		pthread_mutex_unlock(data->philos[i]->l_fork);
}

/* пускай, им не обязательно сразу есть, как только они получат вилки.
	Пускай, у них будет статус голода. Если сосед более голодный, ты вилка отдается ему 
	
	Пусть начинают есть как я задумал, через одного.
	Но, пускай они не сразу едят, когда у них есть доступ к вилкам, а только при 
	определенных условиях.
	1) Если я последний раз ел раньше, чем сосед, то я ем.
	

	Каждый философ может прогнозировать, когда он умрет.
	По идее, он должен получить обе вилки до того как истечет время жизни.

	Он также может проназировать, когда умрет сосед.

	Значит, мне нужно сделать цикл, который будет отслеживать оставшееся время.

	Отдавая вилку, философ должен учесть, хватит ли у него времени ждать, пока другой поест.

	Значит, делаю цикл, в котором смотрю сколько мне осталось. Если соседу осталось меньше,
	и я могу ждать, разлочю вилку.
*/


void	wait_for(size_t time_to_wait)
{
	size_t time;

	time = get_time();
	while (get_time() < time + time_to_wait)
		usleep(100);
}


void	*live(void *p)
{
	t_philo		*philo;

	philo = (t_philo*)p;
	while (1)
	{
		if (philo->index % 2 > 0)
		{
			left_hand(philo);
			right_hand(philo);
		}
		else
		{
			right_hand(philo);
			left_hand(philo);
		}

// оптимизировать вывод
		timestamp(philo->index, "is eating", (t_data*)philo->data);
	
		philo->last_eat = get_time(); 
		wait_for(((t_data*)philo->data)->eating_time);
		philo->count_of_eating++;
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);

		philo->print_time = get_time() - ((t_data*)philo->data)->start_time;	
		timestamp(philo->index, "is sleeping", (t_data*)philo->data);

		wait_for(((t_data*)philo->data)->sleeping_time);
		philo->print_time = get_time() - ((t_data*)philo->data)->start_time;	
		timestamp(philo->index, "is thinking", (t_data*)philo->data);
	}
	
	return ((void*)0);
}