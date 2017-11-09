/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 09:41:38 by cpirlot           #+#    #+#             */
/*   Updated: 2016/11/26 09:41:39 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_strncmp(const char *s1, const char *s2, size_t max)
{
	size_t i;

	i = 0;
	while (i < max - 1 && s1[i] != '\0' && (unsigned char)s1[i] == (unsigned char)s2[i])
	{
		i++;
	}
	if (max)
		return (unsigned char)s1[i] - (unsigned char)s2[i];
	return (0);
}
