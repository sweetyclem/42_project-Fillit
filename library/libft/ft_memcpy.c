/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 09:43:21 by cpirlot           #+#    #+#             */
/*   Updated: 2016/11/26 09:43:21 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
    char    *bdest;
    char    *bsrc;

	i = 0;
    bdest = (char *)dest;
    bsrc = (char *)src;

    while (i < n)
    {
        bdest[i] = bsrc[i];
        i++;
    }
    return (bdest);
}
