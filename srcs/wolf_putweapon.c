/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_putweapon.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 05:58:21 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/03 02:38:39 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		wolf_putweapon(t_mlxdata *data)
{
	if (data->hooks.shooting)
		mlx_put_image_to_window(data->env.mlx,
								data->env.window,
								data->txtures.weaponfiring.ptr,
								WIDTH / 2,
								HEIGHT - data->txtures.weaponfiring.size.y + 1);
	else
		mlx_put_image_to_window(data->env.mlx,
								data->env.window,
								data->txtures.weapon.ptr,
								WIDTH / 2,
								HEIGHT - data->txtures.weapon.size.y + 1);
	return (1);
}
