/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 20:15:58 by rluder            #+#    #+#             */
/*   Updated: 2016/10/03 14:52:38 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "libft/libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

typedef struct		s_map
{
	char			*line;
	char			**spline;
	struct s_map	*next;
}					t_map;

typedef struct	s_m
{
	int		xsize;
	int		ysize;
	void	*mlx;
	void	*win;
	void	*img;
	int		*intab;
	int		**btab;
	int		bits;
	int		size;
	int		endian;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	hit;
	double	vm;
}			t_m;

t_m	init_m(t_m m);

#endif
