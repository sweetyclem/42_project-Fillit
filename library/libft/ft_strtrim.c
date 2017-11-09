/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 09:41:10 by cpirlot           #+#    #+#             */
/*   Updated: 2016/11/26 09:41:11 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static bool	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (true);
	return (false);
}

char		*ft_strtrim(const char *s)
{
	const char		*temp;

	while (is_space(*s))
		s++;
	if (!*s)
		return (ft_strdup(""));
	temp = ft_strchr(s, '\0') - 1;
	while (is_space(*temp))
		temp--;
	return (ft_strsub(s, 0, temp - s + 1));
}
