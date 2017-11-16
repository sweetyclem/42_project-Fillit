/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:14:42 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/16 17:48:56 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     solve(t_map map, t_tetri ltetri)
{
    while (ltetri.next)
    {
        if(!(insert_tetri(map, ltetri)))
        {
            
        }
    }
}
