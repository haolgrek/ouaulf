/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:03:37 by rluder            #+#    #+#             */
/*   Updated: 2016/10/14 16:10:35 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "get_next_line.h"

typedef struct	s_data
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;

	int			x;
	double		camera_x;
	double		raypos_x;
	double		raypos_y;
	double		raydir_x;
	double		raydir_y;

	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			lineheight;

	double		move_speed;
	double		rot_speed;
}				t_data;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*link;
	void		*lb_link;
	void		*sky_link;
	int			*tab;
	int			**tab2d;
	int			bits;
	int			size;
	int			endian;
	char		**map;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		olddir_x;
	double		oldplane_x;
	t_data		d;
	int			*tex[10];
	int			tex_y;
	int			tex_x;
	double		wallx;
	int			lvl;
	int			s[3];
	char		*s1;
	char		*s2;
	char		*s3;
	char		*sl;
}				t_mlx;

char			**map_gen(int level);
t_mlx			print_map(t_mlx l);
t_mlx			create_tex(t_mlx l);
t_mlx			*rot_hook_right(t_mlx *l);
t_mlx			*move_hook(int keycode, t_mlx *l);
t_mlx			*rot_hook_left(t_mlx *l);
t_data			check_steps(t_data d);
t_data			check_side(t_data d, t_mlx *l);
void			free_str(t_mlx *l);

#endif
