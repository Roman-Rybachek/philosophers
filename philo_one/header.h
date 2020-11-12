/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:58:39 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/12 22:34:08 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct			s_philo
{
	/* data */
	pthread_t			id;			// id потока
	int					index;
	size_t				life_time; //Сколько уже отжил
	int					last_eat;
	int					is_dead;

	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;

}						t_philo;

typedef struct			s_data
{
	size_t				philo_nbr;
	size_t				life_time;
	size_t				eating_time;
	size_t				sleeping_time;
	size_t				eating_nbr;
	int					i;
	int					start_time;
	int					c_time;
	pthread_mutex_t		**forks; // Это вилки. Они мьютексы.
	t_philo				**philos; // Это философы.
}						t_data;

/* Utils */
size_t		ft_strlen(const char *s);
void		exit_with_message(char *message);
void		init(t_data *data, char **args, int argc);
int			ft_atoi(const char *str);
void		*pr_malloc(size_t size_of_type, size_t count);
int			ft_atoi(const char *str);
size_t		ft_nbr_len(int n);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		timestamp(int philo_nbr, char *str);
int			get_time();

/* Main */
void	*live(t_data *data);

#endif
