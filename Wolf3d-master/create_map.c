/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 14:33:39 by tandrieu          #+#    #+#             */
/*   Updated: 2016/02/25 10:19:52 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_poire			*ft_list_insert_back(t_poire *walter_white, char *line)
{
	t_poire	*tmp;
	t_poire	*tmp2;

	tmp = ft_create_elem(line);
	if (tmp)
	{
		if (walter_white)
		{
			tmp2 = walter_white;
			while (tmp2->next)
				tmp2 = tmp2->next;
			tmp2->next = tmp;
		}
		else
			walter_white = tmp;
	}
	return (walter_white);
}

t_st			fill_tab(int **tab, t_poire *list, int i, int k)
{
	int			x;
	int			y;
	int			n;
	int			m;
	t_st		tinky_winky;

	n = 0;
	m = 0;
	x = 0;
	while (x < k)
	{
		y = 0;
		while (y < i)
		{
			tab[x][y] = list->arrow_sucks[y];
			y++;
		}
		list = list->next;
		x++;
	}
	tinky_winky.map_width = i;
	tinky_winky.map_height = k;
	tinky_winky.map = tab;
	return (tinky_winky);
}

t_st			tabulatoire(t_poire *rob_stark_mother, int i)
{
	int		**tab;
	int		j;
	int		k;
	t_poire	*begin;

	j = 0;
	k = 0;
	begin = rob_stark_mother;
	while (rob_stark_mother)
	{
		rob_stark_mother = rob_stark_mother->next;
		k++;
	}
	tab = malloc(sizeof(int*) * k);
	while (j < k)
		tab[j++] = malloc(sizeof(int) * i);
	return (fill_tab(tab, begin, i, k));
}

t_st			han_shot_first(char **argv)
{
	char	*line;
	t_poire	*jon_snow;
	t_poire	*rob_stark_wife;
	int		v[2];

	jon_snow = NULL;
	v[0] = open(argv[1], O_RDONLY);
	while (get_next_line(v[0], &line) != 0)
		jon_snow = ft_list_insert_back(jon_snow, line);
	rob_stark_wife = jon_snow;
	while (jon_snow)
	{
		v[1] = 0;
		jon_snow->tab_split = ft_strsplit(jon_snow->twilight_sucks, ' ');
		while (jon_snow->tab_split[v[1]] != '\0')
		{
			if (ft_isok(jon_snow->tab_split[v[1]]) == 0)
				exit(0);
			jon_snow->arrow_sucks[v[1]] = ft_atoi(jon_snow->tab_split[v[1]]);
			v[1]++;
		}
		ft_memdel((void**)&jon_snow->twilight_sucks);
		jon_snow = jon_snow->next;
	}
	return (tabulatoire(rob_stark_wife, v[1]));
}

void			empty_btab(t_st st)
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
}
