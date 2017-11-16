/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 09:40:53 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/16 08:00:02 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct  s_tetriminos 
{
    int     width;
    int     height;
    char    *block;
}               t_tetri;

typedef struct  s_point 
{
    int     x;
    int     y;
}               t_point;

void	read_input(const char *file, t_tetri *tetri_array);
t_tetri trim_tetri(char *block, t_tetri tetri);
int     block_valid(char *block);
void	error(char *message);
void	close_file(int fd);
void close_error(int fd);

#endif // FILLIt_H
