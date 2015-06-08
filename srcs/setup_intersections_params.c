/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_intersection_params.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 19:06:47 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/02 22:23:28 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	setup90(t_mlxdata *data, t_rayparams *ray)
{
	double		first_hit;

	ray->horizontal_y = ((int)data->playerpos.y & 0xffc0) - 0.01;
	first_hit = -256. / tan(ray->angle * PI / 180);
	first_hit *= (double)(ray->horizontal_y - data->playerpos.y);
	first_hit /= 256;
	first_hit += (double)data->playerpos.x;
	ray->horizontal_x = (double)first_hit;
	ray->horizontal_stepx = 64 / tan(ray->angle * PI / 180);
	ray->horizontal_stepy = -64;
	ray->vertical_x = ((int)data->playerpos.x & 0xffc0) + 64;
	first_hit = -256. * tan(ray->angle * PI / 180);
	first_hit *= (double)(ray->vertical_x - data->playerpos.x);
	first_hit /= 256;
	first_hit += (double)data->playerpos.y;
	ray->vertical_y = (double)first_hit;
	ray->vertical_stepx = 64;
	ray->vertical_stepy = -64. * tan(ray->angle * PI / 180);
}

static void setup180(t_mlxdata *data, t_rayparams *ray)
{
	double		first_hit;

	ray->horizontal_y = ((int)data->playerpos.y & 0xffc0) - 0.01;
	first_hit = -256. / tan(ray->angle * PI / 180);
	first_hit *= (double)(ray->horizontal_y - data->playerpos.y);
	first_hit /= 256;
	first_hit += (double)data->playerpos.x;
	ray->horizontal_x = (double)first_hit;
	ray->horizontal_stepx = 64 / tan(ray->angle * PI / 180);
	ray->horizontal_stepy = -64;
	ray->vertical_x = ((int)data->playerpos.x & 0xffc0) - 0.01;
	first_hit = -256. * tan(ray->angle * PI / 180);
	first_hit *= (double)(ray->vertical_x - data->playerpos.x);
	first_hit /= 256;
	first_hit += (double)data->playerpos.y;
	ray->vertical_y = (double)first_hit;
	ray->vertical_stepx = -64;
	ray->vertical_stepy = 64 * tan(ray->angle * PI / 180);
}

static void setup270(t_mlxdata *data, t_rayparams *ray)
{
	double		first_hit;

	ray->horizontal_y = ((int)data->playerpos.y & 0xffc0) + 64;
	first_hit = 256. / tan(ray->angle * PI / 180);
	first_hit *= -(double)(ray->horizontal_y - data->playerpos.y);
	first_hit /= 256;
	first_hit += (double)data->playerpos.x;
	ray->horizontal_x = (double)first_hit;
	ray->horizontal_stepx = -64 / tan(ray->angle * PI / 180);
	ray->horizontal_stepy = 64;
	ray->vertical_x = ((int)data->playerpos.x & 0xffc0) - 0.01;
	first_hit = 256 * tan(ray->angle * PI / 180);
	first_hit *= -(double)(ray->vertical_x - data->playerpos.x);
	first_hit /= 256;
	first_hit += (double)data->playerpos.y;
	ray->vertical_y = (double)first_hit;
	ray->vertical_stepx = -64;
	ray->vertical_stepy = 64 * tan(ray->angle * PI / 180);
}

static void setup360(t_mlxdata *data, t_rayparams *ray)
{
	double		first_hit;

	ray->horizontal_y = ((int)data->playerpos.y & 0xffc0) + 64;
	first_hit = 256. / tan(ray->angle * PI / 180);
	first_hit *= -(double)(ray->horizontal_y - data->playerpos.y);
	first_hit /= 256;
	first_hit += (double)data->playerpos.x;
	ray->horizontal_x = (double)first_hit;
	ray->horizontal_stepx = -64 / tan(ray->angle * PI / 180);
	ray->horizontal_stepy = 64;
	ray->vertical_x = ((int)data->playerpos.x & 0xffc0) + 64;
	first_hit = 256 * tan(ray->angle * PI / 180);
	first_hit *= -(double)(ray->vertical_x - data->playerpos.x);
	first_hit /= 256;
	first_hit += (double)data->playerpos.y;
	ray->vertical_y = (double)first_hit;
	ray->vertical_stepx = 64;
	ray->vertical_stepy = -64 * tan(ray->angle * PI / 180);
}

void		setup_intersections_params(t_mlxdata *data, t_rayparams *ray)
{
	if (ray->angle <= 90)
		setup90(data, ray);
	else if (ray->angle <= 180)
		setup180(data, ray);
	else if (ray->angle <= 270)
		setup270(data, ray);
	else if (ray->angle <= 360)
		setup360(data, ray);
}
