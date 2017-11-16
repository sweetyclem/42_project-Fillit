/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:34:57 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/16 16:44:53 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point new_point(void)
{
	t_point point;

	if (!(point.x = (int)malloc(sizeof(int))))
		error();
	if (!(point.y = (int)malloc(sizeof(int))))
		error();
	point.x = 0;
	point.y = 0;
	return (point);
}

t_tetri	*new_tetri_list(void)
{
	t_tetri *list;

	if (!(list->letter = (char)malloc(sizeof(char))))
		error();
	list->two = new_point();
	list->three = new_point();
	list->four = new_point();
	list->next = NULL;
	return (list);
}
