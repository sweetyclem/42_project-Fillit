/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:36:28 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/17 08:50:03 by cpirlot          ###   ########.fr       */
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
		tetri_list = new_tetri_list();
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
