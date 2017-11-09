/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 09:41:13 by cpirlot           #+#    #+#             */
/*   Updated: 2016/11/26 09:41:14 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strsub(const char *s, unsigned int start, size_t len)
{
	char    *str;
	unsigned int    i;

	i = 0;
	if (!(str = (char*) malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while ((i < len) && (s[start] != '\0'))
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
