/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:37:11 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/16 15:55:46 by cpirlot          ###   ########.fr       */
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

t_tetri	new_tetri(void)
{
	t_tetri tetri;

	if (!(tetri.letter = (char)malloc(sizeof(char))))
		error();
	tetri.two = new_point();
	tetri.three = new_point();
	tetri.four = new_point();
	return (tetri);
}

void	read_input(const char *file, t_tetri *tetri_array)
{
	char	*input;
	char	**input_array;
	int		fd;
	int		nb_blocks;
	int		nb_read;
	int		i;
	int		j;
	t_tetri	t;

	i = 0;
	j = 0;
	nb_blocks = 0;
	nb_read = 0;
	input = ft_strnew(21);
	if (!(input_array = (char **)malloc(sizeof(char*) * 26)))
		error();
	while (i < 26)
	{
		input_array[i] = ft_strnew(21);
		i++;
	}
	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		close_error(fd);
	while ((nb_read = read(fd, input, 21)) != 0)
	{
		nb_blocks++;
		if (nb_blocks > 26)
			close_error(fd);
		if (nb_read != 21 && nb_read != 20)
			close_error(fd);
		if (nb_read == 20)
			input[20] = '\0';
		if (nb_read == 21 && (input[20] != '\n' && input[20] != '\0'))
			close_error(fd);
		input_array[j] = ft_strdup(input);
		j++;
		if (block_valid(input) == 1)
		{
			t = get_tetri_pos(input, new_tetri());
			tetri_array[i] = t;
			i++;
		}
		else
			close_error(fd);
	}
	if (input_array[nb_blocks - 1][20] != '\0')
		close_error(fd);
	close_file(fd);
/* ####### SUPPRIMER ####### */
	j = 0;
	while (j < i)
	{
		ft_putstr("pos # nb 2 :");
		ft_putnbr(tetri_array[j].two.x);
		ft_putstr(", ");
		ft_putnbr(tetri_array[j].two.y);
		ft_putstr("\npos # nb 3 :");
		ft_putnbr(tetri_array[j].three.x);
		ft_putstr(", ");
		ft_putnbr(tetri_array[j].three.y);
		ft_putstr("\npos # nb 4 :");
		ft_putnbr(tetri_array[j].four.x);
		ft_putstr(", ");
		ft_putnbr(tetri_array[j].four.y);
		ft_putstr("\n");
		j++;
	}
/* ####### SUPPRIMER ####### */
}
