/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_win.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:35:24 by tandrieu          #+#    #+#             */
/*   Updated: 2016/03/03 18:09:11 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_st	swin_part1(t_st st)
{
	mlx_string_put(st.mlx, st.win, 200, 25, 0xffffff, "SHIFT : Increase speed");
	mlx_string_put(st.mlx, st.win, 200, 45, 0xffffff, "CTRL : Decrease speed");
	mlx_string_put(st.mlx, st.win, 200, 65, 0xffffff, "ALT : Default speed");
	mlx_string_put(st.mlx, st.win, 5, 0, 0xccffcc, "Movement :");
	mlx_string_put(st.mlx, st.win, 5, 25, 0xffffff, "W : Move forward");
	mlx_string_put(st.mlx, st.win, 5, 45, 0xffffff, "A : Strafe left");
	mlx_string_put(st.mlx, st.win, 5, 65, 0xffffff, "S : Move backward");
	mlx_string_put(st.mlx, st.win, 5, 85, 0xffffff, "D : Strafe right");
	mlx_string_put(st.mlx, st.win, 5, 105, 0xffffff, "<- : Turn left");
	mlx_string_put(st.mlx, st.win, 5, 125, 0xffffff, "-> : Turn right");
	mlx_string_put(st.mlx, st.win, 5, 150, 0xccffcc, "Utilities :");
	mlx_string_put(st.mlx, st.win, 5, 175, 0xffffff, "1 : Pull out knife");
	mlx_string_put(st.mlx, st.win, 5, 195, 0xffffff,
			"2 : Pull out AK-47 (Use space to shoot)");
	mlx_string_put(st.mlx, st.win, 5, 215, 0xffffff,
			"3 : Insult someone(or something)");
	mlx_string_put(st.mlx, st.win, 5, 240, 0xccffcc, "Music :");
	mlx_string_put(st.mlx, st.win, 5, 265, 0xccffcc,
			"(Use the numerical keypad to change the music.)");
	mlx_string_put(st.mlx, st.win, 5, 290, 0xffffff, "1 : Eminem - Survival");
	mlx_string_put(st.mlx, st.win, 5, 310, 0xffffff, "2 : Haendel - Sarabande");
	mlx_string_put(st.mlx, st.win, 5, 330, 0xffffff,
			"3 : Imagine Dragons - Bleeding Out");
	mlx_string_put(st.mlx, st.win, 5, 350, 0xffffff, "4 : KORPIKLAANI - Vodka");
	return (st);
}

t_st	init_swin(t_st st)
{
	if (st.ostate == 0)
	{
		st.ostate = 1;
		st = swin_part1(st);
		mlx_string_put(st.mlx, st.win, 5, 370, 0xffffff,
				"5 : MDK - Press Start");
		mlx_string_put(st.mlx, st.win, 5, 390, 0xffffff,
				"6 : Two Step From Hell - Victory");
		mlx_string_put(st.mlx, st.win, 5, 410, 0xffffff,
				"7 : Whitewoods - Beachwalk");
		mlx_string_put(st.mlx, st.win, 5, 430, 0xffffff,
				"8 : A-ha - Take On Me");
		mlx_string_put(st.mlx, st.win, 5, 450, 0xffffff,
				"9 : Dr.Dre - The Next Episode");
	}
	else if (st.ostate == 1)
	{
		st.ostate = 0;
		empty_btab(st);
		resolve(st);
		mlx_clear_window(st.mlx, st.win);
		mlx_put_image_to_window(st.mlx, st.win, st.link, 0, 0);
	}
	return (st);
}
