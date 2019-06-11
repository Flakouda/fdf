/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floakoud <floakoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:45:26 by floakoud          #+#    #+#             */
/*   Updated: 2019/06/11 16:29:43 by floakoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_count(char *file)
{
	int	nb;
	int	i;

	nb = 0;
	i = -1;
	while (file[++i])
		if (file[i] == '\n')
			nb++;
	return (nb);
}

char	**file_to_tab(char *file)
{
	int		fd;
	char	**tab;
	char	*line;
	int		i;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl("Error when opening");
		exit(0);
	}
	tab = malloc(sizeof(**tab) * ft_count(file) - 1);
	while (get_next_line(fd, &line) == 1)
	{		
		tab[i] = *ft_strsplit(file, ' ');
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
