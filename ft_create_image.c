/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florientakoudad <florientakoudad@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 00:12:48 by florientako       #+#    #+#             */
/*   Updated: 2019/06/19 01:06:22 by florientako      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_fill_image(int fd, t_map *fdf)
{
	fdf->map = ft_tab_coord(fdf->nbline, fd);
	return (0);
}

static int	count_line(t_map *fdf, char *str)
{
	int		fd;
	char	*line;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &line))
	{
		fdf->nbline++;
		free(line);
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}


int		ft_create_image(t_map *fdf, char *str)
{
	int		fd;

	count_line(fdf, str);
	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	ft_fill_image(fd, fdf);
	return (0);
}