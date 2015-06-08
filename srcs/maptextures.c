/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptextures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 18:28:05 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/08 14:29:01 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		mapskytexture(t_mlxdata *data, int x, int *y, int wallheight)
{
	int txcolor;
	int topwall;

	topwall = HEIGHT / 2 - wallheight + data->playerheight;
	while (++(*y) < topwall && (*y) < HEIGHT)
	{
		txcolor = mlx_getpxl_img(x % 256, (*y) % 256, data->txtures.sky);
		mlx_putpxl_img(data->img, x, (*y), txcolor);
	}
}

static void		mapwalltexture(t_mlxdata *data, int x, int *y,
							t_rayparams *ray)
{
	int		txcolor;
	double	coef;
	double	yoffset;
	int		topwall;
	int		botwall;

	topwall = HEIGHT / 2 - ray->wallheight + data->playerheight;
	botwall = HEIGHT / 2 + ray->wallheight + data->playerheight;
	coef = 64. / (botwall - topwall);
	yoffset = (topwall < 0) ? coef * (-topwall) : 0;
	while (++(*y) <= botwall && (*y) < HEIGHT)
	{
		txcolor = mlx_getpxl_img(ray->walloffset % 64, (int)yoffset % 64,
								gettextures(data, ray->blocktype));
		mlx_putpxl_img(data->img, x, (*y), txcolor);
		yoffset += coef;
	}
}

static void		mapfloortexture(t_mlxdata *data, int x, int *y, int floorcolor)
{
	while (++(*y) < HEIGHT)
	{
		mlx_putpxl_img(data->img, x, (*y), floorcolor);
	}
}

static void		mapobjectexture(t_mlxdata *data, int x, t_rayparams *ray)
{
	unsigned int	txcolor;
	double			coef;
	double			yoffset;
	int				botobj;
	int				y;

	y = HEIGHT / 2 - ray->objheight + data->playerheight;
	botobj = HEIGHT / 2 + ray->objheight + data->playerheight;
	coef = 64. / (botobj - y);
	if (y < 0)
	{
		yoffset = coef * -y;
		y = 0;
	}
	else
		yoffset = 0;
	while (++y <= botobj && y < HEIGHT)
	{
		txcolor = mlx_getpxl_img(ray->objoffset % 64, (int)yoffset % 64,
								gettextures(data, ray->objectype));
		if (txcolor ^ 0xff000000)
			mlx_putpxl_img(data->img, x, y, txcolor);
		yoffset += coef;
	}
}

void			textured(t_mlxdata *data, int x, t_rayparams *ray)
{
	int		y;

	ray->wallheight = (ray->blocktype == 10000) ?
		-ray->wallheight : ray->wallheight;
	y = -1;
	mapskytexture(data, x, &y, ray->wallheight);
	mapwalltexture(data, x, &y, ray);
	mapfloortexture(data, x, &y, data->floorcolor);
	if (ray->objheight != data->wallheight / MAX_DISTANCE &&
		ray->wallheight < ray->objheight)
		mapobjectexture(data, x, ray);
}
