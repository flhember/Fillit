/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:01:51 by brpinto           #+#    #+#             */
/*   Updated: 2019/01/18 15:58:56 by flhember         ###   ########.fr       */
/*   Updated: 2019/01/17 16:11:36 by brpinto          ###   ########.fr       */
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
				if (ymin == 0 && xmin == 0)
					return (tetri);
				else
				{

					tetri[i - ymin][j - xmin] = tetri[i][j];
					tetri[i][j] = '.';
				}
			}
			j++;
		}
		i++;
	}
	return (tetri);
}
