/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florientakoudad <florientakoudad@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:23:04 by floakoud          #+#    #+#             */
/*   Updated: 2019/06/19 00:00:27 by florientako      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_putendl("Usage : ./fdf <file>");
	else if (ft_checkfile(argv[1]) == -1)
		return (-1);
	else
		ft_start(argv[1]);	
	return (0);
}
