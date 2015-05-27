/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 05:13:16 by flagoutt          #+#    #+#             */
/*   Updated: 2015/01/30 10:46:36 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		isbreakable(int material)
{
	if (material != 999
		&& material != 7)
		return (1);
	else
		return (0);
}

int		wolf_controller(t_mlxdata *data)
{
	int *material;

	material = &(data->grid->table[(int)(data->target.y / BLOCKSIZE)]
									[(int)(data->target.x / BLOCKSIZE)]);
	if (data->hooks.shooting && isbreakable(*material))
		*material = 0;
	else if (data->hooks.powering && isbreakable(*material))
		data->grid->table[(int)(data->target.y / BLOCKSIZE)][(int)(data->target.x / BLOCKSIZE)] = 666;

	return (1);
}
