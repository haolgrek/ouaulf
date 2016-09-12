/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 21:11:32 by rluder            #+#    #+#             */
/*   Updated: 2016/09/12 21:46:18 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_m	init_m(t_m m)
{
	m.xsize = 1280;
	m.ysize = 720;
	m.mlx = mlx_init();
	m.>win = mlx_new_window(m.mlx, m.xsize, m.ysize, "Wolf3d");
	m.img = mlx_new_image(m.mlx, m.xsize, m.ysize);
	m.intab = (int*)mlx_get_data_addr(m.img, &m.bits, &m.size, &m.endian);
	m.btab = ft_create_btab(m);
	m.posx = 3;
	m.posy = 3;
	m.dirx = -1;
	m.diry = 0;
	m.planex = 0;
	m.planey = 1;
	m.hit = 0;
	m.vm = 0.2;
	return (m);
}
