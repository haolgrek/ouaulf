/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:42:15 by rluder            #+#    #+#             */
/*   Updated: 2016/10/03 15:13:19 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft/libft.h"
#include "get_next_line.h"

int		**ft_create_btab(t_m m)
{
	int	**btab;
	int	i;

	i = 0;
	btab = (int**)malloc(sizeof(int*) * ((int)m.ysize + 1));
	while (i < (int)m.ysize)
	{
		btab[i] = &m.tab[i * (int)m.xsize];
		i++;
	}
	btab[i] = NULL;
	return (btab);
}

t_map		*ft_create_elem(char *file)
{
	t_map	*map;
	int		i;

	i = ft_strlen(file);
	map = malloc(sizeof(t_map));
	if (map)
	{
		map->line = file;
		map->spline = malloc(sizeof(int) * i);
		map->next = NULL;
	}
	return (map);
}

t_map		*ft_list_insert_back(t_map *map, char *file)
{
	t_map	*tmp;
	t_map	*tmp2;

	tmp = ft_create_elem(file);
	if (tmp)
	{		
		if (map)
		{
			tmp2 = map;
			while (tmp2->next)
				tmp2 = tmp2->next;
			tmp2->next = tmp;
		}
		else
			map = tmp;
	}
	return (map);
}

t_m		loadmap(char **argv)
{
	int		tab[2];
	char	*line;
	t_m		m1;
	t_m		m2;

	tab[0] = open(argv[1], O_RDONLY);
	while (get_next_line(tab[0], &line) != 0)
		m1 = ft_list_insert_back(m1, line);
	m2 = m1;
	while (m1)
	{
		tab[1] = 0;

	}
}
