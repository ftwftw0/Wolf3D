/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_show.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 05:31:32 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/08 13:34:10 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	mapuntextured(t_mlxdata *data, int x, int wallheight, int wallcolor)
{
	int topwall;
	int botwall;
	int y;

	y = -1;
	topwall = HEIGHT / 2 - wallheight + data->playerheight;
	botwall = HEIGHT / 2 + wallheight + data->playerheight;
	while (++y < topwall && y < HEIGHT)
		mlx_putpxl_img(data->img, x, y, data->skycolor);
	while (++y < botwall && y < HEIGHT)
		mlx_putpxl_img(data->img, x, y, wallcolor);
	while (++y < HEIGHT)
		mlx_putpxl_img(data->img, x, y, data->floorcolor);
}

static void	untextured(t_mlxdata *data, t_rayparams *ray,
						int width, int horizcloser)
{
	if (horizcloser)
	{
		if (ray->angle > 180)
			mapuntextured(data, width, ray->wallheight, WALLNORTHCOLOR);
		else
			mapuntextured(data, width, ray->wallheight, WALLSOUTHCOLOR);
	}
	else
	{
		if ((ray->angle <= 90 || ray->angle > 270))
			mapuntextured(data, width, ray->wallheight, WALLEASTCOLOR);
		else
			mapuntextured(data, width, ray->wallheight, WALLWESTCOLOR);
	}
}

int			wolf_view(t_mlxdata *data)
{
	t_rayparams	ray;
	int			width;
	double		angperpxl;
	double		angle;
	int			horizcloser;

	data->viewangle += ((data->viewangle <= 0) ? 360 : 0);
	data->viewangle -= ((data->viewangle > 360) ? 360 : 0);
	angle = data->viewangle - FOV / 2;
	angperpxl = FOV / WIDTH;
	width = WIDTH;
	ray.walloffset = 1;
	while (--width)
	{
		ray.angle = ((angle < 0) ? angle + 360 : angle);
		ray.angle = ((ray.angle >= 360) ? ray.angle - 360 : ray.angle);
		ray.wallheight = walldist(data, &ray, &horizcloser);
		if (data->hooks.textured)
			textured(data, width, &ray);
		else
			untextured(data, &ray, width, horizcloser);
		angle += angperpxl;
	}
	return (1);
}
