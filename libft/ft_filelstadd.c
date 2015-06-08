/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:25:30 by flagoutt          #+#    #+#             */
/*   Updated: 2014/12/03 18:44:24 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_filelstadd(t_file **alst, t_file *new)
{
	t_file *tmp;

	if (new)
	{
		new->next = *alst;
		(*alst)->prev = new;
		*alst = new;
	}
}
