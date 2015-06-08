/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 23:00:30 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/08 14:26:46 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void		key_hkmove(int keycode, t_mlxdata *data)
{
	if (keycode == KEY_T)
		data->hooks.textured = (data->hooks.textured) ? 0 : 1;
	if (keycode == SPRINT)
		data->mvspeed -= MOVESPEED;
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

int			key_hook(int keycode, t_mlxdata *data)
{
	key_hkmove(keycode, data);
	if (keycode == PAUSE)
		usleep(10000000);
	if (keycode == SHOOT)
		data->hooks.shooting = 0;
	if (keycode == POWER)
		data->hooks.powering = 0;
	if (keycode == CROUCH && data->hooks.crouch)
	{
		data->playerheight += HEIGHT / 10;
		data->hooks.crouch = 0;
		data->mvspeed += MOVESPEED / 2;
	}
	if (keycode == ESCAPE)
		exit(0);
	return (1);
}

static void	keypress_norm(int keycode, t_mlxdata *data)
{
	if (keycode == TURNRIGHT)
		data->hooks.camright = 1;
	if (keycode == CROUCH && data->hooks.crouch == 0)
	{
		data->mvspeed -= MOVESPEED / 2;
		data->playerheight -= HEIGHT / 10;
		data->hooks.crouch = 1;
	}
	if (keycode == JUMP)
		data->hooks.jumping = 1;
}

int			keypress_hook(int keycode, t_mlxdata *data)
{
	if (keycode == SHOOT)
		data->hooks.shooting = 1;
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
		data->mvspeed += MOVESPEED;
	if (keycode == TURNLEFT)
		data->hooks.camleft = 1;
	keypress_norm(keycode, data);
	return (0);
}
