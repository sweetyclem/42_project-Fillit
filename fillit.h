/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:36:43 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/16 16:45:21 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_tetriminos
{
	t_point		two;
	t_point		three;
	t_point		four;
	char		letter;
}				t_tetri;

typedef struct	s_map
{
	int			size;
	char		**map;
}				t_map;

void			read_input(const char *file, t_tetri *tetri_array);
t_tetri			save_tetri(char *block, t_tetri tetri);
int				block_valid(char *block);
void			error();
void			close_file(int fd);
void			close_error(int fd);

#endif
