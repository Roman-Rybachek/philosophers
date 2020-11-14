/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:58:39 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/15 01:25:11 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct			s_philo
{
	pthread_t			id;
	int					index;
	size_t				life_time;
	size_t				last_eat;
	int					is_dead;
	void				*data;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	int					have_l;
	int					have_r;

	size_t				print_time;
	int					count_of_eating;

	long				to_death;

}						t_philo;

typedef struct			s_data
{
	int					philo_nbr;
	int					life_time;
	int					eating_time;
	int					sleeping_time;
	int					eating_nbr;
	int					i;
	int					start_time;
	int					c_time;
	pthread_mutex_t		**forks;
	t_philo				**philos;
	pthread_t			id;
}						t_data;

size_t					ft_strlen(const char *s);
void					exit_with_message(char *message);
void					init(t_data *data, char **args, int argc);
int						ft_atoi(const char *str);
char					*ft_itoa(int n);
void					*pr_malloc(size_t size_of_type, size_t count);
size_t					ft_nbr_len(int n);
void					ft_putstr_fd(char *s, int fd);
void					ft_putchar_fd(char c, int fd);
void					timestamp(int philo_nbr, char *str, t_data *data);
size_t					get_time();
size_t					ft_strlcat(char *dst, const char *src, size_t size);

void					*live(void *data);
void					*check(void *d);

#endif
