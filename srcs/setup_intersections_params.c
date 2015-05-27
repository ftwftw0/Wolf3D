/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_intersection_params.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 19:06:47 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/27 15:56:59 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

//=====================================================================
// angle 0 to 89 degrees - parameter setup ...
//=====================================================================
t_rayparams setup90(t_mlxdata *data, int angle)
{
	t_rayparams ray;
	long		first_hit;  // temporary variable

	//-----------------------------------------------------------------
	// setup parameters for intersections with horizontal lines
	//-----------------------------------------------------------------
	ray.horizontal_y = (data->playerpos.y & 0xffc0) - 1;
	first_hit = (long)(data->tab_div_128tan[angle] * 2); // 256/tan(angle)
	first_hit *= -(long)(ray.horizontal_y - data->playerpos.y);
	first_hit >>= 8;
	first_hit += (long)data->playerpos.x;
	ray.horizontal_x = (short)first_hit;
	printf("ray.horizontal = (%i, %i)\n", ray.horizontal_x, ray.horizontal_y);
	ray.horizontal_stepx = data->tab_div_128tan[angle] / 2.;  // 64/tan(angle)
	ray.horizontal_stepy = -64;
	printf(" + ray.horizontal_step = (%i, %i)\n", ray.horizontal_stepx, ray.horizontal_stepy);
	//-----------------------------------------------------------------
	// setup parameters for intersections with vertical lines
	//-----------------------------------------------------------------
	ray.vertical_x  = (data->playerpos.x & 0xffc0) + 64;
	first_hit   = (long)(data->tab_128tan[angle] * 2); // 256*tan(angle)
	first_hit  *= -(long)(ray.vertical_x - data->playerpos.x);
	first_hit   >>= 8;
	first_hit  += (long)data->playerpos.y;
	ray.vertical_y = (short)first_hit;
	printf("ray.vertical = (%i, %i)\n", ray.vertical_x, ray.vertical_y);
	ray.vertical_stepx = 64;
	ray.vertical_stepy = -(data->tab_128tan[angle] / 2.); // 64*tan(angle)
	printf(" + ray.vertical_step = (%i, %i)\n", ray.vertical_stepx, ray.vertical_stepy);
	return (ray);
}

//=====================================================================
// angle 90 to 179 degrees - parameter setup ...
//=====================================================================
t_rayparams setup180(t_mlxdata *data, int angle)
{
	t_rayparams ray;
	long		first_hit;  // temporary variable

	angle = 180 - angle;
	//-----------------------------------------------------------------
	// setup parameters for intersections with horizontal lines
	//-----------------------------------------------------------------
	ray.horizontal_y = (data->playerpos.y & 0xffc0) - 1;
	first_hit = (long)(data->tab_div_128tan[angle] * 2); // 256/tan(angle)
	first_hit *= (long)(ray.horizontal_y - data->playerpos.y);
	first_hit >>= 8;
	first_hit += (long)data->playerpos.x;
	ray.horizontal_x = (short)first_hit;
	printf("ray.horizontal = (%i, %i)\n", ray.horizontal_x, ray.horizontal_y);
	ray.horizontal_stepx = -(data->tab_div_128tan[angle] / 2.);  // 64/tan(angle)
	ray.horizontal_stepy = -64;
	printf(" + ray.horizontal_step = (%i, %i)\n", ray.horizontal_stepx, ray.horizontal_stepy);
	//-----------------------------------------------------------------
	// setup parameters for intersections with vertical lines
	//-----------------------------------------------------------------
	ray.vertical_x  = (data->playerpos.x & 0xffc0) - 1;
	first_hit   = (long)(data->tab_128tan[angle] * 2); // 256*tan(angle)
	first_hit  *= (long)(ray.vertical_x - data->playerpos.x);
	first_hit   >>= 8;
	first_hit  += (long)data->playerpos.y;
	ray.vertical_y = (short)first_hit;
	printf("ray.vertical = (%i, %i)\n", ray.vertical_x, ray.vertical_y);
	ray.vertical_stepx = -64;
	ray.vertical_stepy = -(data->tab_128tan[angle] / 2.);  // 64*tan(angle)
	printf(" + ray.vertical_step = (%i, %i)\n", ray.vertical_stepx, ray.vertical_stepy);
	return (ray);
}

