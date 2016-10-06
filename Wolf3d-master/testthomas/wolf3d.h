/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 11:55:45 by tandrieu          #+#    #+#             */
/*   Updated: 2016/03/03 17:45:29 by tandrieu         ###   ########.fr       */
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
# include "./get_next_line/get_next_line.h"

typedef struct		s_motd
{
	void			*mlx;
	void			*win;
	void			*link;
	int				*tab;
	int				bits;
	int				size;
	int				endian;
}					t_motd;

typedef struct		s_poire
{
	char			*twilight_sucks;
	char			**tab_split;
	int				*arrow_sucks;
	struct s_poire	*next;
}					t_poire;

typedef struct		s_st
{
	t_motd			st2;
	void			*mlx;
	void			*win;
	void			*link;
	int				*tab;
	int				**btab;
	int				bits;
	int				size;
	int				endian;

	int				testbits;
	int				testsize;
	int				testendian;
	void			*text1;
	int				*text1tab;
	void			*text2;
	int				*text2tab;
	void			*text3;
	int				*text3tab;
	void			*textsol;
	int				*textsoltab;
	void			*textfu;
	int				*textfutab;
	void			*textplaf;
	int				*textplaftab;
	void			*textak;
	int				*textaktab;
	void			*textkf;
	int				*textkftab;
	void			*textakfeu;
	int				*textakfeutab;
	void			*textakfeu2;
	int				*textakfeu2tab;

	int				w;
	int				h;
	int				map_width;
	int				map_height;
	int				**map;
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
	int				texx;
	int				texy;
	double			floorxwall;
	double			floorywall;
	double			distwall;
	double			distplayer;
	double			currentdist;
	double			weight;
	double			currentfloorx;
	double			currentfloory;
	int				floortexx;
	int				floortexy;

	int				fustate;
	int				akstate;
	int				kfstate;
	int				akfeustate;
	int				ostate;
}					t_st;

t_st				init(t_st st);
t_poire				*ft_create_elem(char *line);
int					ft_isok(char *str);
int					check(char *str);
void				intel_print(int i);
t_st				han_shot_first(char **argv);
void				resolve(t_st st);
int					**ft_create_btab(t_st list);
int					key_hook(int keycode, t_st *st);
void				empty_btab(t_st st);
t_st				read_jpg(t_st st);
void				fu_display(t_st *st);
void				kf_display(t_st *st);
void				ak_display(t_st *st);
void				akfeu(t_st *st);
void				akfeu2(t_st *st);
void				shoot(t_st *st);
t_st				res_part3(t_st st);
t_st				res_part4(t_st st, int y, int color, int x);
t_st				res_part5(t_st st);
void				music(int keycode);
t_st				init_swin(t_st st);
void				run_and_walk(int keycode, t_st *st);

#endif
