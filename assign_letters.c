/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_letterss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:59:00 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/20 13:32:34 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*assign_letters(t_tetri *tetri_list)
{
	char	c;
	t_tetri	*tmp;

	c = 'A';
	tmp = tetri_list;

	while (tmp || c <= 'Z')
	{
		tmp->letter = c;
		ft_putchar(tmp->letter);
		c++;
		tmp = tmp->next;
	}
	return (tetri_list);
}
