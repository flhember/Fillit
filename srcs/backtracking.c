/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:45:14 by flhember          #+#    #+#             */
/*   Updated: 2019/01/15 18:13:30 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_check_piece(int x, int y, t_map *map, t_piece *piece)
{
	int		i;

	i = 0;
	while (piece->content[i] != '#')
		i++;
	while (y < map->ymax)
	{
		x = 0;
		while (x < map->xmax)
		{
			if (map->map[y][x] == '.' && piece->content[i] == '#')
			{
				map->map[y][x] = '#';
				x++;
			}
			else
				return (0);
			i++;
		}
	}
	return (1)
}

int		ft_delete(t_piece *piece, t_map map)
{
	int		i;

	i = 0;



}

int		ft_backtracking(t_piece piece, t_map map, int i)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->ymax)
	{
		x = 0;
		while (x < map->xmax)
		{
			if (ft_check_piece(x, y, piece[i], map))
			{
				if (ft_backtracking(piece, map, i + 1))
					return (1);
				else
					ft_delete(piece, map)
			}
			x++;
		}
		y++;
	}
	return (0);
}
