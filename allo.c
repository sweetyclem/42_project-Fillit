/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:36:59 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/17 16:41:16 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	free_map(t_map *map)
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


void	print_map(t_map *map)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->size)
	{
		while (j++ < map->size)
			ft_putchar(map->map[i][j]);
		ft_putchar('\n');
		i++;
	}
}

t_map	*map_new(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->map = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->map[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}
