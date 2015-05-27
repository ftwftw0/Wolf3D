/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_putpxl_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 14:50:46 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/05 16:19:47 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int mlx_putpxl_img(t_img img, int x, int y, int color)
{
	char *imgptr;
	int *pxl;

	imgptr = mlx_get_data_addr(img.ptr, &(img.bpp), &(img.sizeline), &(img.endian));
	if (x > img.size.x || x < 0 || y < 0 || y > img.size.y)
		return (0);
	pxl = (int*)(imgptr + y * img.sizeline + 4 * x);
	*pxl = color;
	return (1);
}

int	 mlx_pixel_putsquare(t_mlxdata *data, int xsize, int ysize, int color)
{
	int xmax;
	int ymax;
	int x;
	int y;

	y = 0;
	x = 0;
	xmax = x + xsize;
	ymax = y + ysize;
	while (x < xmax)
	{
		y = 0;
		while (y < ymax)
		{
			mlx_putpxl_img(data->img, x, y, color);
			y++;
		}
		x++;
	}
	return (1);
}
