/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:36:28 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/16 16:34:18 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_tetri	*tetri_list;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (1);
	}
	else if (argc == 2)
	{
		if (!(tetri_list = (t_tetri *)malloc(sizeof(t_tetri) * 26)))
			return (1);
		read_input(argv[1], tetri_list);
		/*
		while (i <= 25)
		{
			free(tetri_list[i].block_square);
			free(tetri_list);
		}
		free(tetri_list); */
	}
	return (0);
}
