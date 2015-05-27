/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_show.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 05:31:32 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/27 16:10:49 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void tracewall(t_mlxdata *data, int x, int wallheight)
{
	int topwall;
	int botwall;
	int y;

	y = -1;
	topwall = HEIGHT / 2 - wallheight;
	botwall = HEIGHT / 2 + wallheight;
	while (++y < topwall && y < HEIGHT)
		mlx_putpxl_img(data->img, x,
						y, 0x00ffffff);
	while (++y < botwall && y < HEIGHT)
		mlx_putpxl_img(data->img, x,
						y, 0x00000000);
	while (++y < HEIGHT)
		mlx_putpxl_img(data->img, x,
						y, 0x00ffffff);
}

int		wolf_view(t_mlxdata *data)
{
	int			horizontal_hit_dist;
	int			vertical_hit_dist;
	int			horizontal_map_content;
	int			vertical_map_content;
	int			wall_height;
	t_rayparams p;
	int			ray;
	int			width;
	double		angperpxl;
	double		angle;

//----------------------------------------------------------------------------------
// squares are 64x64 in size !!
//----------------------------------------------------------------------------------
	printf("TGGG\n");
	angle = data->viewangle - FOV / 2;
	angperpxl = FOV / WIDTH;
	width = 0;
	while (angle < data->viewangle + FOV / 2)
	{
		ray = ((angle < 0) ? -((int)angle % 360) : ((int)angle % 360));
		printf("\n   ### Massive debug ray %i started ###    -- Player pos : (%i, %i) = [%i][%i]\n", ray, data->playerpos.x, data->playerpos.y, data->playerpos.y >> 6, data->playerpos.x >> 6);
		p = setup_intersections_params(data, ray);
		//-------------------------------------------------------------------
		// find nearest horizontal intersection ...
		//-------------------------------------------------------------------
		while (1)
		{
//			if (ray > 180 && ray < 270)
//				printf("Any horiz wall at (%i, %i) = [%i][%i] ?? DIST %f\n", p.horizontal_x, p.horizontal_y, p.horizontal_y >> 6, p.horizontal_x >> 6, (abs(data->playerpos.y - p.horizontal_y) / (data->tab_128sin[ray - 180] / 128.)));

			if (p.horizontal_x < 1 || p.horizontal_x >> 6 > (data->grid->table[0][0]) ||
				p.horizontal_y < 0 || p.horizontal_y >> 6 >= (data->grid->columns))
			{
				printf("-== OUT OF MAP : grid->columns : %i > (p.horiz_y>>6) : %i  ==-\n", data->grid->columns, p.horizontal_y >> 6);
				//---------------------------------------------------------------
				// We ran out of the map. Set hit distance to maximum and break
				//---------------------------------------------------------------
				horizontal_hit_dist = MAX_DISTANCE;
				break ;
			}
			else if ((horizontal_map_content = data->grid->table[p.horizontal_y >> 6][p.horizontal_x >> 6]))
			{
				if (ray < 90)
					horizontal_hit_dist = (abs(data->playerpos.y - p.horizontal_y) / (data->tab_128sin[ray] / 128.));
				else if (ray < 180)
					horizontal_hit_dist = (abs(data->playerpos.y - p.horizontal_y) / (data->tab_128sin[180 - ray] / 128.));
				else if (ray < 270)
					horizontal_hit_dist = (abs(data->playerpos.y - p.horizontal_y) / (data->tab_128sin[ray - 180] / 128.));
				else if (ray < 360)
					horizontal_hit_dist = (abs(data->playerpos.y - p.horizontal_y) / (data->tab_128sin[360 - ray] / 128.));
				break;
			}
			else
			{
				p.horizontal_x += p.horizontal_stepx;
				p.horizontal_y += p.horizontal_stepy;
			}
		}

		//----------------------------------------------------------------------
		// find nearest vertical intersection ...
		//----------------------------------------------------------------------
		while (1)
		{
//			if (ray > 180 && ray < 270)
//				printf("Any vertical wall at (%i, %i) = [%i, %i] ?? DIST %f\n", p.vertical_x, p.vertical_y, p.vertical_y >> 6, p.vertical_x >> 6, (abs(data->playerpos.x - p.vertical_x) / (data->tab_128sin[270 - ray] / 128.)));

			if (p.vertical_x < 1 || p.vertical_x >> 6 > (data->grid->table[0][0]) ||
				p.vertical_y < 0 || p.vertical_y >> 6 >= (data->grid->columns))
			{
				printf("-== OUT OF MAP : grid->columns : %i && p.verti_y >> 6 : %i ==-\n", data->grid->columns, p.vertical_y >> 6);
				vertical_hit_dist = MAX_DISTANCE;
				break;
			}
			else if ((vertical_map_content = data->grid->table[p.vertical_y >> 6][p.vertical_x >> 6]))
			{
				if (ray < 90)
					vertical_hit_dist = (abs(data->playerpos.x - p.vertical_x) / (data->tab_128sin[90 - ray] / 128.));//cos(ray);
				else if (ray < 180)
					vertical_hit_dist = (abs(data->playerpos.x - p.vertical_x) / (data->tab_128sin[ray - 90] / 128.));//cos(ray);
				else if (ray < 270)
					vertical_hit_dist = (abs(data->playerpos.x - p.vertical_x) / (data->tab_128sin[270 - ray] / 128.));//cos(ray);
				else if (ray < 360)
					vertical_hit_dist = (abs(data->playerpos.x - p.vertical_x) / (data->tab_128sin[ray - 270] / 128.));//cos(ray);
				break;
			}
			else
			{
				p.vertical_x += p.vertical_stepx;
				p.vertical_y += p.vertical_stepy;
			}
		}
		if (horizontal_hit_dist <= vertical_hit_dist)
		{
			wall_height	= data->wallheight / horizontal_hit_dist;
			printf("Wall height : %i  --  Horiz dist : %i\n", wall_height, horizontal_hit_dist);
//			texture_index  = 64 - (p.horizontal_x & 0x3f);
		}
		else
		{
			wall_height	= data->wallheight / vertical_hit_dist;
			printf("Wall height : %i  --  Verti dist : %i\n", wall_height, vertical_hit_dist);
//			texture_index  = p.vertical_y & 0x3f;
		}
		tracewall(data, width, wall_height); // Trace dont les lignes du murs, une par une biatch
		angle += angperpxl;
		width++;
	}
	return (1);
}
