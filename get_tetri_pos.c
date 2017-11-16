/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:36:15 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/16 16:19:38 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	get_tetri_pos(char *block, t_tetri tetri)
{
	int		i;
	int		j;
	int		index_first;
	int		nb_pounds;

	i = 0;
	j = 0;
	nb_pounds = 0;
	index_first = -1;
	while (block[i] != '\0')
	{
		if (block[i] == '#')
		{
			if (index_first == -1)
			{
				index_first = i;
				nb_pounds = 1;
			}
			if (nb_pounds == 1 && i != index_first)
			{
				tetri.two.x = (i + 1) / 5 - (index_first + 1) / 5;
				tetri.two.y = (i + 1) % 5 - (index_first + 1) % 5;
				nb_pounds = 2;
			}
			else if (nb_pounds == 2)
			{
				tetri.three.x = (i + 1) / 5 - (index_first + 1) / 5;
				tetri.three.y = (i + 1) % 5 - (index_first + 1) % 5;
				nb_pounds = 3;
			}
			else if (nb_pounds == 3)
			{
				tetri.four.x = (i + 1) / 5 - (index_first + 1) / 5;
				tetri.four.y = (i + 1) % 5 - (index_first + 1) % 5;
				nb_pounds = 4;
			}
			j++;
		}
		i++;
	}
	return (tetri);
}
