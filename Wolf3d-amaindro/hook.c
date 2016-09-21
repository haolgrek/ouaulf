/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:37:51 by amaindro          #+#    #+#             */
/*   Updated: 2016/03/20 19:15:29 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_mlx	*collect_x(t_mlx *l)
{
	char	ore;
	int		i;

	ore = l->map[(int)(l->pos_x + l->dir_x * l->d.move_speed)][(int)(l->pos_y)];
	l->map[(int)(l->pos_x + l->dir_x * l->d.move_speed)][(int)(l->pos_y)] = '0';
	l->s[ore - '3'] += 1;
	if (l->s[2] == 1 && l->s[0] == 4 && l->s[1] == 9
			&& l->lvl == 1)
	{
		l->lvl = 2;
		l->pos_x = 2;
		l->pos_y = 2;
		i = 0;
		while (l->map[i])
			ft_memdel((void**)&l->map[i++]);
		ft_memdel((void**)&l->map);
		l->map = map_gen(l->lvl);
	}
	return (l);
}

t_mlx	*collect_y(t_mlx *l)
{
	char	ore;
	int		i;

	ore = l->map[(int)(l->pos_x)][(int)(l->pos_y + l->dir_y * l->d.move_speed)];
	l->map[(int)(l->pos_x)][(int)(l->pos_y + l->dir_y * l->d.move_speed)] = '0';
	l->s[ore - '3'] += 1;
	if (l->s[2] == 1 && l->s[0] == 4 && l->s[1] == 9
			&& l->lvl == 1)
	{
		l->lvl = 2;
		l->pos_x = 2;
		l->pos_y = 2;
		i = 0;
		while (l->map[i])
			ft_memdel((void**)&l->map[i++]);
		ft_memdel((void**)&l->map);
		l->map = map_gen(l->lvl);
	}
	return (l);
}

t_mlx	*move_hook(int keycode, t_mlx *l)
{
	if (keycode == 13)
	{
		if (l->map[(int)(l->pos_x + l->dir_x * l->d.move_speed)]
				[(int)(l->pos_y)] > '2')
			collect_x(l);
		if (l->map[(int)(l->pos_x)][(int)(l->pos_y + l->dir_y *
					l->d.move_speed)] > '2')
			collect_y(l);
		if (l->map[(int)(l->pos_x + l->dir_x * l->d.move_speed)]
				[(int)(l->pos_y)] == '0')
			l->pos_x += l->dir_x * l->d.move_speed;
		if (l->map[(int)(l->pos_x)][(int)(l->pos_y + l->dir_y *
					l->d.move_speed)] == '0')
			l->pos_y += l->dir_y * l->d.move_speed;
	}
	if (keycode == 1)
	{
		if (l->map[(int)(l->pos_x - l->dir_x * l->d.move_speed)]
				[(int)l->pos_y] == '0')
			l->pos_x -= l->dir_x * l->d.move_speed;
		if (l->map[(int)l->d.pos_x][(int)(l->pos_y - l->dir_y *
					l->d.move_speed)] == '0')
			l->pos_y -= l->dir_y * l->d.move_speed;
	}
	return (l);
}

t_mlx	*rot_hook_left(t_mlx *l)
{
	l->olddir_x = l->dir_x;
	l->dir_x = l->dir_x * cos(l->d.rot_speed) - l->dir_y *
		sin(l->d.rot_speed);
	l->dir_y = l->olddir_x * sin(l->d.rot_speed) + l->dir_y *
		cos(l->d.rot_speed);
	l->oldplane_x = l->plane_x;
	l->plane_x = l->plane_x * cos(l->d.rot_speed) - l->plane_y *
		sin(l->d.rot_speed);
	l->plane_y = l->oldplane_x * sin(l->d.rot_speed) + l->plane_y *
		cos(l->d.rot_speed);
	return (l);
}

t_mlx	*rot_hook_right(t_mlx *l)
{
	l->olddir_x = l->dir_x;
	l->dir_x = l->dir_x * cos(-l->d.rot_speed) - l->dir_y *
		sin(-l->d.rot_speed);
	l->dir_y = l->olddir_x * sin(-l->d.rot_speed) + l->dir_y *
		cos(-l->d.rot_speed);
	l->oldplane_x = l->d.plane_x;
	l->plane_x = l->plane_x * cos(-l->d.rot_speed) - l->plane_y *
		sin(-l->d.rot_speed);
	l->plane_y = l->oldplane_x * sin(-l->d.rot_speed) + l->plane_y *
		cos(-l->d.rot_speed);
	return (l);
}
