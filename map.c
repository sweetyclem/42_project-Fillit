/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:36:59 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/21 12:57:36 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	size_map(unsigned int nb_tetri)
{
	unsigned int	size_map;

	size_map = 0;
	nb_tetri = nb_tetri * 4;
	while (size_map * size_map < nb_tetri)
		size_map++;
	return (size_map);
}

void		print_map(t_map *map)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			ft_putchar(map->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void		free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->map[i]));
		i++;
	}
	ft_memdel((void **)&(map->map));
	ft_memdel((void **)&map);
}

t_map		*map_new(int size)
{
	t_map	*map;
	int		i;

	i = size;
	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	if (!(map->map = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	while (i--)
	{
		if (!(map->map[i] = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		ft_memset(map->map[i], '.', size);
	}
	return (map);
}

t_map		*map_min(unsigned int nb_tetri)
{
	int		size;

	size = size_map(nb_tetri);
	return (map_new(size));
}
