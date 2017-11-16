/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 08:15:27 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/16 07:56:14 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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