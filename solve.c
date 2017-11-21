/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:14:42 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/21 06:18:17 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static t_map	*solve_map(t_map *map, t_tetri *ltetri)
{
	int     x;
	int     y;

	x = 0;
	y = 0;
	if (ltetri == NULL)
		return(map);
	while (insert_tetri(map, ltetri, &x, &y) && y < map->size)
	{
		if(solve_map(map, ltetri->next))
			return (map);
		else
		{
			retire_tetri(map, ltetri, x, y);
			x++;
			if (x >= map->size)
			{
				x = 0;
				y++;
			}
		}
	}	
	return (0);
}

t_map	*solve(t_tetri *ltetri, unsigned int nb_tetri)
{
	t_map			*m;
	int	m_size;

	m = map_min(nb_tetri);
	m_size = m->size;
	while (!(m = solve_map(m, ltetri)))
	{
		m = map_new(++m_size);		
	}
	print_map(m);
	return (m);
}
