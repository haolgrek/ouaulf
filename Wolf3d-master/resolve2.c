/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:47:12 by tandrieu          #+#    #+#             */
/*   Updated: 2016/10/06 17:56:25 by rluder           ###   ########.fr       */
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
//	if (st.side == 1)
//		st.wallx = st.rayposx + ((st.mapy - st.rayposy + (1 - st.stepy) / 2) /
//				st.raydiry) * st.raydirx;
//	else
//		st.wallx = st.rayposy + ((st.mapx - st.rayposx + (1 - st.stepx) / 2) /
//				st.raydirx) * st.raydiry;
//	st.wallx -= floor((st.wallx));
	return (st);
}

t_st		res_part4(t_st st, int y, int color, int x)
{
	while (y < st.drawend)
	{
		color = 0x00ff00;
		if (st.side == 0)
			color = 0x00f0f0;
		if (st.side == 1 && st.raydiry < 0)
			color = 0xff0000;
		if (st.side == 0 && st.raydirx > 0)
			color = 0x0000ff;
		st.btab[y][x] = color;
		y++;
	}
	return (st);
}
