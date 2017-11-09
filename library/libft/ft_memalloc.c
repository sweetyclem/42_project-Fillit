/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 09:43:34 by cpirlot           #+#    #+#             */
/*   Updated: 2016/11/26 09:43:35 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memalloc(size_t size)
{
	void *tmp;

	if (!(tmp = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}
