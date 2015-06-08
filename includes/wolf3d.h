/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 20:01:25 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/08 17:50:10 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
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
# define WALL_HEIGHT 20
# define JUMP_HEIGHT 50

/*
**  In game Colors
*/
# define SKYCOLOR 0x0000eeff
# define WALLNORTHCOLOR 0x00ffcc00
# define WALLSOUTHCOLOR 0x00ff99ff
# define WALLEASTCOLOR 0x00ccff33
# define WALLWESTCOLOR 0x0000ffcc
# define FLOORCOLOR 0x0005870

/*
**	Define your own keys
*/
# define ESCAPE 53
# define PAUSE 50
# define SHOOT 258
# define POWER 82
# define CROUCH 8
# define JUMP 49
# define SPRINT 257
# define FORWARD 126
# define DOWNWARD 125
# define STRAFELEFT 123
# define STRAFERIGHT 124
# define TURNLEFT 0
# define TURNRIGHT 2
# define KEY_T 17

/*
**  In game movement speeds
*/
# define MOVESPEED 2
# define ROTSPEED 2

/*
** Ajout des t_booleens, substitue par des chars
*/
typedef char	t_bool;

/*
** Points x, y + couleur.
*/
typedef struct		s_ipoint
{
	double			x;
	double			y;
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
	t_bool			textured;
	t_bool			shooting;
	t_bool			powering;
	t_bool			forward;
	t_bool			backward;
	t_bool			strafeleft;
	t_bool			straferight;
	t_bool			camleft;
	t_bool			camright;
	t_bool			crouch;
	t_bool			jumping;
}					t_hooks;

/*
** Textures structure
*/
typedef struct		s_textures
{
	t_img			stone;
	t_img			wood;
	t_img			planks;
	t_img			dirt;
	t_img			wool;
	t_img			hell;
	t_img			sky;
	t_img			floor;
	t_img			grass;
	t_img			flower_rose;
	t_img			bush;
	t_img			glowstone;
	t_img			weapon;
	t_img			weaponfiring;
}					t_textures;

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
**  Ray params
*/
typedef struct		s_rayparams
{
	double			angle;
	double			horizontal_x;
	double			horizontal_y;
	double			horizontal_stepx;
	double			horizontal_stepy;
	double			horizontal_hit_dist;
	double			horizontal_object_x;
	double			horizontal_object_dist;
	double			vertical_x;
	double			vertical_y;
	double			vertical_stepx;
	double			vertical_stepy;
	double			vertical_hit_dist;
	double			vertical_object_y;
	double			vertical_object_dist;
	double			wallheight;
	double			objheight;
	int				walloffset;
	int				objoffset;
	int				blocktype;
	int				objectype;
}					t_rayparams;

/*
** Contient toute les donnees globales du Wolf3D
*/
typedef struct		s_mlxdata
{
	t_env			env;
	t_ipoint		playerpos;
	int				playerheight;
	int				score;
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
	t_textures		txtures;
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
								int xsize, int ysize, int bpp);
int					mlx_putpxl_img(t_img img, int x, int y, int color);
int					wolf_view(t_mlxdata *data);
int					wolf_move(t_mlxdata *data, int direction);
int					mlx_getpxl_img(int x, int y, t_img img);
void				setup_intersections_params(t_mlxdata *data,
								t_rayparams *ray);
double				walldist(t_mlxdata *data, t_rayparams *ray,
								int *horizcloser);
int					verti_walldist(t_mlxdata *data, t_rayparams *ray,
								int *vobjectype);
int					horiz_walldist(t_mlxdata *data, t_rayparams *ray,
								int *hobjectype);
int					load_txtures(t_mlxdata *data);
int					mlx_getpxl_img(int x, int y, t_img img);
void				textured(t_mlxdata *data, int x, t_rayparams *ray);
int					wolf_putweapon(t_mlxdata *data);
int					wolf_controller(t_mlxdata *data);
t_img				gettextures(t_mlxdata *data, int type);
#endif
