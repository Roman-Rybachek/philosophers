/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 01:10:18 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/11 01:22:13 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/* Нужно привести к указателю нужного типа */
void		*pr_malloc(size_t size_of_type, size_t count) {
	void *p = malloc(size_of_type * count);
	if (!p)
	{
		write(2, "Malloc error\n", ft_strlen("Malloc error\n"));
		exit(1);
	}
	return (p);
}