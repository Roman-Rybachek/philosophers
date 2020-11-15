/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:40:23 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/11 01:19:20 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

size_t		ft_strlen(const char *s)
{
	char *start;

	start = (char*)s;
	while (s && *s != '\0')
		s++;
	return (s - start);
}
