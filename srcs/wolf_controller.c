/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 05:13:16 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/08 14:28:14 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		isbreakable(int material)
{
	if (material == 10000 ||
		material == 7 ||
		material == 1 ||
		material == 0)
		return (0);
	else
		return (1);
}

int				wolf_controller(t_mlxdata *data)
{
	int *material;

	material = &(data->grid->table[(int)(data->target.y / BLOCKSIZE)]
									[(int)(data->target.x / BLOCKSIZE)]);
	if (data->hooks.shooting && isbreakable(*material))
	{
		data->score += *material;
		*material = 0;
	}
	else if (data->hooks.powering && isbreakable(*material))
		data->grid->table[(int)(data->target.y / BLOCKSIZE)]
						[(int)(data->target.x / BLOCKSIZE)] = 666;
	return (1);
}
