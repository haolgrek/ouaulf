/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:11:33 by rluder            #+#    #+#             */
/*   Updated: 2016/10/16 22:37:23 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mlx		draw(int x, int height, t_mlx l, t_data d)
{
	int		i;
	int		d1;
	int		color;

	i = 0;
	while (i < 1000)
	{
		l.tab2d[i][x] = (i < 500) ? 0x00AFFF : 0x5F5F5F;
		i++;
	}
	i = 500 - height / 2;
	i = (i < 0) ? 0 : i;
	while (i < 500 + height / 2 && i < 1000)
	{
		color = 0x00FF00;
		if (d.side == 0)
			color = 0x00F0F0;
		if (d.side == 1 && d.raydir_y < 0)
			color = 0x7F7F7F;
		if (d.side == 0 && d.raydir_x > 0)
			color = 0x0000FF;
		l.tab2d[i++][x] = color;
	}
	return (l);
}

t_data		data_init(t_data d, t_mlx l)
{
	d.move_speed = 0.2;
	d.rot_speed = 0.1;
	d.pos_x = l.pos_x;
	d.pos_y = l.pos_y;
	d.dir_x = l.dir_x;
	d.dir_y = l.dir_y;
	d.plane_x = l.plane_x;
	d.plane_y = l.plane_y;
	d.x = 0;
	return (d);
}

t_data		change_ray(t_data d)
{
	d.camera_x = 2 * (double)d.x / 1000 - 1;
	d.raypos_x = d.pos_x;
	d.raypos_y = d.pos_y;
	d.raydir_x = d.dir_x + d.plane_x * d.camera_x;
	d.raydir_y = d.dir_y + d.plane_y * d.camera_x;
	d.map_x = (int)d.raypos_x;
	d.map_y = (int)d.raypos_y;
	d.deltadist_x = sqrt(1 + (d.raydir_y * d.raydir_y) /
			(d.raydir_x * d.raydir_x));
	d.deltadist_y = sqrt(1 + (d.raydir_x * d.raydir_x) /
			(d.raydir_y * d.raydir_y));
	d.hit = 0;
	return (d);
}

t_data		hit(t_data d, t_mlx l)
{
	while (d.hit == 0)
	{
		if (d.sidedist_x < d.sidedist_y)
		{
			d.sidedist_x += d.deltadist_x;
			d.map_x += d.step_x;
			d.side = 0;
		}
		else
		{
			d.sidedist_y += d.deltadist_y;
			d.map_y += d.step_y;
			d.side = 1;
		}
		d.hit = l.map[d.map_x][d.map_y] - '0';
	}
	return (d);
}

t_mlx		print_map(t_mlx l)
{
	t_data	d;

	d = data_init(d, l);
	while (d.x < 1000)
	{
		d = change_ray(d);
		d = check_steps(d);
		d = hit(d, l);
		d = check_side(d, &l);
		d.lineheight = (int)1000 / d.perpwalldist;
		draw(d.x, d.lineheight, l, d);
		d.x++;
	}
	l.d = d;
	return (l);
}
