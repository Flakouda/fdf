/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florientakoudad <florientakoudad@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:08:17 by floakoud          #+#    #+#             */
/*   Updated: 2019/06/19 01:06:42 by florientako      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct	s_map
{	
	int		**map;
	int		nbline;
	int		nbnumbers;
}				t_map;



int     		main(int argc, char **argv);
int				ft_checkfile(char *str);
int				ft_start(char *str);
int				ft_create_image(t_map *fdf, char *str);
int				**ft_tab_coord(int y, int fd);


#endif
