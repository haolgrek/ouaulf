/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:18:47 by amaindro          #+#    #+#             */
/*   Updated: 2016/03/20 19:10:01 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_mlx	create_tex(t_mlx l)
{
	void	*img;
	int		int1;
	int		int2;

	img = mlx_xpm_file_to_image(l.mlx, "tex/stone.xpm", &int1, &int2);
	l.tex[0] = (int*)mlx_get_data_addr(img, &l.bits, &l.size, &l.endian);
	img = mlx_xpm_file_to_image(l.mlx, "tex/wood.xpm", &int1, &int2);
	l.tex[1] = (int*)mlx_get_data_addr(img, &l.bits, &l.size, &l.endian);
	img = mlx_xpm_file_to_image(l.mlx, "tex/iron.xpm", &int1, &int2);
	l.tex[2] = (int*)mlx_get_data_addr(img, &l.bits, &l.size, &l.endian);
	img = mlx_xpm_file_to_image(l.mlx, "tex/cole.xpm", &int1, &int2);
	l.tex[3] = (int*)mlx_get_data_addr(img, &l.bits, &l.size, &l.endian);
	img = mlx_xpm_file_to_image(l.mlx, "tex/diamond.xpm", &int1, &int2);
	l.tex[4] = (int*)mlx_get_data_addr(img, &l.bits, &l.size, &l.endian);
	l.lb_link = mlx_xpm_file_to_image(l.mlx, "tex/leaderboard.xpm",
			&int1, &int2);
	l.tex[9] = (int*)mlx_get_data_addr(l.lb_link, &l.bits, &l.size, &l.endian);
	return (l);
}

void	free_str(t_mlx *l)
{
	ft_memdel((void**)&l->s1);
	ft_memdel((void**)&l->s2);
	ft_memdel((void**)&l->s3);
	ft_memdel((void**)&l->sl);
}
