/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_raycast_horiz.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:21:05 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/08 13:31:56 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	raystillinsidemap(t_mlxdata *data, int x, int y)
{
	if (x <= 1 || y <= 0 ||
		(x >> 6) > (data->grid->table[0][0]) ||
		(y >> 6) >= (data->grid->columns))
		return (0);
	return (1);
}

static int	hblock(t_mlxdata *data, t_rayparams *ray,
					int blocktype, int *hobjectype)
{
	if (blocktype > 0)
	{
		ray->horizontal_hit_dist = fabs((data->playerpos.y -
			ray->horizontal_y) / (sin(ray->angle * PI / 180)));
		return (1);
	}
	else if (ray->horizontal_object_dist == MAX_DISTANCE)
	{
		ray->horizontal_object_dist = fabs((data->playerpos.y -
			ray->horizontal_y) / (sin(ray->angle * PI / 180)));
		(*hobjectype) = blocktype;
		ray->horizontal_object_x = ray->horizontal_x;
	}
	ray->horizontal_x += ray->horizontal_stepx;
	ray->horizontal_y += ray->horizontal_stepy;
	return (0);
}

int			horiz_walldist(t_mlxdata *data, t_rayparams *ray,
							int *hobjectype)
{
	int blocktype;

	ray->horizontal_object_dist = MAX_DISTANCE;
	while (1)
	{
		if (!raystillinsidemap(data, ray->horizontal_x, ray->horizontal_y))
		{
			ray->horizontal_hit_dist = MAX_DISTANCE;
			break ;
		}
		else if (((blocktype) = data->grid->table
			[(int)ray->horizontal_y >> 6][(int)ray->horizontal_x >> 6]))
		{
			if (hblock(data, ray, blocktype, hobjectype))
				break ;
		}
		else
		{
			ray->horizontal_x += ray->horizontal_stepx;
			ray->horizontal_y += ray->horizontal_stepy;
		}
	}
	return (blocktype);
}
