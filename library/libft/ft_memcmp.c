/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 09:43:24 by cpirlot           #+#    #+#             */
/*   Updated: 2016/11/26 09:43:25 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t num)
{
	size_t          i;
	size_t          j;
	unsigned char   *str1;
	unsigned char   *str2;

	i = 0;
	j = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (num--)
	{
		if (str1[i] != str2[j])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
		j++;
	}
	return (0);
}
