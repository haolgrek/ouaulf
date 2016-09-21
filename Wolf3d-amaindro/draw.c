/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 12:05:13 by amaindro          #+#    #+#             */
/*   Updated: 2016/03/17 18:07:40 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_mlx		draw(int x, int height, t_mlx l, t_data d)
{
	int		i;
	int		d1;
	int		color;

	i = 0;
	while (i < 1000)
	{
		l.tab2d[i][x] = (i < 500) ? 0x00BFFF : 0x4F4F4F;
		i++;
	}
	i = 500 - height / 2;
	i = (i < 0) ? 0 : i;
	while (i < 500 + height / 2 && i < 1000)
	{
		d1 = i * 256 - 1000 * 128 + height * 128;
		l.tex_y = ((d1 * 16) / height) / 256;
		color = l.tex[d.hit - 1][16 * l.tex_y + l.tex_x];
		if (d.side == 1)
			color = (color >> 1) & 0x7F7F7F;
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
		if ((d.side == 0 && d.raydir_x > 0) || (d.side == 1 && d.raydir_y < 0))
			l.tex_x = 16 - l.tex_x - 1;
		d.lineheight = (int)1000 / d.perpwalldist;
		draw(d.x, d.lineheight, l, d);
		d.x++;
	}
	l.d = d;
	return (l);
}
