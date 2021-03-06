/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 15:39:42 by rluder            #+#    #+#             */
/*   Updated: 2016/10/14 14:25:29 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*t_map			*ft_list_insert_back(t_map *map, char *line)
{
	t_map	*tmp;
	t_map	*tmp2;

	tmp = ft_create_elem(line);
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

t_st			fill_tab(int **tab, t_map *list, int i, int k)
{
	int			x;
	int			y;
	int			n;
	int			m;
	t_st		s;

	n = 0;
	m = 0;
	x = 0;
	ft_bzero(&s, sizeof(t_st));
	while (x < k)
	{
		y = 0;
		while (y < i)
		{
			tab[x][y] = list->intab[y];
			y++;
		}
		list = list->next;
		x++;
	}
	s.map_width = i;
	s.map_height = k;
//	s.map = tab;
	return (s);
}

t_st			tabulatoire(t_map *map, int i)
{
	int		**tab;
	int		j;
	int		k;
	t_map	*begin;

	j = 0;
	k = 0;
	begin = map;
	while (map)
	{
		map = map->next;
		k++;
	}
	tab = malloc(sizeof(int*) * k);
	while (j < k)
		tab[j++] = malloc(sizeof(int) * (i - 1));
	return (fill_tab(tab, begin, i, k));
}*/

char		**create_chain(char	*argv, t_st r)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**tab;

	i = 0;
	j = 0;
	line = NULL;
	fd = open(argv, O_RDONLY);
	while(get_next_line(fd, &line))
		i++;
	r.map_height = i - 1;
	ft_memdel((void**)&line);
	close(fd);
	tab = malloc(sizeof(char*) * (i + 1));
	i = 0;
	fd = open(argv, O_RDONLY);
	while(get_next_line(fd, &line))
	{
		tab[j] = ft_strdup(line);
		ft_memdel((void**)&line);
		j++;
	}
	tab[j] = NULL;
	r.map_width = j - 1;
	return (tab);
}

int			**intab(t_st r)
{
	int	i;
	int	**intab;

	i = 0;
	intab = malloc(sizeof(int*) * r.h);
	while (i < r.h)
	{
		intab[i] = &r.tab[i * r.h];
		i++;
	}
	intab[i] = NULL;
	return (intab);
}

/*int			**create_chain(char **argv, t_st r)
{
	int		fd;
	int		i;
	int		j;
	int		k;
	int		l;
	char	*line;
	int		**intab;

	ft_putendl("start");
	i = 0;
	j = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	ft_putendl("open");
	while (get_next_line(fd, &line) != 0)
		i++;
	ft_memdel((void**)&line);
	r.map_height = i / 2;
	ft_putendl("ivalue");
	close(fd);
	ft_putendl("close");
	intab = ft_memalloc(sizeof(int*) * (i + 1));
	ft_putendl("memallocintab");
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	ft_putendl("open2");
	while (get_next_line(fd, &line) != 0)
	{
		k = 0;
		l = 0;
		ft_putendl("inwhile");
		ft_putstr("line is ");
		ft_putendl(line);
		i = ft_strlen(line);
		intab[j] = ft_memalloc(sizeof(int) * i);
		while(line[k])
		{
			if (line[k] == '1')
			{
				intab[j][l] = 1;
				k++;
				l++;
			}
			else if (line[k] == '0')
			{
				intab[j][l] = 0;
				k++;
				l++;
			}
			else if (line[k] == ' ')
			{
				k++;
			}
//			else if (line[k] != '\0')
//			{
//				ft_putendl("map is nope");
//				exit (0);
//			}
		}
		ft_putendl("endcalc");
		ft_memdel((void**)&line);
		j++;
	}
	r.map_width = i;
	ft_putendl("endwhile");
	intab[j] = NULL;
	ft_putendl("endintabnull");
	i = 0;
	j = 0;
	while (intab[j] != NULL)
	{
		i = 0;
		while (i < r.map_width)
		{
			ft_putnbr(intab[j][i]);
			i++;
		}
		j++;
		ft_putchar('\n');
	}
	ft_putendl("endcreate");
	return (intab);
}

	
//	tab[j] = ft_atoi(ft_strsplit(ft_strdup(line), ' '));
//		ft_memdel((void**)&line);
//	}
//	tab[j] = NULL;*/

/*	char	*line;
	t_map	*map1;
	t_map	*map2;
	int		v[2];

	map1 = NULL;
	v[0] = open(argv[1], O_RDONLY);
	while (get_next_line(v[0], &line) != 0)
	{
		map1 = ft_list_insert_back(map1, line);
		ft_memdel((void**)&line);
	}
	map2 = map1;
	while (map1)
	{
		v[1] = 0;
		map1->tab_split = ft_strsplit(map1->chartab, ' ');
		while (map1->tab_split[v[1]] != '\0')
		{
			if (ft_mapok(map1->tab_split[v[1]]) == 0)
				exit(0);
			map1->intab[v[1]] = ft_atoi(map1->tab_split[v[1]]);
			v[1]++;
		}
		map1 = map1->next;
	}
	return (tabulatoire(map2, v[1]));*/
//}

/*void			empty_btab(t_st st)
{
	int x;
	int y;

	y = 0;
	while (y < st.h)
	{
		x = 0;
		while (x < st.w)
		{
			st.btab[y][x] = 0;
			x++;
		}
		y++;
	}
}*/
