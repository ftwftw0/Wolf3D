/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:25:56 by flagoutt          #+#    #+#             */
/*   Updated: 2014/11/25 15:53:32 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_filelstdel(t_file **alst)
{
	t_file		*lst;
	t_file		*last;

	if (!alst)
		return ;
	if (!*alst)
		return ;
	lst = *alst;
	while (lst)
	{
		last = lst;
		lst = lst->next;
		free(last->perms);
		free(last->uid);
		free(last->gid);
		free(last->name);
		free(last);
	}
	*alst = NULL;
}
