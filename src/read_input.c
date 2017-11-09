/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 08:15:27 by cpirlot          #+#    #+#              */
/*   Updated: 2017/10/24 17:18:05 by cpirlot         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetri new_tetri()
{
    t_tetri tetri;

    if (!(tetri.block = (char *)malloc(sizeof(char) * 7)))
        error("Execution error");
    return(tetri);
}

static int	already_there(t_tetri tetri, t_tetri *tetri_array, int size)
{
	int i;

	i = 0;
	if (size == 0)
		return(0);
	while (i < size)
	{
		if (ft_strcmp(tetri.block, tetri_array[i].block) == 0 &&
			(tetri.width == tetri_array[i].width &&
			tetri.height == tetri_array[i].height))
			return(1);
		i++;
	}
	return(0);
}

/* Read from the input file block by block (20 char + \0) */

/* ####### SUPPRIMER ####### */
/* ####### SEGFAULT IF FILE EMPTY ####### */
/* ####### SUPPRIMER ####### */

void	read_input(const char *file, t_tetri *tetri_array)
{
	char	*input;
	char	**input_array;
	int		fd;
    int     nb_blocks;
    int     nb_read;
	int		i;
	int 	j;
	t_tetri	t;

	i = 0;
	j = 0;
	nb_blocks = 0;
	nb_read = 0;
	input = ft_strnew(21);
	if (!(input_array = (char **)malloc(sizeof(char*) * 26)))
			error("Execution error");
	while (i < 26)
	{
		input_array[i] = ft_strnew(21);
		i++;
	}
	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		close_file(fd);
		error("Execution error");
        exit(0);
	}
	
	while ((nb_read = read(fd, input, 21)) != 0 )
	{
        nb_blocks++;
        if (nb_blocks > 26)
            close_error(fd);
	    if (nb_read != 21 && nb_read != 20)
		 	close_error(fd);
		if (nb_read == 20)
	     	input[20] = '\0';
		if (nb_read == 21 && (input[20] != '\n' &&
		 input[20] != '\0'))
	     	close_error(fd);
		input_array[j] = ft_strdup(input);
		j++;
	    if (block_valid(input) == 1)
		{
			t = trim_tetri(input, new_tetri());
			if (already_there(t, tetri_array, i) == 0)
			{
				tetri_array[i] = t;
				i++;
			}
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
		ft_putstr(tetri_array[j].block);
		ft_putstr(" : ");
		ft_putnbr(tetri_array[j].height);
		ft_putstr(" ");
		ft_putnbr(tetri_array[j].width);
		ft_putstr(" block at index ");
		ft_putnbr(j);
		ft_putstr("\n");
		j++;
	}

/* ####### SUPPRIMER ####### */
}