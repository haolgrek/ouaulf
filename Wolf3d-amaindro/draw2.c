/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 12:43:11 by amaindro          #+#    #+#             */
/*   Updated: 2016/03/20 18:06:04 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_data		check_steps(t_data d)
{
	if (d.raydir_x < 0)
	{
		d.step_x = -1;
		d.sidedist_x = (d.raypos_x - d.map_x) * d.deltadist_x;
	}
	else
	{
		d.step_x = 1;
		d.sidedist_x = (d.map_x + 1.0 - d.raypos_x) * d.deltadist_x;
	}
	if (d.raydir_y < 0)
	{
		d.step_y = -1;
		d.sidedist_y = (d.raypos_y - d.map_y) * d.deltadist_y;
	}
	else
	{
		d.step_y = 1;
		d.sidedist_y = (d.map_y + 1.0 - d.raypos_y) * d.deltadist_y;
	}
	return (d);
}

t_data		check_side(t_data d, t_mlx *l)
{
	if (d.side == 0)
	{
		d.perpwalldist = (d.map_x - d.raypos_x + (1 - d.step_x) / 2)
			/ d.raydir_x;
		l->wallx = d.raypos_y + d.perpwalldist * d.raydir_y;
	}
	else
	{
		d.perpwalldist = (d.map_y - d.raypos_y + (1 - d.step_y) / 2)
			/ d.raydir_y;
		l->wallx = d.raypos_x + d.perpwalldist * d.raydir_x;
	}
	l->wallx -= floor(l->wallx);
	l->tex_x = (int)(l->wallx * (double)16);
	return (d);
}
