/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:15:01 by amaindro          #+#    #+#             */
/*   Updated: 2016/10/14 14:07:09 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char	**map_gen(int level)
{
	int		i;
	int		fd;
	char	*line;
	char	**tab;

	line = NULL;
	if (level == 1)
		fd = open("maps/lvl1", O_RDONLY);
	if (level == 2)
		fd = open("maps/lvl2", O_RDONLY);
	i = 0;
	tab = malloc(sizeof(char*) * 13);
	while (get_next_line(fd, &line))
	{
		tab[i] = ft_strdup(line);
		ft_memdel((void**)&line);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int		**tab_to_tab2d(t_mlx l)
{
	int		i;
	int		**tab2d;

	i = 0;
	tab2d = malloc(sizeof(int*) * 1000);
	while (i < 1000)
	{
		tab2d[i] = &l.tab[i * 1000];
		i++;
	}
	tab2d[i] = NULL;
	return (tab2d);
}

void	free_all(t_mlx *l)
{
	ft_memdel((void**)&l->tex[0]);
	ft_memdel((void**)&l->tex[1]);
	ft_memdel((void**)&l->tex[2]);
	ft_memdel((void**)&l->tex[3]);
	ft_memdel((void**)&l->tex[4]);
	ft_memdel((void**)&l->tex[9]);
	ft_memdel((void**)&l->map);
	ft_memdel((void**)&l->tab);
}

int		key_hook(int keycode, t_mlx *l)
{
	if (keycode == 53)
	{
		system("killall afplay");
		free_all(l);
		exit(0);
	}
	if (keycode == 13 || keycode == 1)
		move_hook(keycode, l);
	if (keycode == 0)
		rot_hook_left(l);
	if (keycode == 2)
		rot_hook_right(l);
	mlx_clear_window(l->mlx, l->win);
	*l = print_map(*l);
	mlx_put_image_to_window(l->mlx, l->win, l->link, 0, 0);
	mlx_put_image_to_window(l->mlx, l->win, l->lb_link, 0, 0);
	mlx_string_put(l->mlx, l->win, 350, 15, 0xFFFFFF, l->s1 = ft_itoa(l->s[2]));
	mlx_string_put(l->mlx, l->win, 575, 15, 0xFFFFFF, l->s2 = ft_itoa(l->s[1]));
	mlx_string_put(l->mlx, l->win, 450, 15, 0xFFFFFF, l->s3 = ft_itoa(l->s[0]));
	mlx_string_put(l->mlx, l->win, 50, 15, 0xFFFFFF, "lvl");
	mlx_string_put(l->mlx, l->win, 100, 15, 0xFFFFFF, l->sl = ft_itoa(l->lvl));
	free_str(l);
	return (0);
}

int		main(void)
{
	t_mlx	l;

	system("afplay -v 2 sounds/calm.mp3&");
	l.s[0] = 0;
	l.s[1] = 0;
	l.s[2] = 0;
	l.lvl = 1;
	l.mlx = mlx_init();
	l.win = mlx_new_window(l.mlx, 1000, 1000, "Wolf");
	l.link = mlx_new_image(l.mlx, 1000, 1000);
	l.tab = (int*)mlx_get_data_addr(l.link, &l.bits, &l.size, &l.endian);
	l.tab2d = tab_to_tab2d(l);
	l.map = map_gen(l.lvl);
	l.pos_y = 2;
	l.pos_x = 2;
	l.dir_x = -1;
	l.dir_y = 0;
	l.plane_x = 0;
	l.plane_y = 0.66;
	l = print_map(create_tex(l));
	mlx_hook(l.win, 2, 1, key_hook, &l);
	mlx_put_image_to_window(l.mlx, l.win, l.link, 0, 0);
	mlx_put_image_to_window(l.mlx, l.win, l.lb_link, 0, 0);
	mlx_loop(l.mlx);
	return (0);
}
