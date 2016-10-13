/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:10:28 by rluder            #+#    #+#             */
/*   Updated: 2016/10/14 00:03:06 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			printparams(t_st r)
{
	ft_putstr("w: ");
	ft_putnbr(r.w);
	ft_putchar('\n');
	ft_putstr("h: ");
	ft_putnbr(r.h);
	ft_putchar('\n');
	ft_putstr("map_width: ");
	ft_putnbr(r.map_width);
	ft_putchar('\n');
	ft_putstr("map_height: ");
	ft_putnbr(r.map_height);
	ft_putchar('\n');
	ft_putstr("mapx: ");
	ft_putnbr(r.mapx);
	ft_putchar('\n');
	ft_putstr("mapy: ");
	ft_putnbr(r.mapy);
	ft_putchar('\n');
	ft_putstr("stepx: ");
	ft_putnbr(r.stepx);
	ft_putchar('\n');
	ft_putstr("stepy: ");
	ft_putnbr(r.stepy);
	ft_putchar('\n');
	ft_putstr("hit: ");
	ft_putnbr(r.hit);
	ft_putchar('\n');
	ft_putstr("side: ");
	ft_putnbr(r.side);
	ft_putchar('\n');
	ft_putstr("lineheight: ");
	ft_putnbr(r.lineheight);
	ft_putchar('\n');
}

t_st			resolve(t_st r)
{
	int	x;
	int	y;
	double	color;

//	ft_putendl("resstart");
	x = 0;
	y = 0;
	while (x < r.w)
	{
//		ft_putendl("while1");
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
//		ft_putendl("beforeif");
		if (r.raydirx < 0)
		{
			r.stepx = -1;
//			ft_putendl("inif");
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
//			ft_putendl("inif2");
			r.sidedisty = (r.rayposy - r.mapy) * r.deltadisty;
		}
		else
		{
			r.stepy = 1;
			r.sidedisty = (r.mapy + 1.0 - r.rayposy) * r.deltadisty;
		}
		while (r.hit == 0)
		{
//			ft_putendl("while2");
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
	return (r);
}

int				main(int argc, char **argv)
{
	t_st	r;

	r.w = 1280;
	r.h = 768;
	ft_putendl("pseudo-init");
	if (argc != 2)
		intel_print(1);
	else if (check(argv[1]) == 1)
	{
		r.mlx = mlx_init();
		r.win = mlx_new_window(r.mlx, r.h, r.w, "");
		r.link = mlx_new_image(r.mlx, r.h, r.w);
		r = init(r);
		ft_putendl("init");
		r.map = create_chain(argv[1], r);
		r.tab = (int*)mlx_get_data_addr(r.link, &r.bits, &r.size, &r.endian);
		r.btab = intab(r);
		ft_putendl("createchain");
		r = resolve(r);
		ft_putendl("resolve");
		printparams(r);
		mlx_put_image_to_window(r.mlx, r.win, r.link, 0, 0);
		mlx_hook(r.win, 2, 1, key_hook, &r);
		mlx_loop(r.mlx);
	}
	else
		intel_print(3);
	return (0);
}
