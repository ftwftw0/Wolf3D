/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 00:33:42 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/27 13:46:51 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int collisions(t_mlxdata *data, t_ipoint pos)
{
	if (data->grid->table[pos.y>>6][pos.x>>6] > 0)
		return (1);
	return (0);
}

int		wolf_move(t_mlxdata *data, int direction)
{
	double theta;
	t_ipoint newpos;

	theta = data->viewangle * PI / 180;
	if (direction == 1)
	{
		newpos.x = data->playerpos.x + data->mvspeed * cos(theta);
		newpos.y = data->playerpos.y - data->mvspeed * sin(theta);
	}
	else if (direction == 3)
	{
		newpos.x = data->playerpos.x - data->mvspeed * cos(theta);
		newpos.y = data->playerpos.y + data->mvspeed * sin(theta);
	}
	else if (direction == 2)
	{
		newpos.x = data->playerpos.x + data->mvspeed * sin(theta);
		newpos.y = data->playerpos.y + data->mvspeed * cos(theta);
	}
	else if (direction == 4)
	{
		newpos.x = data->playerpos.x - data->mvspeed * sin(theta);
		newpos.y = data->playerpos.y - data->mvspeed * cos(theta);
	}
	if (collisions(data, newpos) == 0)
		data->playerpos = newpos;
	return (0);
}
