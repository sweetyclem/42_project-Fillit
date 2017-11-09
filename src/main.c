/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 08:15:27 by cpirlot          #+#    #+#              */
/*   Updated: 2017/10/24 17:18:05 by cpirlot         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	//int 	i;
	t_tetri	*tetri_array;

	//i = 0;
    if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (1);
	}
	else if (argc == 2)
	{
		if (!(tetri_array = (t_tetri *)malloc(sizeof(t_tetri) * 26)))
			return (1);
		read_input(argv[1], tetri_array);
		/* create_smallest_square(&tetri_array)
		while (i <= 25)
		{
			free(tetri_array[i].block_square);
			free(tetri_array);
		}
		free(tetri_array); */
	}	

	return (0);
}
