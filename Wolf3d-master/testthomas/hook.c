/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:06:57 by rluder            #+#    #+#             */
/*   Updated: 2016/10/10 18:30:46 by rluder           ###   ########.fr       */
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

	if (keycode == 14)
	{
		olddirx = st->dirx;
		st->dirx = st->dirx * cos(-0.1) - st->diry * sin(-0.1);
		st->diry = olddirx * sin(-0.1) + st->diry * cos(-0.1);
		oldplanex = st->planex;
		st->planex = st->planex * cos(-0.1) - st->planey * sin(-0.1);
		st->planey = oldplanex * sin(-0.1) + st->planey * cos(-0.1);
	}
	if (keycode == 12)
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

void	free_all(t_st *st)
{
	ft_memdel((void**)&st->tab);
	ft_memdel((void**)&st->btab);
	ft_memdel((void**)&st->map);
}

int		key_hook(int keycode, t_st *st)
{
	if (keycode == 53)
	{
		free_all(st);
		exit(0);
	}
	if (keycode == 13 || keycode == 1)
		move1(keycode, st);
	if (keycode == 0 || keycode == 2)
		move2(keycode, st);
	if (keycode == 12 || keycode == 14)
		rotate(keycode, st);
	return (0);
}
