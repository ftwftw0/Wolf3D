/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:55:36 by flagoutt          #+#    #+#             */
/*   Updated: 2014/11/26 13:34:32 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file		*ft_filelstnew(void)
{
	t_file	*lst;

	if ((lst = (t_file *)malloc(sizeof(t_file))))
	{
		lst->perms = NULL;
		lst->plinks = 0;
		lst->uid = NULL;
		lst->gid = NULL;
		lst->size = 0;
		lst->timestamp = 0;
		lst->name = NULL;
		lst->next = NULL;
		lst->prev = NULL;
		return (lst);
	}
	return (NULL);
}
