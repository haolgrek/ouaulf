/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:10:28 by rluder            #+#    #+#             */
/*   Updated: 2016/10/10 18:05:55 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			resolve(t_st r)
{
	int	x;
	int	y;
	double	color;

	x = 0;
	y = 0;
	while (x < r.w)
	{
		r.camerax = 2 * x / (double)r.w - 1;
		r.rayposx = r.posx;
		r.rayposy = r.posy;
		r.raydirx = r.dirx + r.planex * r.camerax;
		r.raydiry = r.diry + r.planey * r.camerax;
		r.mapx = (int)r.rayposx;
		r.mapy = (int)r.rayposy;
		r.deltadistx = sqrt(1 + (r.raydiry * r.raydiry) /
				(r.raydirx * r.raydirx));
		r.deltadisty = sqrt(1 + (r.raydirx * r.raydirx) /
				(r.raydiry * r.raydiry));
		r.hit = 0;
		if (r.raydirx < 0)
		{
			r.stepx = -1;
			r.sidedistx = (r.rayposx - r.mapx) * r.deltadistx;
		}
		else
		{
			r.stepx = 1;
			r.sidedistx = (r.mapx + 1.0 - r.rayposx) * r.deltadistx;
		}
		if (r.raydiry < 0)
		{
			r.stepy = -1;
			r.sidedisty = (r.rayposy - r.mapy) * r.deltadisty;
		}
		else
		{
			r.stepy = 1;
			r.sidedisty = (r.mapy + 1.0 - r.rayposy) * r.deltadisty;
		}
		while (r.hit == 0)
		{
			if (r.sidedistx < r.sidedisty)
			{
				r.sidedistx += r.deltadistx;
				r.mapx += r.stepx;
				r.side = 0;
			}
			else
			{
				r.sidedisty += r.deltadisty;
				r.mapy += r.stepy;
				r.side = 1;
			}
			if (r.map[r.mapx][r.mapy] > 0)
				r.hit = 1;
		}
		if (r.side == 0)
			r.perpwalldist = (r.mapx - r.rayposx + (1 - r.stepx) / 2) /
				r.raydirx;
		else
			r.perpwalldist = (r.mapy - r.rayposy + (1 - r.stepy) / 2) /
				r.raydiry;
		r.lineheight = (int)(r.h / r.perpwalldist);
		r.drawstart = -r.lineheight / 2 + r.h / 2;
		if (r.drawstart < 0)
			r.drawstart = 0;
		r.drawend = r.lineheight / 2 + r.h / 2;
		if (r.drawend >= r.h)
			r.drawend = r.h;
		y = r.drawstart;
		while (y < r.drawend)
		{
			color = 0x00ff00;
			if (r.side == 0)
				color = 0x00f0f0;
			if (r.side == 1 && r.raydiry < 0)
				color = 0xff0000;
			if (r.side == 0 && r.raydirx > 0)
				color = 0x0000ff;
			r.btab[y][x] = color;
			y++;
		}
		x++;
	}
}

int				main(int argc, char **argv)
{
	t_st	r;
	
	if (argc != 2)
		intel_print(1);
	else if (check(argv[1]) == 1)
	{
		r = create_chain(argv);
		r = init(r);
		resolve(r);
		mlx_put_image_to_window(r.mlx, r.win, r.link, 0, 0);
		mlx_hook(r.win, 2, 1, key_hook, &r);
		mlx_loop(r.mlx);
	}
	else
		intel_print(3);
	return (0);
}
