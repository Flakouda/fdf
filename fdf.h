/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floakoud <floakoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:08:17 by floakoud          #+#    #+#             */
/*   Updated: 2019/06/11 15:11:52 by floakoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_e
{	
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		ex;
	int		ey;
	int		Dx;
	int		Dy;
	int		Xincr;
	int		Yincr;
}				s_t;

int     main();

#endif
