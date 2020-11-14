/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:04:45 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/15 01:29:54 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		timestamp(int philo_index, char *str, t_data *data)
{
	char	*str_index;
	char	*str_time;
	char	*buf;
	int		len;

	str_time = ft_itoa(data->philos[philo_index]->print_time);
	str_index = ft_itoa(philo_index + 1);
	len = ft_strlen(str_time) + ft_strlen(str_index) + 4 + ft_strlen(str);
	buf = (char*)pr_malloc(1, len);
	*buf = '\0';
	ft_strlcat(buf, str_time, len);
	ft_strlcat(buf, " ", len);
	ft_strlcat(buf, str_index, len);
	ft_strlcat(buf, " ", len);
	ft_strlcat(buf, str, len);
	ft_strlcat(buf, "\n", len);
	write(1, buf, len);
	free(buf);
	free(str_time);
	free(str_index);
}
