/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_txtures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 05:39:21 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/03 02:02:38 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_img	loadimage(t_mlxdata *data, char *path, int xsize, int ysize)
{
	t_img img;

	img.size.x = xsize;
	img.size.y = ysize;
	img.ptr = (void *)mlx_xpm_file_to_image(data->env.mlx, path,
											&xsize, &ysize);
	return (img);
}

static void		load64textures(t_mlxdata *data)
{
	int size;

	size = 64;
	data->txtures.wool = loadimage(data, "images/wool_colored_red.xpm",
									size, size);
	data->txtures.flower_rose = loadimage(data, "images/flower_rose.xpm",
									size, size);
	data->txtures.bush = loadimage(data, "images/leaves_jungle.xpm",
									size, size);
	data->txtures.planks = loadimage(data, "images/planks_jungle.xpm",
									size, size);
	data->txtures.dirt = loadimage(data, "images/dirt.xpm",
									size, size);
	data->txtures.glowstone = loadimage(data, "images/glowstone.xpm",
									size, size);
}

int				load_txtures(t_mlxdata *data)
{
	int		size;

	size = 256;
	data->txtures.sky = loadimage(data, "images/sky.xpm", size, size);
	data->txtures.stone = loadimage(data, "images/stonewall.xpm", size, size);
	data->txtures.wood = loadimage(data, "images/woodwall.xpm", size, size);
	data->txtures.hell = loadimage(data, "images/hell.xpm", size, size);
	data->txtures.grass = loadimage(data, "images/grass.xpm",
									size, size);
	data->txtures.weapon = loadimage(data, "images/weapons/weapon.xpm",
									255, 133);
	data->txtures.weaponfiring = loadimage(data,
									"images/weapons/weaponfiring.xpm",
									255, 133);
	load64textures(data);
	return (1);
}
