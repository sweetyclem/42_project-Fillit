/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:37:11 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/17 08:44:33 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	read_input(const char *file, t_tetri *tetri_list)
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
			/* ####### SUPPRIMER ####### */
			ft_putstr("NEW BLOCK\n");
			ft_putstr("pos # nb 2 :");
			ft_putnbr(t.two.x);
			ft_putstr(", ");
			ft_putnbr(t.two.y);
			ft_putstr("\npos # nb 3 :");
			ft_putnbr(t.three.x);
			ft_putstr(", ");
			ft_putnbr(t.three.y);
			ft_putstr("\npos # nb 4 :");
			ft_putnbr(t.four.x);
			ft_putstr(", ");
			ft_putnbr(t.four.y);
			ft_putstr("\n");
		/* ####### SUPPRIMER ####### */
			tetri_list_add(&tetri_list, &t);
			(void)tetri_list;
			i++;
		}
		else
			close_error(fd);
	}
	if (input_array[nb_blocks - 1][20] != '\0')
		close_error(fd);
	close_file(fd);
}
