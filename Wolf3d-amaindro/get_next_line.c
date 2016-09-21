/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:05:57 by amaindro          #+#    #+#             */
/*   Updated: 2016/01/14 13:45:49 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			takeline(int fd, char **data)
{
	char	*tmp;
	char	buffer[BUFF_SIZE + 1];
	int		readret;

	ft_bzero(buffer, BUFF_SIZE + 1);
	while (ft_strchr(buffer, '\n') == NULL)
	{
		if ((readret = read(fd, buffer, BUFF_SIZE)) <= 0)
			return (readret);
		buffer[readret] = '\0';
		if ((tmp = ft_strjoin(*data, buffer)) == NULL)
			return (-1);
		ft_memdel((void**)data);
		*data = tmp;
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	char			*tmp;
	char			*ptr;
	int				tlret;
	static t_backup	backup;

	if (backup.fd != fd)
	{
		backup.fd = fd;
		ft_memdel((void**)&backup.data);
	}
	if ((tlret = takeline(fd, &backup.data)) == -1)
		return (tlret);
	if (backup.data == NULL)
		return (0);
	if (ft_strlen(backup.data) == 0)
		return (0);
	ptr = ft_strchr(backup.data, '\n');
	*line = ft_strndup(backup.data, ptr - backup.data);
	tmp = ft_strsub(backup.data, ptr - backup.data + 1, ft_strlen(backup.data));
	ft_memdel((void**)&backup.data);
	backup.data = tmp;
	return (1);
}
