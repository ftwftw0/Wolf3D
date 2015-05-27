/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_getpxl_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 05:38:30 by flagoutt          #+#    #+#             */
/*   Updated: 2015/01/26 06:25:44 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int mlx_getpxl_img(int x, int y, t_img img)
{
    char    *imgptr;
    int     *pxl;

    if (x >= img.size.x || x < 0 || y < 0 || y >= img.size.y)
        return (0);
    imgptr = mlx_get_data_addr(img.ptr,
							   &(img.bpp),
							   &(img.sizeline),
							   &(img.endian));
    pxl = (int*)(imgptr + y * img.sizeline + 4 * x);
    return (*pxl);
}
