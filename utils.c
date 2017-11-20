/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:34:57 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/20 13:40:44 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point	new_point(void)
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

	if (!(list = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	list->letter = '\0';
	list->two = new_point();
	list->three = new_point();
	list->four = new_point();
	list->next = NULL;
	return (list);
}

t_tetri	new_tetri(void)
{
	t_tetri tetri;

	tetri.letter = '\0';
	tetri.two = new_point();
	tetri.three = new_point();
	tetri.four = new_point();
	tetri.next = NULL;
	return (tetri);
}

void	tetri_list_add(t_tetri **begin_list, t_tetri *tetri)
{
	t_tetri	*tmp;

	tmp = *begin_list;
	if (*begin_list)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = tetri;
	}
}
