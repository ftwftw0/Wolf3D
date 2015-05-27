/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_txtures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 05:39:21 by flagoutt          #+#    #+#             */
/*   Updated: 2015/01/30 07:01:26 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		load_txtures(t_mlxdata *data)
{
	int		 size;

	size = 256;
	data->txtures.wall1.size.x = BLOCKSIZE;
	data->txtures.wall1.size.y = BLOCKSIZE;
	data->txtures.wall1.ptr = (void *)mlx_xpm_file_to_image(data->env.mlx, "images/stonewall.xpm", &size, &size);
	data->txtures.wall2.size.x = BLOCKSIZE;
	data->txtures.wall2.size.y = BLOCKSIZE;
	data->txtures.wall2.ptr = (void *)mlx_xpm_file_to_image(data->env.mlx, "images/woodwall.xpm", &size, &size);
	data->txtures.sky.size.x = BLOCKSIZE;
	data->txtures.sky.size.y = BLOCKSIZE;
	data->txtures.sky.ptr = (void *)mlx_xpm_file_to_image(data->env.mlx, "images/sky.xpm", &size, &size);
	data->txtures.hell.size.x = BLOCKSIZE;
	data->txtures.hell.size.y = BLOCKSIZE;
	data->txtures.hell.ptr = (void *)mlx_xpm_file_to_image(data->env.mlx, "images/hell.xpm", &size, &size);
	data->txtures.grass.size.x = BLOCKSIZE;
	data->txtures.grass.size.y = BLOCKSIZE;
	data->txtures.grass.ptr = (void *)mlx_xpm_file_to_image(data->env.mlx, "images/grass.xpm", &size, &size);
	data->txtures.weapon.size.x = 255;
	data->txtures.weapon.size.y = 133;
	data->txtures.weapon.ptr = (void *)mlx_xpm_file_to_image(data->env.mlx, "images/weapons/weapon.xpm", &(data->txtures.weapon.size.x), &(data->txtures.weapon.size.y));
	data->txtures.weaponfiring.size.x = 255;
	data->txtures.weaponfiring.size.y = 133;
	data->txtures.weaponfiring.ptr = (void *)mlx_xpm_file_to_image(data->env.mlx, "images/weapons/weaponfiring.xpm", &(data->txtures.weaponfiring.size.x), &(data->txtures.weaponfiring.size.y));
	return (1);
}
