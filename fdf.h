/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floakoud <floakoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:08:17 by floakoud          #+#    #+#             */
/*   Updated: 2019/06/11 16:04:09 by floakoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

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

int     		main(int argc, char **argv);
char			**file_to_tab(char *file);

#endif
