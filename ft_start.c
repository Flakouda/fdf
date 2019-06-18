/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florientakoudad <florientakoudad@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 00:00:39 by florientako       #+#    #+#             */
/*   Updated: 2019/06/19 00:54:38 by florientako      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_start(char *str)
{
	t_map	fdf;

	ft_bzero(&fdf, sizeof(t_map));
	ft_create_image(&fdf, str);
	return (0);
}