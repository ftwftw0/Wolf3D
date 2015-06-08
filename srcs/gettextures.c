/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettextures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 23:18:45 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/02 23:20:05 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_img	gettextures(t_mlxdata *data, int type)
{
	if (type == 1)
		return (data->txtures.stone);
	else if (type == 2)
		return (data->txtures.grass);
	else if (type == 3)
		return (data->txtures.dirt);
	else if (type == 6)
		return (data->txtures.planks);
	else if (type == 17)
		return (data->txtures.wood);
	else if (type == 35)
		return (data->txtures.wool);
	else if (type == 95)
		return (data->txtures.glowstone);
	else if (abs(type) == 39)
		return (data->txtures.flower_rose);
	else if (abs(type) == 23)
		return (data->txtures.bush);
	return (data->txtures.stone);
}
