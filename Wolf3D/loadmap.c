/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:42:15 by rluder            #+#    #+#             */
/*   Updated: 2016/09/21 17:04:59 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		**ft_create_btab(t_m m)
{
	int	**btab;
	int	i;

	i = 0;
	btab = (int**)malloc(sizeof(int*) * ((int)m.h + 1));
	while (i < (int)m.h)
	{
		btab[i] = &m.tab[i * (int)m.w];
		i++;
	}
	btab[i] = NULL;
	return (btab);
}

t_m		*ft_create_elem(char *file)
{
	t_m	*m;
	int	i;

	i = ft_strlen(file);
	m = malloc(sizeof(t_m));
	if (m)
	{
		m->line = file;
		m->spline = malloc(sizeof(int) * i);
		m->next = NULL;
	}
	return (m);
}

t_m		*ft_list_insert_back(t_m *m, char *file)
{
	t_m	*tmp;
	t_m	*tmp2;

	tmp = ft_create_elem(file);
	if (tmp)
	{		
		if (m)
		{
			tmp2 = m;
			while (tmp2->next)
				tmp2 = tmp2->next;
			tmp2->next = tmp;
		}
		else
			m = tmp;
	}
	return (m);
}

t_m		loadmap(char **argv)
{
	int		tab[2];
	char	*line;
	t_m		m1;
	t_m		m2;

	tab[0] = open(arg[1], O_RDONLY);
	while (get_next_line(tab[0], &line) != 0)
		m1 = ft_list_insert_back(m1, line);
	m2 = m1;
	while (m1)
	{
		tab[1] = 0;

	}
}
