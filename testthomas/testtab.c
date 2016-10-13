/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testtab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:47:49 by rluder            #+#    #+#             */
/*   Updated: 2016/10/13 20:37:59 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char		**create_map(char	*argv)
{
	int		i;
	int		fd;
	char	*line;
	char	**tab;

	i = 0;
	line = NULL;
	fd = open(argv, O_RDONLY);
	while(get_next_line(fd, &line))
		i++;
	ft_memdel((void**)&line);
	close(fd);
	tab = malloc(sizeof(char*) * (i + 1));
	i = 0;
	fd = open(argv, O_RDONLY);
	while(get_next_line(fd, &line))
	{
		tab[i] = ft_strdup(line);
		ft_memdel((void**)&line);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

