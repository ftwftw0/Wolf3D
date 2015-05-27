/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 19:15:12 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/27 16:33:47 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define PI 3.141592
# define WIDTH 800
# define HEIGHT 600
# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
/*
**  Common parameters
*/
# define FOV 60.
# define BLOCKSIZE 64.
# define MAX_DISTANCE 100000
# define WALL_HEIGHT 10
/*
**  In game Colors
*/
# define SKYCOLOR 0x0000eeff
# define FLOORCOLOR 0x00058700
/*
**	Define your own keys
*/
# define ESCAPE 53
# define PAUSE 50
# define SHOOT 1
# define POWER 2
# define SPRINT 257
# define FORWARD 126
# define DOWNWARD 125
# define STRAFELEFT 123
# define STRAFERIGHT 124
# define TURNLEFT 0
# define TURNRIGHT 2
/*
**  In game movement speeds
*/
# define MOVESPEED 2
# define ROTSPEED 1

/*
** Ajout des booleens, substitue par des chars
*/
typedef char	bool;

/*
** Points x, y + couleur.
*/
typedef struct		s_ipoint
{
	int				x;
	int				y;
	int				color;
}					t_ipoint;

/*
** Structures gestion d'affichage minilibx
*/
typedef struct		s_img
{
	void			*ptr;
	t_ipoint		size;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*window;
}					t_env;

/*
** Stockage donnees de la map / grille
*/
typedef struct		s_grid
{
	int				**table;
	int				columns;
}					t_grid;

/*
** Temp datas for hooks events
*/
typedef struct		s_hooks
{
	bool			shooting;
	bool			powering;
	bool			forward;
	bool			backward;
	bool			strafeleft;
	bool			straferight;
	bool			camleft;
	bool			camright;
}					t_hooks;

/*
** Textures structure
*/
typedef struct		s_textures
{
	t_img			wall1;
	t_img			wall2;
	t_img			wall3;
	t_img			wall4;
	t_img			hell;
	t_img			sky;
	t_img			floor;
	t_img			grass;
	t_img			weapon;
	t_img			weaponfiring;
	t_img			key;
}					textures;

/*
** Textures structure to print
*/
typedef struct		s_txtshow
{
	t_img			wall;
	t_img			sky;
	t_img			floor;
	t_img			weapon;
}					t_txtshow;

/*
**  Donnees de la minimap
*/
typedef struct		s_minimap
{
	int				xdepth;
	int				ydepth;
	int				zdepth;
}					t_minimap;

/*
**  
*/
typedef struct		s_rayparams
{
    int   horizontal_x;
    int   horizontal_y;
    int   horizontal_stepx;
    int   horizontal_stepy;
    int   vertical_x;
    int   vertical_y;
    int   vertical_stepx;
    int   vertical_stepy;
}					t_rayparams;

/*
** Contient toute les donnees globales du Wolf3D
*/
typedef struct		s_mlxdata
{
	t_env			env;
	t_ipoint		playerpos;
	t_ipoint		target;
	t_ipoint		a;
	t_ipoint		b;
	t_minimap		map;
	t_img			img;
	t_grid			*grid;
	int				color;
	double			wallheight;
	int				mvspeed;
	int				rotspeed;
	double			viewangle;
	t_hooks			hooks;
	int				skycolor;
	int				floorcolor;
	int				camdist;
	textures		txtures;
	int				tab_128sin[90];
	int				tab_div_128tan[90];
	int				tab_128tan[90];
	int				tab_div_128sin[90];
}					t_mlxdata;

int					mlx_putline(t_mlxdata *data, t_ipoint a, t_ipoint b);
void				swap_points(t_ipoint *a, t_ipoint *b);
int					key_hook(int keycode, t_mlxdata *data);
int					keypress_hook(int keycode, t_mlxdata *data);
int					mouse_hook(int button, int x, int y, t_mlxdata *data);
int					expose_hook(t_mlxdata *data);
int					loop_hook(t_mlxdata *data);
t_mlxdata			*ft_init(int argc, char **argv);
t_grid				*ft_mktable(char *path);
int					*ft_createline(char *str);
int					ft_countcolumns(char *str);
void				ft_puttab(t_grid *grid);
int					mlx_putgrid(t_mlxdata *data, t_grid *grid);
int					mlx_cleanwindow(t_mlxdata *data);
t_img				mlx_create_image(t_mlxdata *data,
									int xsize,
									int ysize,
									int bpp);
int					mlx_putpxl_img(t_img img, int x, int y, int color);
int		            wolf_view(t_mlxdata *data);
int					wolf_move(t_mlxdata *data, int direction);
int					mlx_img_cpy(t_mlxdata *data, t_img img1, t_img img2, t_ipoint a, t_ipoint b);
int					mlx_getpxl_img(int x, int y, t_img img);
t_rayparams			setup_intersections_params(t_mlxdata *data, int angle);
#endif
