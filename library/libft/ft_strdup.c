
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 09:42:17 by cpirlot           #+#    #+#             */
/*   Updated: 2016/11/26 09:42:18 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup (const char *str)
{
	char    *dest;

	dest = (char *)malloc(sizeof(char) *(ft_strlen(str) + 1));
	if (dest)
	{
		ft_strcpy(dest, str);
		return (dest);
	}
	else
		return (NULL);
}
