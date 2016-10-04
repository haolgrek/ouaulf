/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:31:45 by tandrieu          #+#    #+#             */
/*   Updated: 2016/10/04 17:39:17 by rluder           ###   ########.fr       */
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
			y = st.drawstart;
			st = res_part4(st, y, color, x);
			st = res_part5(st);
			st = resp_part6(st, y, x);
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
