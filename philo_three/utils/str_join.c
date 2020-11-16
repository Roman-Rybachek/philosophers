/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 14:15:18 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/14 04:49:18 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*str_join(char *s1, char *s2)
{
	char	*s;
	int		i;

	i = 0;
	s = (char*)pr_malloc(1, ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		s[(i + ft_strlen(s1) + 1)] = s2[i];
		i++;
	}
	s[(i + ft_strlen(s1) + 1)] = '\0';
	free(s1);
	free(s2);
	return (s);
}
