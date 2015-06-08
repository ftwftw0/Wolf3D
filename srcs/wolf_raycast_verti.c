/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_raycast_verti.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:22:10 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/08 13:31:43 by flagoutt         ###   ########.fr       */
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

static int	vblock(t_mlxdata *data, t_rayparams *ray, int blocktype,
					int *vobjectype)
{
	if (blocktype > 0)
	{
		ray->vertical_hit_dist = fabs((data->playerpos.x -
			ray->vertical_x) / cos(ray->angle * PI / 180));
		return (1);
	}
	else if (ray->vertical_object_dist == MAX_DISTANCE)
	{
		ray->vertical_object_dist = fabs((data->playerpos.x -
			ray->vertical_x) / cos(ray->angle * PI / 180));
		(*vobjectype) = blocktype;
		ray->vertical_object_y = ray->vertical_y;
	}
	ray->vertical_x += ray->vertical_stepx;
	ray->vertical_y += ray->vertical_stepy;
	return (0);
}

int			verti_walldist(t_mlxdata *data, t_rayparams *ray,
							int *vobjectype)
{
	int blocktype;

	ray->vertical_object_dist = MAX_DISTANCE;
	while (1)
	{
		if (!raystillinsidemap(data, ray->vertical_x, ray->vertical_y))
		{
			ray->vertical_hit_dist = MAX_DISTANCE;
			break ;
		}
		else if (((blocktype) = data->grid->table
				[(int)ray->vertical_y >> 6][(int)ray->vertical_x >> 6]))
		{
			if (vblock(data, ray, blocktype, vobjectype))
				break ;
		}
		else
		{
			ray->vertical_x += ray->vertical_stepx;
			ray->vertical_y += ray->vertical_stepy;
		}
	}
	return (blocktype);
}
