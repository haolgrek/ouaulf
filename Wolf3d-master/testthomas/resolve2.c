/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:47:12 by tandrieu          #+#    #+#             */
/*   Updated: 2016/03/04 12:09:39 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./wolf3d.h"

t_st		res_part3(t_st st)
{
	st.drawstart = -st.lineheight / 2 + st.h / 2;
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

t_st		res_part4(t_st st, int y, int color, int x)
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

t_st		res_part5(t_st st)
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
