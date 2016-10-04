/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:31:45 by tandrieu          #+#    #+#             */
/*   Updated: 2016/10/04 21:19:30 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				main(int argc, char **argv)
{
	t_st	st;

	if (argc != 2)
		intel_print(1);
	else if (check(argv[1]) == 1)
	{
		st = han_shot_first(argv);
		st = init(st);
		resolve(st) : while (x < st.w)
		{
			st = init_st(st, x) : t_st	init_st(t_st st, int x)
			{
				st.camerax = 2 * x / (double)st		.w - 1;
				st.rayposx = st.posx;
				st.rayposy = st.posy;
				st.raydirx = st.dirx + st.planex * st.camerax;
				st.raydiry = st.diry + st.planey * st.camerax;
				st.mapx = (int)st.rayposx;
				st.mapy = (int)st.rayposy;
				st.deltadistx = sqrt(1 + (st.raydiry * st.raydiry) /
						(st.raydirx * st.raydirx));
				st.deltadisty = sqrt(1 + (st.raydirx * st.raydirx) /
						(st.raydiry * st.raydiry));
				st.hit = 0;
				return (st);
			}
			st = res_part1(st);
			st = res_part2(st);
			{
				if (st.raydirx < 0)
				{
					st.stepx = -1;		
					st.sidedistx = (st.rayposx - st.mapx) * st.deltadistx;
				}
				else
				{
					st.stepx = 1;
					st.sidedistx = (st.mapx + 1.0 - st.rayposx) * st.deltadistx;
				}
				if (st.raydiry < 0)
				{
					st.stepy = -1;
					st.sidedisty = (st.rayposy - st.mapy) * st.deltadisty;
				}
				else
				{
					st.stepy = 1;
					st.sidedisty = (st.mapy + 1.0 - st.rayposy) * st.deltadisty;
				}
				return (st);
			}

			{
				while (st.hit == 0)
				{
					if (st.sidedistx < st.sidedisty)
					{
						st.sidedistx += st.deltadistx;
						st.mapx += st.stepx;
						st.side = 0;
					}
					else
					{
						st.sidedisty += st.deltadisty;
						st.mapy += st.stepy;
						st.side = 1;
					}
					if (st.map[st.mapx][st.mapy] > 0)
						st.hit = 1;
				}
				if (st.side == 0)
					st.perpwalldist = (st.mapx - st.rayposx + (1 - st.stepx) / 2) /
						st.raydirx;
				else
					st.perpwalldist = (st.mapy - st.rayposy + (1 - st.stepy) / 2) /
						st.raydiry;
				st.lineheight = (int)(st.h / st.perpwalldist);
				return (st);
			}
			st = res_part3(st);
			t_stres_part3(t_st st):
				t_st	res_part3(t_st st)
			{
				st.drawstart = -st.lineheight		 / 2 + st.h / 2;
				if (st.drawstart < 0)
					st.drawstart = 0;
				st.drawend = st.lineheight / 2 + st.h / 2;
				if (st.drawend >= st.h)
					st.drawend = st.h;
				if (st.side == 1)
					st.wallx = st.rayposx + ((st.mapy - st.rayposy + (1 - st.stepy) / 2) /
							st.raydiry) * st.raydirx;
				else
					st.wallx = st.rayposy + ((st.mapx - st.rayposx + (1 - st.stepx) / 2) /
							st.raydirx) * st.raydiry;
				st.wallx -= floor((st.wallx));
				st.texx = (int)(st.wallx * 64);
				if (st.side == 0 && st.raydirx > 0)
					st.texx = 64 - st.texx - 1;
				if (st.side == 1 && st.raydiry < 0)
					st.texx = 64 - st.texx - 1;
				return (st);
			}

			y = st.drawstart;

			st = res_part4(st, y, color, x);
			st = res_part5(st);
			t_st	res_part4(t_st st, int y, int color, int x)
			{
				while (y < st.drawend)
				{
					st.texy = (y * 2 - st.h + st.lineheight) * (64 / 2) / st.lineheight;
					if (st.map[st.mapx][st.mapy] == 1)
						color = st.text1tab[64 * st.texy + st.texx];
					else if (st.map[st.mapx][st.mapy] == 2)
						color = st.text2tab[64 * st.texy + st.texx];
					else if (st.map[st.mapx][st.mapy] == 3)
						color = st.text3tab[64 * st.texy + st.texx];
					st.btab[y][x] = color;
					y++;
				}
				return (st);
			}
			t_st	res_part5(t_st st)
			{
				if (st.side == 0 && st.raydirx > 0)
				{
					st.floorxwall = st.mapx;
					st.floorywall = st.mapy + st.wallx;
				}
				else if (st.side == 0 && st.raydirx < 0)
				{
					st.floorxwall = st.mapx + 1.0;
					st.floorywall = st.mapy + st.wallx;
				}
				else if (st.side == 1 && st.raydiry > 0)
				{
					st.floorxwall = st.mapx + st.wallx;
					st.floorywall = st.mapy;
				}
				else
				{
					st.floorxwall = st.mapx + st.wallx;
					st.floorywall = st.mapy + 1.0;
				}
				st.distwall = st.perpwalldist;
				st.distplayer = 0.0;
				return (st);
			}
			st = resp_part6(st, y, x);
			t_stresp_part6(t_st st, int y, int x)
			{
				if (st.drawend < 0)
					st.		drawend = st.h;
				y = st.drawend;
				while (y < st.h)
				{
					st.currentdist = st.h / (2.0 * y - st.h);
					st.weight = (st.currentdist - st.distplayer) /
						(st.distwall - st.distplayer);
					st.currentfloorx = st.weight * st.floorxwall +
						(1.0 - st.weight) * st.posx;
					st.currentfloory = st.weight * st.floorywall +
						(1.0 - st.weight) * st.posy;
					st.floortexx = (int)(st.currentfloorx * 64) % 64;
					st.floortexy = (int)(st.currentfloory * 64) % 64;
					st.btab[y][x] = st.textsoltab[64 * st.floortexy + st.floortexx];
					st.btab[st.h - y][x] = st.textplaftab[64 *
						st.floortexy + st.floortexx];
					y++;
				}
				return (st);
			}
			x++;
		}
		mlx_put_image_to_window(st.mlx, st.win, st.link, 0, 0);
		mlx_hook(st.win, 2, 1, key_hook, &st);
		mlx_loop(st.mlx);
	}
	else
		intel_print(3);
	return (0);
}