//=====================================================================
// angle 180 to 270 degrees - parameter setup ...
//=====================================================================
t_rayparams setup270(t_mlxdata *data, int angle)
{
	t_rayparams ray;
	long		first_hit;  // temporary variable

	//-----------------------------------------------------------------
	// setup parameters for intersections with horizontal lines
	//-----------------------------------------------------------------
	angle = angle - 180;
	ray.horizontal_y = (data->playerpos.y & 0xffc0) + 64;
	first_hit = (long)(data->tab_div_128tan[angle] * 2); // 256/tan(angle)
	first_hit *= -(long)(ray.horizontal_y - data->playerpos.y);
	first_hit >>= 8;
	first_hit += (long)data->playerpos.x;
	ray.horizontal_x = (short)first_hit;
	printf("ray.horizontal = (%i, %i)\n", ray.horizontal_x, ray.horizontal_y);
	ray.horizontal_stepx = -(data->tab_div_128tan[angle] / 2.);  // 64/tan(angle)
	ray.horizontal_stepy = 64;
	printf(" + ray.horizontal_step = (%i, %i)\n", ray.horizontal_stepx, ray.horizontal_stepy);
	//-----------------------------------------------------------------
	// setup parameters for intersections with vertical lines
	//-----------------------------------------------------------------
	ray.vertical_x  = (data->playerpos.x & 0xffc0) - 1;
	first_hit   = (long)(data->tab_128tan[angle] * 2); // 256*tan(angle)
	first_hit  *= -(long)(ray.vertical_x - data->playerpos.x);
	first_hit   >>= 8;
	first_hit  += (long)data->playerpos.y;
	ray.vertical_y = (short)first_hit;
	printf("ray.vertical = (%i, %i)\n", ray.vertical_x, ray.vertical_y);
	ray.vertical_stepx = -64;
	ray.vertical_stepy = (data->tab_128tan[angle] / 2.); // 64*tan(angle)
	printf(" + ray.vertical_step = (%i, %i)\n", ray.vertical_stepx, ray.vertical_stepy);
	return (ray);
}

//=====================================================================
// angle 270 to 360 degrees - parameter setup ...
//=====================================================================
t_rayparams setup360(t_mlxdata *data, int angle)
{
	t_rayparams ray;
	long		first_hit;  // temporary variable

	angle = 360 - angle;
	//-----------------------------------------------------------------
	// setup parameters for intersections with horizontal lines
	//-----------------------------------------------------------------
	ray.horizontal_y = (data->playerpos.y & 0xffc0) + 64;
	first_hit = (long)(data->tab_div_128tan[angle] * 2); // 256/tan(angle)
	first_hit *= (long)(ray.horizontal_y - data->playerpos.y);
	first_hit >>= 8;
	first_hit += (long)data->playerpos.x;
	ray.horizontal_x = (short)first_hit;
	printf("ray.horizontal = (%i, %i)\n", ray.horizontal_x, ray.horizontal_y);
	ray.horizontal_stepx = (data->tab_div_128tan[angle] / 2.);  // 64/tan(angle)
	ray.horizontal_stepy = 64;
	printf(" + ray.horizontal_step = (%i, %i)\n", ray.horizontal_stepx, ray.horizontal_stepy);
	//-----------------------------------------------------------------
	// setup parameters for intersections with vertical lines
	//-----------------------------------------------------------------
	ray.vertical_x  = (data->playerpos.x & 0xffc0) + 64;
	first_hit   = (long)(data->tab_128tan[angle] * 2); // 256*tan(angle)
	first_hit  *= (long)(ray.vertical_x - data->playerpos.x);
	first_hit   >>= 8;
	first_hit  += (long)data->playerpos.y;
	ray.vertical_y = (short)first_hit;
	printf("ray.vertical = (%i, %i)\n", ray.vertical_x, ray.vertical_y);
	ray.vertical_stepx = 64;
	ray.vertical_stepy = (data->tab_128tan[angle] / 2.);  // 64*tan(angle)
	printf(" + ray.vertical_step = (%i, %i)\n", ray.vertical_stepx, ray.vertical_stepy);
	return (ray);
}

t_rayparams	setup_intersections_params(t_mlxdata *data, int angle)
{
	t_rayparams nul;

	if (angle < 90)
		return (setup90(data, angle));
	else if (angle <= 180)
		return (setup180(data, angle));
	else if (angle < 270)
		return (setup270(data, angle));
	else if (angle <= 360)
		return (setup360(data, angle));
	printf("\n\n\n\n\n\n\n\n\nFUCK YOU IL A DIT\n\n\n\n\n\n\n\n");
	return (nul);
}
