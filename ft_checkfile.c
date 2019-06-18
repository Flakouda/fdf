/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florientakoudad <florientakoudad@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:38:22 by florientako       #+#    #+#             */
/*   Updated: 2019/06/18 23:57:52 by florientako      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_content(char *str)
{
	int 	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && str[i + 1] == ' ')
				return (-1);
		if (str[i] != '-' && str[i] != ' '
		&& !(str[i] <= '9' && str[i] >= '0'))
			return (-1);
		i++;
	}
	return (0);
}

static int	check_data(char *str, char *line)
{
	int		ret;
	int		fd;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	ret = get_next_line(fd, &line);
	if (check_content(line) == -1)
		return (-1);
	if (ret == 0 || ret == -1)
	{
		ft_putendl("Void file");
		return (-1);
	}
	while (get_next_line(fd, &line))
		if (check_content(line) == -1)
			return (-1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

int			ft_checkfile(char *str)
{
	char	*line;

	line = "\0";
	if (check_data(str, line) == -1)
	{
		ft_putendl("Map invalid");	
		return (-1);
	}
	return (0);
}