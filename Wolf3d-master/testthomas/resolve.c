/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:22:18 by tandrieu          #+#    #+#             */
/*   Updated: 2016/10/06 19:07:00 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

t_st		init_st(t_st st, int x)
{
	st.camerax = 2 * x / (double)st.w - 1;
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
/*
t_st		res_part1(t_st st)
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

t_st		res_part2(t_st st)
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

t_st		resp_part6(t_st st, int y, int x)
{
	if (st.drawend < 0)
		st.drawend = st.h;
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

void		resolve(t_st st)
{
	int		y;
	int		x;
	double	color;

	x = 0;
	y = 0;
	color = 0.0;
	while (x < st.w)
	{
		st = init_st(st, x);
		st = res_part1(st);
		st = res_part2(st);
		st = res_part3(st);
		y = st.drawstart;
		st = res_part4(st, y, color, x);
		st = res_part5(st);
		st = resp_part6(st, y, x);
		x++;
	}
	if (st.kfstate == 0)
		kf_display(&st);
	if (st.fustate == 0)
		fu_display(&st);
	if (st.akstate == 0)
		ak_display(&st);
}*/
