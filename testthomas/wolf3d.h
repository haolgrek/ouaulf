/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:13:13 by rluder            #+#    #+#             */
/*   Updated: 2016/10/14 16:02:28 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include "get_next_line.h"

typedef struct		s_map
{
	char			*chartab;
	char			**tab_split;
	int				*intab;
	struct s_map	*next;
}					t_map;

typedef struct		s_st
{
	void			*mlx;
	void			*win;
	void			*link;
	int				*tab;
	int				**btab;
	int				bits;
	int				size;
	int				endian;
	int				w;
	int				h;
	int				map_width;
	int				map_height;
	char			**map;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			vm;
	double			wallx;
	double			floorxwall;
	double			floorywall;
	double			distwall;
	double			distplayer;
	double			currentdist;
	double			weight;
	double			currentfloorx;
	double			currentfloory;
}					t_st;

t_st				init(t_st st);
t_map				*ft_create_elem(char *line);
int					ft_mapok(char *str);
int					check(char *str);
void				intel_print(int i);
char				**create_chain(char *argv, t_st r);
t_st				resolve(t_st st);
int					**ft_create_btab(t_st list);
int					key_hook(int keycode, t_st st);
void				empty_btab(t_st st);
void				free_all(t_st *st);
int					**intab(t_st r);

#endif
