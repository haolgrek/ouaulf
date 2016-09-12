/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:31:13 by tandrieu          #+#    #+#             */
/*   Updated: 2016/03/03 17:51:35 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move1(int keycode, t_st *st)
{
	if (keycode == 13)
	{
		if (st->map[(int)(st->posx + st->dirx * st->vm)][(int)st->posy] == 0)
			st->posx += st->dirx * st->vm;
		if (st->map[(int)st->posx][(int)(st->posy + st->diry * st->vm)] == 0)
			st->posy += st->diry * st->vm;
	}
	if (keycode == 1)
	{
		if (st->map[(int)(st->posx - st->dirx * st->vm)][(int)st->posy] == 0)
			st->posx -= st->dirx * st->vm;
		if (st->map[(int)st->posx][(int)(st->posy - st->diry * st->vm)] == 0)
			st->posy -= st->diry * st->vm;
	}
	mlx_clear_window(st->mlx, st->win);
	empty_btab(*st);
	resolve(*st);
	mlx_put_image_to_window(st->mlx, st->win, st->link, 0, 0);
}

void	move2(int keycode, t_st *st)
{
	if (keycode == 0)
	{
		if (st->map[(int)(st->posx - st->planex * st->vm)][(int)st->posy] == 0)
			st->posx -= st->planex * st->vm;
		if (st->map[(int)st->posx][(int)(st->posy - st->planey * st->vm)] == 0)
			st->posy -= st->planey * st->vm;
	}
	if (keycode == 2)
	{
		if (st->map[(int)(st->posx + st->planex * st->vm)][(int)st->posy] == 0)
			st->posx += st->planex * st->vm;
		if (st->map[(int)st->posx][(int)(st->posy + st->planey * st->vm)] == 0)
			st->posy += st->planey * st->vm;
	}
	mlx_clear_window(st->mlx, st->win);
	empty_btab(*st);
	resolve(*st);
	mlx_put_image_to_window(st->mlx, st->win, st->link, 0, 0);
}

void	rotate(int keycode, t_st *st)
{
	double		olddirx;
	double		oldplanex;

	if (keycode == 124)
	{
		olddirx = st->dirx;
		st->dirx = st->dirx * cos(-0.1) - st->diry * sin(-0.1);
		st->diry = olddirx * sin(-0.1) + st->diry * cos(-0.1);
		oldplanex = st->planex;
		st->planex = st->planex * cos(-0.1) - st->planey * sin(-0.1);
		st->planey = oldplanex * sin(-0.1) + st->planey * cos(-0.1);
	}
	if (keycode == 123)
	{
		olddirx = st->dirx;
		st->dirx = st->dirx * cos(0.1) - st->diry * sin(0.1);
		st->diry = olddirx * sin(0.1) + st->diry * cos(0.1);
		oldplanex = st->planex;
		st->planex = st->planex * cos(0.1) - st->planey * sin(0.1);
		st->planey = oldplanex * sin(0.1) + st->planey * cos(0.1);
	}
	mlx_clear_window(st->mlx, st->win);
	empty_btab(*st);
	resolve(*st);
	mlx_put_image_to_window(st->mlx, st->win, st->link, 0, 0);
}

void	inventory(int keycode, t_st *st)
{
	if (keycode == 18)
	{
		st->kfstate = (st->kfstate == 0) ? 1 : 0;
		st->fustate = 1;
		st->akstate = 1;
	}
	if (keycode == 19)
	{
		st->akstate = (st->akstate == 0) ? 1 : 0;
		st->fustate = 1;
		st->kfstate = 1;
	}
	if (keycode == 20)
	{
		if (st->fustate == 1)
			system("afplay music/fu.mp3&");
		st->fustate = (st->fustate == 0) ? 1 : 0;
		st->kfstate = 1;
		st->akstate = 1;
	}
	empty_btab(*st);
	resolve(*st);
	mlx_clear_window(st->mlx, st->win);
	mlx_put_image_to_window(st->mlx, st->win, st->link, 0, 0);
}

int		key_hook(int keycode, t_st *st)
{
	if (keycode == 53)
	{
		system("killall afplay");
		exit(0);
	}
	if (keycode == 13 || keycode == 1)
		move1(keycode, st);
	if (keycode == 0 || keycode == 2)
		move2(keycode, st);
	if (keycode == 124 || keycode == 123)
		rotate(keycode, st);
	if (keycode == 18 || keycode == 19 || keycode == 20)
		inventory(keycode, st);
	if (keycode == 49)
		shoot(st);
	if (keycode == 83 || keycode == 84 || keycode == 85 || keycode == 86 ||
		keycode == 87 || keycode == 88 || keycode == 89 || keycode == 91 ||
		keycode == 92)
		music(keycode);
	if (keycode == 48)
		*st = init_swin(*st);
	if (keycode == 257 || keycode == 256 || keycode == 261)
		run_and_walk(keycode, st);
	return (0);
}
