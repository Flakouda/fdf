/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floakoud <floakoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:32:13 by floakoud          #+#    #+#             */
/*   Updated: 2019/06/11 15:22:58 by floakoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*ft_gnl(t_list **gnl, int fd)
{
	t_list *tmp;

	tmp = *gnl;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(gnl, tmp);
	tmp = *gnl;
	return (tmp);
}

static int		ft_display(char **line, t_list *lst)
{
	char	*tmp;
	int		i;

	if (!ft_strlen(lst->content))
		return (0);
	i = ft_strfind(lst->content, '\n');
	if (i != -1)
	{
		tmp = ft_strnew(i);
		ft_memcpy(tmp, lst->content, i);
		tmp[i] = '\0';
		*line = ft_strdup(tmp);
		free(tmp);
		tmp = ft_strdup(lst->content);
		free(lst->content);
		lst->content = ft_strdup(tmp + i + 1);
		free(tmp);
		tmp = NULL;
		return (1);
	}
	*line = ft_strdup(lst->content);
	ft_strclr(lst->content);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list		*gnl;
	t_list				*lst;
	char				tmp[BUFF_SIZE + 1];
	int					ret;

	if ((fd < 0 || line == NULL || BUFF_SIZE <= 0 || read(fd, tmp, 0) < 0))
		return (-1);
	lst = ft_gnl(&gnl, fd);
	*line = NULL;
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		if (!(lst->content = ft_strjoinfree(lst->content, tmp)))
			return (-1);
		if (ft_strchr(tmp, 0x0a))
			break ;
	}
	return (ft_display(line, lst));
}
