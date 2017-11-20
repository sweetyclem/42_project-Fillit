/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:14:42 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/17 16:35:15 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map   *solve(t_map *map, t_tetri *ltetri)
{
	t_map   *m;
	int     x;
	int     y;

	x = 0;
	y = 0;
	if (ltetri == NULL)
		return(map);
	if(insert_tetri(map, ltetri, &x, &y))
	{
		if((m = solve(map, ltetri->next)))
			return (m);
		else
		{
			retire_tetri(map, ltetri, x, y);
			x++;
			y++;
		}
	}
	return (0);
}
