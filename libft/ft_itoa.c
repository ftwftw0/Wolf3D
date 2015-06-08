/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 18:37:34 by flagoutt          #+#    #+#             */
/*   Updated: 2015/01/14 18:37:35 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tobecontinued(char *str, int n, int *i, int div)
{
	while (n / div > 9)
		div *= 10;
	while (div != 0)
	{
		str[*i] = (n / div) + 48;
		n %= div;
		div /= 10;
		(*i)++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		div;

	i = 0;
	div = 1;
	if (n == -2147483648)
	{
		str = (char *)malloc(sizeof(char) * 12);
		ft_strcpy(str, "-2147483648");
		return (str);
	}
	str = (char *)malloc(sizeof(char) * ft_intlen(n) + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[i++] = '-';
		n *= -1;
	}
	str = ft_tobecontinued(str, n, &i, div);
	str[i] = '\0';
	return (str);
}
