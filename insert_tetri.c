/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:53:04 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/16 16:13:10 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned int	insert_tetri_pos(t_map map, t_tetri tetri,unsigned int x, unsigned int y)
{
	if(m[x][y] =! '.')
		return (0);
	if(m[x + tetri.two.x][y + tetri.two.y] =! '.')
		return (0);
	if(m[x + tetri.three.x][y + tetri.three.y] =! '.')
		return (0);
	if(m[x + tetri.four.x][y + tetri.four.y] =! '.')
		return (0);
	m[x][y] = tetri.letter;
	m[x+tetri.two.x][y+tetri.two.y] = tetri.letter;
	m[x+tetri.tree.x][y+tetri.tree.y] = tetri.letter;
	m[x+tetri.four.x][y+tetri.four.y] = tetri.letter;
	return (1);
}

void	insert_tetri(t_map map, t_tetri tetri)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (y < map.size)
	{	while (x < map.size)
		{
			if(insert_tetri_pos(map, tetri, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
