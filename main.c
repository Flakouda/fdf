/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floakoud <floakoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:23:04 by floakoud          #+#    #+#             */
/*   Updated: 2019/06/11 16:27:28 by floakoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

int     deal_key(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(0);
	return(0);
}

int     main(int argc, char **argv)
{
	//void	*mlx_ptr;
	//void	*win_ptr;
	char	**tab;

	if (argc != 2)
	{
		ft_putendl("usage : ./FDF file");
		return (-1);
	}
	tab = file_to_tab(argv[1]);
	ft_print_words_tables(tab);
	/*mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FDF");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 200, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);*/
	return (0);
}
