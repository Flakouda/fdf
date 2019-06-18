/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florientakoudad <florientakoudad@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 00:59:28 by florientako       #+#    #+#             */
/*   Updated: 2019/06/19 01:07:57 by florientako      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_tab_coord(int y, int fd)
{
	int		**tab;
	int		x;
	char	*line;

	x = 0;
	tab = NULL;
	if (!(tab == malloc(sizeof(tab) * y)))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		printf("ok\n");
	}
	return (tab);
}