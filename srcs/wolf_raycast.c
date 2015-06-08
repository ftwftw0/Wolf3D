/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 03:29:59 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/08 13:54:17 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	int getdanorm(t_mlxdata *data, t_rayparams *ray,
						int hblocktype, int *horizcloser)
{
	int wall_height;

	*horizcloser = 1;
	wall_height = data->wallheight / ray->horizontal_hit_dist;
	ray->blocktype = hblocktype;
	ray->walloffset = 64 - ((int)(ray->horizontal_x) & 0x3f);
	if ((int)(data->viewangle) == (int)(ray->angle))
	{
		data->target.y = ray->horizontal_y;
		data->target.x = ray->horizontal_x;
	}
	return (wall_height);
}

static	int getdafuckingnorm(t_mlxdata *data, t_rayparams *ray,
						int vblocktype, int *horizcloser)
{
	int wall_height;

	*horizcloser = 0;
	wall_height = data->wallheight / ray->vertical_hit_dist;
	ray->blocktype = vblocktype;
	ray->walloffset = (int)(ray->vertical_y) & 0x3f;
	if ((int)(data->viewangle) == (int)(ray->angle))
	{
		data->target.y = ray->vertical_y;
		data->target.x = ray->vertical_x;
	}
	return (wall_height);
}

double		walldist(t_mlxdata *data, t_rayparams *ray,
					int *horizcloser)
{
	int			vblocktype;
	int			hblocktype;
	int			vobjectype;
	int			hobjectype;
	int			wall_height;

	setup_intersections_params(data, ray);
	hblocktype = horiz_walldist(data, ray, &hobjectype);
	vblocktype = verti_walldist(data, ray, &vobjectype);
	wall_height = (ray->horizontal_hit_dist <= ray->vertical_hit_dist) ?
		getdanorm(data, ray, hblocktype, horizcloser) :
		getdafuckingnorm(data, ray, vblocktype, horizcloser);
	if (ray->horizontal_object_dist <= ray->vertical_object_dist)
	{
		ray->objheight = data->wallheight / ray->horizontal_object_dist;
		ray->objoffset = 64 - ((int)(ray->horizontal_object_x) & 0x3f);
		ray->objectype = hobjectype;
	}
	else
	{
		ray->objheight = data->wallheight / ray->vertical_object_dist;
		ray->objoffset = (int)(ray->vertical_object_y) & 0x3f;
		ray->objectype = vobjectype;
	}
	return (wall_height);
}
