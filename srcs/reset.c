/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:01:51 by brpinto           #+#    #+#             */
/*   Updated: 2019/01/16 17:48:32 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	get_xmin(char **tetri)
{
	int xmin;
	int i;
	int j;

	i = 0;
	j = 0;
	xmin = 4;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j] != '\0')
		{
			if (tetri[i][j] == '#' && j <= xmin)
				xmin = j;
			j++;
		}
		i++;
	}
	ft_putstr("xmin = ");
	ft_putnbr(xmin);
	ft_putchar('\n');
	return (xmin);
}

int	get_ymin(char **tetri)
{
	int ymin;
	int i;
	int j;

	i = 0;
	j = 0;
	ymin = 4;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j] != '\0')
		{
			if (tetri[i][j] == '#' && i <= ymin)
				ymin = i;
			j++;
		}
		i++;
	}
	ft_putstr("ymin = ");
	ft_putnbr(ymin);
	ft_putchar('\n');
	return (ymin);
}

char **reset(char **tetri)
{
	int xmin;
	int ymin;
	int i;
	int j;

	i = 0;
	j = 0;
	ymin = get_ymin(tetri);
	xmin = get_xmin(tetri);
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j] != '\0')
		{
			if (tetri[i][j] == '#')
			{
				tetri[i - ymin][j - xmin] = tetri[i][j];
				tetri[i][j] = '.';
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (tetri[i])
	{
		ft_putstr(tetri[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
	return (tetri);
}
