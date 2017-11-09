/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 09:41:19 by cpirlot           #+#    #+#             */
/*   Updated: 2016/11/26 09:41:20 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t     nbWords(const char *s, char c)
{
	size_t i;
	size_t nbwords;

	i = 0;
	nbwords = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (s[i -1] == c || i == 0)
			{
				nbwords++;
			}
		}
		i++;
	}
	return (nbwords);
}

char            **ft_strsplit(char const *s, char c)
{
	size_t      nb_words;
	char        *start;
	char        **result;

	nb_words = nbWords((char *)s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	start = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (start != s)
				*(result++) = ft_strsub(start, 0, s - start);
			start = (char *)s + 1;
		}
		++s;
	}
	if (start != s)
		*(result++) = ft_strsub(start, 0, s - start);
	*result = NULL;
	return (result - nb_words);
}
