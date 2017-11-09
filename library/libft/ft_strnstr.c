/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 09:41:25 by cpirlot           #+#    #+#             */
/*   Updated: 2016/11/26 09:41:26 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (s2[j] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && len > 0)
	{
		while (s1[i] == s2[j])
		{
			i++;
			j++;
			if (s2[j] == '\0')
				return (char *)s1 + (i - ft_strlen(s2));
		}
		j = 0;
		i++;
		len--;
	}
	return (NULL);
}
