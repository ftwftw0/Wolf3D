/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 17:09:08 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/27 16:32:22 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <sys/time.h>
#include <stdio.h>
#include "libft.h"

int		main(int argc, char **argv)
{
	t_mlxdata	*data;
	t_grid		*grid;

	if (!(data = ft_init(argc, argv)))
		return (0);
	if (!(grid = (argc < 2) ? ft_mktable("Maps/basic.fdf") : ft_mktable(argv[1])))
		return (0);
	data->viewangle = 100;
	ft_puttab(grid);
	data->grid = grid;
	data->playerpos.x = 200;
	data->playerpos.y = 200;
	data->a.x = WIDTH / 2;
    data->a.y = HEIGHT;
	data->img = mlx_create_image(data, WIDTH, HEIGHT, 32);
	mlx_mouse_hook(data->env.window, mouse_hook, data);
	mlx_key_hook(data->env.window, key_hook, data);
	mlx_hook(data->env.window, 2, (1L << 0), keypress_hook, data);
	mlx_expose_hook(data->env.window, expose_hook, data);
	mlx_loop_hook(data->env.mlx, loop_hook, data);
	printf("\nBefore mlx_loop\n");
	mlx_loop(data->env.mlx);
	printf("End of program.\n");
	return (1);
}

int		loop_hook(t_mlxdata *data)
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
	printf("\nBefore expose_hook\n");
	expose_hook(data);
	return (1);
}

int wolf_debug(t_mlxdata *data, int usec)
{
    char *tmp;

	printf("Into wolfdebug\n");
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
    mlx_string_put(data->env.mlx, data->env.window, 110, 50, 0x00000000,
                   (tmp = ft_itoa((int)data->playerpos.y)));
    free(tmp);
//    mlx_string_put(data->env.mlx, data->env.window, 10, 65, 0x00000000,
//                   "Sin : ");
//    mlx_string_put(data->env.mlx, data->env.window, 70, 65, 0x00000000,
//                   (char *)ft_dtoa((double)sin(data->viewangle * PI / 180), 6));
    return (0);
}

int		expose_hook(t_mlxdata *data)
{
	static struct timeval time;
	struct timeval nowtime;

	printf("\nInto expose!\n");
	gettimeofday(&nowtime, NULL);
	mlx_destroy_image(data->env.mlx, data->img.ptr);
	data->img = mlx_create_image(data, WIDTH, HEIGHT, 32);
	wolf_view(data);
	mlx_put_image_to_window(data->env.mlx,
							data->env.window,
							data->img.ptr,
							0, 0);
	wolf_debug(data, nowtime.tv_usec - time.tv_usec);
	time = nowtime;
	return (1);
}
