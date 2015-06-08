/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 17:09:08 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/08 14:25:30 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			main(int argc, char **argv)
{
	t_mlxdata	*data;

	if (!(data = ft_init(argc, argv)) ||
		(!(data->grid = (argc < 2) ? ft_mktable("Maps/killemall.map") :
			ft_mktable(argv[1]))))
		return (0);
	data->viewangle = 270;
	data->playerpos.x = 350;
	data->playerpos.y = 150;
	if (!ft_strcmp(argv[1], "Maps/killemall.map") || argc < 2)
	{
		data->playerpos.x = BLOCKSIZE * 24 + 10;
		data->playerpos.y = BLOCKSIZE * 24 + 10;
	}
	data->a.x = WIDTH / 2;
	data->a.y = HEIGHT;
	data->img = mlx_create_image(data, WIDTH, HEIGHT, 32);
	mlx_key_hook(data->env.window, key_hook, data);
	mlx_hook(data->env.window, 2, (1L << 0), keypress_hook, data);
	mlx_expose_hook(data->env.window, expose_hook, data);
	mlx_loop_hook(data->env.mlx, loop_hook, data);
	mlx_loop(data->env.mlx);
	return (1);
}

static void	justjump(t_mlxdata *data)
{
	static int jmp = JUMP_HEIGHT;

	data->playerheight += jmp;
	jmp -= 5;
	if (jmp < -JUMP_HEIGHT)
	{
		jmp = JUMP_HEIGHT;
		data->hooks.jumping = 0;
	}
}

int			loop_hook(t_mlxdata *data)
{
	if (data->hooks.forward)
		wolf_move(data, 1);
	else if (data->hooks.backward)
		wolf_move(data, 3);
	if (data->hooks.strafeleft)
		wolf_move(data, 4);
	else if (data->hooks.straferight)
		wolf_move(data, 2);
	if (data->hooks.camleft)
		data->viewangle += data->rotspeed;
	if (data->hooks.camright)
		data->viewangle -= data->rotspeed;
	if (data->hooks.jumping)
		justjump(data);
	wolf_controller(data);
	expose_hook(data);
	return (1);
}

int			wolf_debug(t_mlxdata *data, int usec)
{
	char *tmp;

	mlx_string_put(data->env.mlx, data->env.window, 10, 20, 0x00000000,
				"FPS :");
	mlx_string_put(data->env.mlx, data->env.window, 70, 20, 0x00000000,
				(tmp = ft_itoa((int)(1 / (usec / 1000000.)))));
	free(tmp);
	mlx_string_put(data->env.mlx, data->env.window, 10, 35, 0x00000000,
				"Ang :");
	mlx_string_put(data->env.mlx, data->env.window, 70, 35, 0x00000000,
				(tmp = ft_itoa((int)data->viewangle)));
	free(tmp);
	mlx_string_put(data->env.mlx, data->env.window, 10, 50, 0x00000000,
				"Pos :    ,");
	mlx_string_put(data->env.mlx, data->env.window, 70, 50, 0x00000000,
				(tmp = ft_itoa((int)data->playerpos.x)));
	free(tmp);
	mlx_string_put(data->env.mlx, data->env.window, 115, 50, 0x00000000,
				(tmp = ft_itoa((int)data->playerpos.y)));
	free(tmp);
	mlx_string_put(data->env.mlx, data->env.window, WIDTH / 2 - 10, 10,
				0x00449922, (tmp = ft_itoa(data->score)));
	free(tmp);
	return (0);
}

int			expose_hook(t_mlxdata *data)
{
	static struct timeval	time;
	struct timeval			nowtime;

	gettimeofday(&nowtime, NULL);
	mlx_destroy_image(data->env.mlx, data->img.ptr);
	data->img = mlx_create_image(data, WIDTH, HEIGHT, 32);
	wolf_view(data);
	mlx_put_image_to_window(data->env.mlx,
							data->env.window,
							data->img.ptr,
							0, 0);
	if (data->hooks.textured)
		wolf_putweapon(data);
	wolf_debug(data, nowtime.tv_usec - time.tv_usec);
	time = nowtime;
	return (1);
}
