/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florientakoudad <florientakoudad@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:38:22 by florientako       #+#    #+#             */
/*   Updated: 2019/06/17 18:35:53 by florientako      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_spaces(char *str, char c)
{
	int		spaces;
	int		numbers;
	int		i;

	spaces = 0;
	i = 0;
	numbers = 0;
	printf("%s\n", str);
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			printf("spaces is : %c\n", str[i]);
			printf("case is : %d\n", i);
			spaces++;
		}
		if (str[i] != c && str[i] != '-')
			numbers++;
		i++;
	}
	printf("%d\n", spaces);
	printf("%d\n", numbers);
	if (spaces != numbers - 1)
		return (-1);
	return (spaces);
}

static int	check_line(char *str, char *line)
{
	int		count;
	int		fd;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	get_next_line(fd, &line);
	if ((count = count_spaces(line, ' ') == -1))
	{
		ft_putendl("Map invalid, wrong numbers of spaces.");
		return (-1);
	}
	while (get_next_line(fd, &line))
	{
		if (count != count_spaces(line, ' '))
		{
			ft_putendl("Map invalid, wrong line.");
			return (-1);
		}
		free(line);
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}

static int	check_data(char *str, char *line)
{
	int		ret;
	int		fd;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	ret = get_next_line(fd, &line);
	if (ret == 0 || ret == -1)
	{
		ft_putendl("Void file");
		return (-1);
	}
	while (get_next_line(fd, &line))
	{
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}

int			ft_checkfile(char *str)
{
	char	*line;

	line = "\0";
	if (check_data(str, line) == -1)
		return (-1);
	if (check_line(str, line) == -1)
		return (-1);
	return (0);
}