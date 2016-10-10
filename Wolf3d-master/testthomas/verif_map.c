/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 17:28:03 by rluder            #+#    #+#             */
/*   Updated: 2016/10/10 18:43:02 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				**ft_create_btab(t_st list)
{
	int		**btab;
	int		i;

	i = 0;
	btab = (int**)malloc(sizeof(int*) * ((int)list.h + 1));
	while (i < (int)list.h)
	{
		btab[i] = &list.tab[i * (int)list.w];
		i++;
	}
	btab[i] = NULL;
	return (btab);
}

t_map			*ft_create_elem(char *line)
{
	t_map		*map;
	int			j;

	j = ft_strlen(line);
	map = malloc(sizeof(t_map));
	if (map)
	{
		map->chartab = line;
		map->intab = malloc(sizeof(int) * j);
		map->next = NULL;
	}
	return (map);
}

int				ft_mapok(char *str)
{
	int		i;

	i = 0;
	if (('1' < str[i] || str[i] < '0') && str[i] != '-')
	{
		intel_print(2);
		return (0);
	}
	return (1);
}

int				check(char *str)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(str, O_RDONLY);
	ret = get_next_line(fd, &line);
	close(fd);
	return (ret);
}

void			intel_print(int i)
{
	if (i == 1)
	{
		ft_putendl("Wrong number of arguments");
		ft_putendl("Add either level/level_1.wolf or level/level_2.wolf\n");
	}
	if (i == 2)
		ft_putendl("Bad map\n");
	if (i == 3)
		ft_putendl("That map doesnt exist\n");
}
