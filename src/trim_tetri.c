/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 08:15:27 by cpirlot          #+#    #+#              */
/*   Updated: 2017/10/24 17:18:05 by cpirlot         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void initialize_point(t_point *point, int x, int y)
{
    point[0].x = x;
    point[0].y = y;
 }

/* Add a block to the list of tetriminos */
/* current index % 5 gives position on the x, / 5 position on the y */
/* the height/width of the tetriminos will be max - min + 1 for 0 based index */

t_tetri trim_tetri(char *block, t_tetri tetri)
{
    int     i;
    int     j;
    t_point pos;
    t_point min;
    t_point max;  
    
    i = 0;
    j = 0;
    initialize_point(&pos, 0, 0);
    initialize_point(&max, 0, 0);
    initialize_point(&min, -1, -1);
    while (block[i] != '\0')
    {
        pos.x = i % 5;
        pos.y = i / 5;
        if (block[i] == '#') {
            if (min.x == -1)
                min.x = pos.x;
            if (min.y == -1)
                min.y = pos.y;
            if (pos.x > max.x)
                max.x = pos.x;
            if (pos.y > max.y)
                max.y = pos.y;
        }
        i++;
    }
    tetri.height = max.y - min.y + 1;
    tetri.width = max.x - min.x + 1;
    i = 0;
    while (block[i] != '\0') {
        pos.x = i % 5;
        pos.y = i / 5;
        if ((pos.x >= min.x && pos.x <= max.x) &&
         (pos.y >= min.y && pos.y <= max.y))
        {
            tetri.block[j] = block[i];
            j++;
        }
        i++;
    }
    tetri.block[j] = '\0';
    return tetri;
}
