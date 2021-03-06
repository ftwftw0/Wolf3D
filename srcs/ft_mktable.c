/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mktable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 13:16:04 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/03 00:19:45 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <fcntl.h>

t_grid	*ft_mktable(char *path)
{
	t_grid	*grid;
	char	*str;
	int		fd;
	int		**tmp;

	if ((fd = open(path, O_RDONLY, S_IREAD)) == -1 ||
		!(grid = (t_grid *)malloc(sizeof(t_grid))))
	{
		ft_putendl_fd("Bad map.", 2);
		return (NULL);
	}
	grid->columns = 0;
	while (get_next_line(fd, &str) >= 0)
	{
		tmp = grid->table;
		grid->table = (int **)malloc(sizeof(int*) * (grid->columns + 1));
		ft_memcpy(grid->table, tmp, sizeof(int*) * grid->columns);
		grid->table[grid->columns] = ft_createline(str);
		free(str);
		grid->columns++;
	}
	while (grid->table[grid->columns - 1] == NULL)
		grid->columns--;
	close(fd);
	return (grid);
}

void	ft_puttab(t_grid *grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < grid->columns)
	{
		j = 0;
		while (j <= grid->table[i][0])
		{
			ft_putnbr(grid->table[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putstr("Nb lines : ");
	ft_putnbr(grid->columns);
	ft_putchar('\n');
}

int		*ft_createline(char *str)
{
	int *tab;
	int columns;
	int i;

	if (!str || *str == '\n' || *str == '\0')
		return (NULL);
	columns = ft_countcolumns(str);
	if (*str == '\n' || columns == 0)
		return (NULL);
	tab = (int*)malloc(sizeof(int) * (columns + 1));
	i = 0;
	tab[i++] = columns;
	while (*str != '\0' && *str != '\n')
	{
		while (*str == ' ')
			str++;
		if (ft_isdigit(*str) || *str == '-')
			tab[i++] = ft_atoi(str);
		while (*str != '\0' && *str != '\n' && *str != ' ')
			str++;
	}
	return (tab);
}

int		ft_countcolumns(char *str)
{
	int columns;

	columns = 0;
	while (*str != '\0' && *str != '\n')
	{
		while (*str == ' ')
			str++;
		if (ft_isdigit(*str) || *str == '-')
			columns++;
		while (*str != '\0' && *str != '\n' && *str != ' ')
			str++;
	}
	return (columns);
}
