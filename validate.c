/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:36:56 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/21 07:02:20 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_pound(char *block, int pos)
{
	if ((pos >= 0 || pos < 21) && block[pos] == '#')
		return (1);
	return (0);
}

int			check_char(char c, int i)
{
	if (c != '.' && c != '#' &&
		c != '\n' && c != '\0')
		return (0);
	if (i % 5 == 4 && c != '\n')
		return (0);
	return (1);
}

int			block_valid(char *block)
{
	int	nb_pounds;
	int	nb_lines;
	int	i;

	i = 1;
	nb_pounds = 0;
	nb_lines = 0;
	if (block[0] != '.' && block[0] != '#')
		return (0);
	while (block[i++] != '\0')
	{
		if (!check_char(block[i], i))
			return (0);
		if (i % 5 == 0 && block[i] == '\n')
			nb_lines++;
		else
			return (0);
		if (i % 5 != 0 && (block[i] != '.' || block[i] != '#'))
			return (0);
		if (is_pound(block, i))
		{
			nb_pounds++;
			if (is_pound(block, i + 1) == 0 && is_pound(block, i + 5) == 0 &&
				is_pound(block, i - 1) == 0 && is_pound(block, i - 5) == 0)
				return (0);
		}
	}
	if (nb_pounds > 4)
		return (0);
	return (nb_lines != 4 ? 0 : 1);
}
