/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:08:35 by tandrieu          #+#    #+#             */
/*   Updated: 2016/03/03 16:38:02 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_st	init(t_st st)
{
	st.w = 1280;
	st.h = 720;
	st.mlx = mlx_init();
	st.win = mlx_new_window(st.mlx, st.w, st.h, "wolf3d");
	st.link = mlx_new_image(st.mlx, st.w, st.h);
	st.tab = (int*)mlx_get_data_addr(st.link, &st.bits, &st.size, &st.endian);
	st.btab = ft_create_btab(st);
	st.posx = 3;
	st.posy = 3;
	st.dirx = -1;
	st.diry = 0;
	st.planex = 0;
	st.planey = 1;
	st.hit = 0;
	st.vm = 0.2;
	st.fustate = 1;
	st.akstate = 1;
	st.kfstate = 1;
	st.ostate = 0;
	st = read_jpg(st);
	return (st);
}
