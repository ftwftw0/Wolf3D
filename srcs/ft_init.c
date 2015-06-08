/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 15:02:33 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/03 00:11:26 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void		init_hooks(t_mlxdata *data)
{
	data->hooks.textured = 0;
	data->hooks.shooting = 0;
	data->hooks.forward = 0;
	data->hooks.backward = 0;
	data->hooks.strafeleft = 0;
	data->hooks.straferight = 0;
	data->hooks.camleft = 0;
	data->hooks.camright = 0;
	data->hooks.shooting = 0;
	data->hooks.crouch = 0;
	data->hooks.jumping = 0;
}

t_mlxdata	*ft_init(int argc, char **argv)
{
	t_mlxdata	*data;

	if (argv[argc - 1])
		argc = argc + 1;
	if (!(data = (t_mlxdata *)malloc(sizeof(t_mlxdata))) ||
		!(data->env.mlx = mlx_init()) ||
		!(data->env.window = mlx_new_window(data->env.mlx, WIDTH, HEIGHT,
											"TheDudeNukesThem")))
		return (NULL);
	data->playerpos.x = BLOCKSIZE;
	data->playerpos.y = BLOCKSIZE;
	data->score = 0;
	data->mvspeed = MOVESPEED;
	data->rotspeed = ROTSPEED;
	data->img.ptr = NULL;
	data->img.endian = 1;
	data->img.bpp = 32;
	data->grid = NULL;
	data->skycolor = SKYCOLOR;
	data->floorcolor = FLOORCOLOR;
	data->wallheight = WALL_HEIGHT * HEIGHT;
	data->playerheight = 0;
	init_hooks(data);
	load_txtures(data);
	return (data);
}
