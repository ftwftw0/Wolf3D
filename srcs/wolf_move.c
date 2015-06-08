/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 00:33:42 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/03 02:38:24 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			collisions(t_mlxdata *data, t_ipoint pos)
{
	if ((int)(pos.x) < 1 || (int)(pos.x) >> 6 > (data->grid->table[0][0]) ||
		(int)(pos.y) < 0 || (int)(pos.y) >> 6 >= (data->grid->columns))
		return (1);
	if (data->grid->table[((int)(pos.y)) >> 6][((int)(pos.x)) >> 6] > 0)
		return (1);
	return (0);
}

static void	splittedmoves(t_mlxdata *data, int direction,
							t_ipoint *newpos, double theta)
{
	if (direction == 2)
	{
		(*newpos).x = data->playerpos.x + data->mvspeed * sin(theta);
		(*newpos).y = data->playerpos.y + data->mvspeed * cos(theta);
	}
	else if (direction == 4)
	{
		(*newpos).x = data->playerpos.x - data->mvspeed * sin(theta);
		(*newpos).y = data->playerpos.y - data->mvspeed * cos(theta);
	}
}

int			wolf_move(t_mlxdata *data, int direction)
{
	double		theta;
	t_ipoint	newpos;

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
	splittedmoves(data, direction, &newpos, theta);
	if (collisions(data, newpos) == 0)
		data->playerpos = newpos;
	return (0);
}
