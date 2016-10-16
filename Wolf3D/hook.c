/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:49:40 by rluder            #+#    #+#             */
/*   Updated: 2016/10/16 22:36:17 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mlx		*move_hook(int keycode, t_mlx *l)
{
	if (keycode == 13)
	{
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

t_mlx		*rot_hook_left(t_mlx *l)
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

t_mlx		*rot_hook_right(t_mlx *l)
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
