/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:31:59 by tandrieu          #+#    #+#             */
/*   Updated: 2016/03/02 16:43:16 by tandrieu         ###   ########.fr       */
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

t_poire			*ft_create_elem(char *line)
{
	t_poire		*rob_stark;
	int			j;

	j = ft_strlen(line);
	rob_stark = malloc(sizeof(t_poire));
	if (rob_stark)
	{
		rob_stark->twilight_sucks = line;
		rob_stark->arrow_sucks = malloc(sizeof(int) * j);
		rob_stark->next = NULL;
	}
	return (rob_stark);
}

int				ft_isok(char *str)
{
	int		i;

	i = 0;
	if (('9' < str[i] || str[i] < '0') && str[i] != '-')
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
		ft_putstr("\033[31mSorry, wrong number of argument.\n\033[00m");
		ft_putstr("Available map :\n");
		ft_putstr("               level_1 - 5\n");
		ft_putstr("\033[32mUse ./wolf3d \"map_name\"\n\033[00m");
	}
	if (i == 2)
		ft_putstr("\033[31mSorry, map not well formated.\n\033[00m");
	if (i == 3)
		ft_putstr("\033[31mSorry, that file doesn't exist.\n\033[00m");
}
