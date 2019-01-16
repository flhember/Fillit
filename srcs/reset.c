/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:01:51 by brpinto           #+#    #+#             */
/*   Updated: 2019/01/16 14:22:11 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char **reset_tetri(t_piece *tetri)
{
	int xmin;
	int ymin;
	int i;
	int j;

	i = 0;
	j = 0;
	xmin = tetri->x;
	ymin = tetri->y;
	while (tetri->content[i])
	{
		while (tetri->content[i][j] != '\0')
		{
			if (tetri->content[i][j] == '#' && j <= xmin)
				xmin = j;
			j++;
		}
		j = 0;
		i++;
	}
	return (tetri->content);
}
