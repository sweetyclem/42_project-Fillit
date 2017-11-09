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

static void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	error(char *message)
{
	ft_puterror(message);
	ft_puterror("\n");
}

void	close_file(int fd)
{
	if (close(fd) == -1)
		error("Execution error");
}

void close_error(int fd)
{
	error("error: incorrect file");
	close_file(fd);
    exit(0);
}