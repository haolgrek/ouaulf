/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:31:45 by tandrieu          #+#    #+#             */
/*   Updated: 2016/03/03 16:24:10 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				main(int argc, char **argv)
{
	t_st	st;

	if (argc != 2)
		intel_print(1);
	else if (check(argv[1]) == 1)
	{
		st = han_shot_first(argv);
		st = init(st);
		resolve(st);
		mlx_put_image_to_window(st.mlx, st.win, st.link, 0, 0);
		mlx_hook(st.win, 2, 1, key_hook, &st);
		mlx_loop(st.mlx);
	}
	else
		intel_print(3);
	return (0);
}
