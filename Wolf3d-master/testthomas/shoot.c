/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:43:26 by tandrieu          #+#    #+#             */
/*   Updated: 2016/03/03 18:04:17 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./wolf3d.h"

void	shoot(t_st *st)
{
	if (st->fustate == 1 && st->kfstate == 1)
	{
		if (st->akstate == 0)
		{
			st->akstate = 1;
			st->akfeustate = 1;
			empty_btab(*st);
			resolve(*st);
			akfeu(st);
			system("afplay -v 0.15 music/ak.mp3&");
		}
		else
		{
			st->akstate = 0;
			st->akfeustate = 0;
			empty_btab(*st);
			resolve(*st);
		}
		mlx_clear_window(st->mlx, st->win);
		mlx_put_image_to_window(st->mlx, st->win, st->link, 0, 0);
	}
}

void	run_and_walk(int keycode, t_st *st)
{
	if (keycode == 257)
	{
		if (st->vm < 1)
			st->vm += 0.1;
	}
	else if (keycode == 256)
	{
		if (st->vm > 0.2)
			st->vm -= 0.1;
	}
	else
		st->vm = 0.2;
}
