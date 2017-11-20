/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   B*y: *yvillepo <*yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:53:04 b*y *yvillepo          #+#    #+#             */
/*   Updated: 2017/11/17 15:46:42 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned int	insert_tetri_pos(t_map *m, t_tetri *tetri,unsigned int x, unsigned int y)
{
	if(m->map[x][y] =! '.')
		return (0);
	if(m->map[x + tetri->two.x][y + tetri->two.y] =! '.')
		return (0);
	if(m->map[x + tetri->three.x][y + tetri->three.y] =! '.')
		return (0);
	if(m->map[x + tetri->four.x][y + tetri->four.y] =! '.')
		return (0);
	m->map[x][y] = tetri->letter;
	m->map[x+tetri->two.x][y+tetri->two.y] = tetri->letter;
	m->map[x+tetri->three.x][y+tetri->three.y] = tetri->letter;
	m->map[x+tetri->four.x][y+tetri->four.y] = tetri->letter;
	return (1);
}

unsigned int		insert_tetri(t_map *map, t_tetri *tetri, int *x, int *y)
{
	while (*y < map->size)
	{	while (*x < map->size)
		{
			if(insert_tetri_pos(map, tetri, *x, *y))
				return (1);
			(*x)++;
		}
		(*y)++;
	}
	return (0);
}

unsigned int		retire_tetri(t_map *m, t_tetri *tetri, int x, int y)
{
	m->map[x][y] = '.';
	m->map[x+tetri->two.x][y+tetri->two.y] = '.';
	m->map[x+tetri->three.x][y+tetri->three.y] = '.';
	m->map[x+tetri->four.x][y+tetri->four.y] = '.';
}
