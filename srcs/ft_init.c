
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 15:02:33 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/27 17:00:56 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void		init_hooks(t_mlxdata *data)
{
	data->hooks.shooting = 0;
	data->hooks.forward = 0;
	data->hooks.backward = 0;
	data->hooks.strafeleft = 0;
	data->hooks.straferight = 0;
	data->hooks.camleft = 0;
	data->hooks.camright = 0;
	data->hooks.shooting = 0;
}

void		precalculs(t_mlxdata *data)
{
	int	ang;
	double rad;

	ang = 89;
	while (ang > 0)
	{
		rad = ang * PI / 180;
		printf("  %i degree = %f radians\n", ang, rad);
		data->tab_128sin[ang] = 128. * sin(rad);
		printf("128sin[%i] = %i\n", ang, data->tab_128sin[ang]);
		data->tab_div_128sin[ang] = 128. / sin(rad);
		printf("div_128sin[%i] = %i\n", ang, data->tab_div_128sin[ang]);
		data->tab_128tan[ang] = 128. * tan(rad);
		printf("128tan[%i] = %i\n", ang, data->tab_128tan[ang]);
		data->tab_div_128tan[ang] = 128. / tan(rad);
		printf("div_128tan[%i] = %i\n", ang, data->tab_div_128tan[ang]);
		ang--;
	}
	printf("  %i degree = %f radians\n", ang, rad);
	data->tab_128sin[ang] = 128. * sin(rad);
	printf("128sin[%i] = %i\n", ang, data->tab_128sin[ang]);
	data->tab_div_128sin[ang] = 128. / sin(rad);
	printf("div_128sin[%i] = %i\n", ang, data->tab_div_128sin[ang]);
	data->tab_128tan[ang] = 128. * tan(rad);
	printf("128tan[%i] = %i\n", ang, data->tab_128tan[ang]);
	data->tab_div_128tan[ang] = 128. / tan(rad);
	printf("div_128tan[%i] = %i\n", ang, data->tab_div_128tan[ang]);
/*
	data->tab_128sin[ang] = 2;
	printf("128sin[%i] = %i\n", ang, data->tab_128sin[ang]);
	data->tab_div_128sin[ang] = 14666;
	printf("div_128sin[%i] = %i\n", ang, data->tab_div_128sin[ang]);
	data->tab_128tan[ang] = 2;
	printf("128tan[%i] = %i\n", ang, data->tab_128tan[ang]);
	data->tab_div_128tan[ang] = 14666;
	printf("div_128tan[%i] = %i\n", ang, data->tab_div_128tan[ang]);
*/
}

t_mlxdata	*ft_init(int argc, char **argv)
{
	t_mlxdata	*data;

	if (argv[argc - 1])
		argc = argc + 1;
	if (!(data = (t_mlxdata *)malloc(sizeof(t_mlxdata))))
		return (NULL);
	if (!(data->env.mlx = mlx_init()))
		return (NULL);
	if (!(data->env.window = mlx_new_window(data->env.mlx, WIDTH, HEIGHT, "TheDudeNukesThem")))
		return (NULL);
	data->playerpos.x = BLOCKSIZE;
	data->playerpos.y = BLOCKSIZE;
	data->mvspeed = MOVESPEED;
	data->rotspeed = ROTSPEED;
	data->img.ptr = NULL;
	data->img.endian = 1;
	data->img.bpp = 32;
	data->grid = NULL;
	data->skycolor = SKYCOLOR;
	data->floorcolor = FLOORCOLOR;
	data->wallheight = WALL_HEIGHT * HEIGHT;
	data->camdist = 255;
	init_hooks(data);
	precalculs(data);
	return (data);
}
