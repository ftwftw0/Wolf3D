/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_cpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 03:28:33 by flagoutt          #+#    #+#             */
/*   Updated: 2015/01/26 05:20:34 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Copys a square from img2 to img1 at data->a position.
*/
int		mlx_img_cpy(t_mlxdata *data, t_img img1, t_img img2, t_ipoint a, t_ipoint b)
{
	void *imgptr1;
	void *imgptr2;
	int k;

	if (!img1.ptr || !img2.ptr)
		perror("Bad images to copy.");
	if (b.x > WIDTH || b.y > HEIGHT)
		perror("Bad square to copy.");
//	if (data->a.y + a.y > HEIGHT || a.x < 0 || a.y < 0)
//        return (0);
	imgptr1 = mlx_get_data_addr(img1.ptr,
							   &(img1.bpp),
							   &(img1.sizeline),
							   &(img1.endian));
	imgptr2 = mlx_get_data_addr(img2.ptr,
							   &(img2.bpp),
							   &(img2.sizeline),
							   &(img2.endian));
	k = abs(a.y - b.y) + 1;
	while (k)
	{
		ft_memcpy(imgptr1 + (data->a.y + k) * (img1.sizeline) + (data->a.x) * 4, 
				imgptr2 + (a.y + k) * (img2.sizeline) + (a.x) * 4,
				  (b.x - a.x + 1) * 4);
		k--;
	}
	return (1);
}
