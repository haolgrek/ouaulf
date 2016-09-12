/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 20:12:32 by rluder            #+#    #+#             */
/*   Updated: 2016/09/12 22:17:06 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	main(int argc, char **argv)
{
	t_m	m;

	if (argc != 2)
	{
		ft_putendl("Wrong number of arguments");
		return (0);
	}
	else if (lvlok(argv[1]))
	{
		m = loadmap(argv);
		m = init(m);
		play(m);
		mlx_put_image_to_window(m.mlx, m.win, m.img, 0, 0);
		mlx_hook(m.win, 2, 1, keys, &m);
		mlx_loop(m.mlx);
	}
	else
		ft_putendl("Map is shitty");
	return (0);
}
