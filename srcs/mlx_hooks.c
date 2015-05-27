/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 23:00:30 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/27 16:14:32 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

int		mouse_hook2(int button, int x, int y, t_mlxdata *data)
{
	(void)x;
	(void)y;
	if (button == 5)
		(void)data;
	return (1);
}

int		mouse_hook(int button, int x, int y, t_mlxdata *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		(void)data;
	mouse_hook2(button, x, y, data);
	printf("\n Mouse button pressed : %i", button);
	return (1);
}

void	key_hkmove(int keycode, t_mlxdata *data)
{
	if (keycode == SPRINT)
		data->mvspeed = MOVESPEED;
	if (keycode == FORWARD)
		data->hooks.forward = 0;
	if (keycode == DOWNWARD)
		data->hooks.backward = 0;
	if (keycode == STRAFELEFT)
		data->hooks.strafeleft = 0;
	if (keycode == STRAFERIGHT)
		data->hooks.straferight = 0;
	if (keycode == TURNLEFT)
		data->hooks.camleft = 0;
	if (keycode == TURNRIGHT)
		data->hooks.camright = 0;
}

int		key_hook(int keycode, t_mlxdata *data)
{
	printf("\n Key pressed : %i", keycode);
	key_hkmove(keycode, data);
	if (keycode == PAUSE)
		usleep(10000000);
	if (keycode == SHOOT)
		data->hooks.shooting = 0;
	if (keycode == POWER)
		data->hooks.powering = 0;
	if (keycode == ESCAPE)
		exit(0);
	return (1);
}

int keypress_hook(int keycode, t_mlxdata *data)
{
	printf("\nHallelujah\n");
//	if (keycode == SHOOT)
//		usleep(1000000);
//		data->hooks.shooting = 1;
	if (keycode == POWER)
		data->hooks.powering = 1;
	if (keycode == FORWARD)
		data->hooks.forward = 1;
	if (keycode == DOWNWARD)
		data->hooks.backward = 1;
	if (keycode == STRAFELEFT)
		data->hooks.strafeleft = 1;
	if (keycode == STRAFERIGHT)
		data->hooks.straferight = 1;
	if (keycode == SPRINT)
		data->mvspeed = MOVESPEED * 2;
	if (keycode == TURNLEFT)
		data->hooks.camleft = 1;
	if (keycode == TURNRIGHT)
		data->hooks.camright = 1;
	return (0);
}
