/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 09:43:27 by cpirlot           #+#    #+#             */
/*   Updated: 2016/11/26 09:43:28 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *str, int c, size_t n)
{
	char    *s;
	size_t  i;

	s = (char *)str;
	i = 0;
	while (n--)
	{
		if (s[i] == c)
			return (&s[i]);

		i++;
	}
	return (NULL);
}
