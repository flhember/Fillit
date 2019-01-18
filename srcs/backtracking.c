/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:45:14 by flhember          #+#    #+#             */
/*   Updated: 2019/01/17 18:55:47 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_put_piece(t_piece *piece, t_map *map, char c)
{
	int		i;
	int		j;

	j = 0;
	while (piece->y + j <= map->xymax)
	{
		i = 0;
		while (piece->x + i <= map->xymax)
		{
			if (piece->content[piece->y + j][piece->x + i] == '#')
				map->map[piece->y + j][piece->x + i] = c;
			i++;
		}
		j++;
	}
}

int		ft_check_piece(t_map *map, t_piece *piece)
{
	int		j;
	int		i;

	j = 0;
	while (j + piece->y < map->xymax)
	{
		i = 0;
		while (i + piece->x < map->xymax)
		{
			if (piece->content[j][i] == '#')
			{
				if (map->map[piece->y + j][piece->x + i] != '.')
					return (0);
			}
			i++;
		}
		j++;
	}
	ft_put_piece(piece, map, piece->alpha);
	return (1);
}

int		ft_backtracking(t_piece *piece, t_map *map)
{
	if (piece == NULL)
		return (1);
	while (piece->y + piece->height - 1 < map->xymax)
	{
		piece->x = 0;
		while (piece->x + piece->width - 1 < map->xymax)
		{
			if (ft_check_piece(map, piece))
			{
				if (ft_backtracking(piece->next, map))
				{
					printf("ca passe");
					return (1);
				}
				else
					printf("non");
					ft_put_piece(piece, map, '.');
			}
			piece->x++;
		}
		piece->y++;
	}
	return (0);
}

int		ft_lstlen(t_piece *piece)
{
	int		nb;

	nb = 0;
	while (piece)
	{
		nb++;
		piece = piece->next;
	}
	return (nb);
}

int		ft_resolution(t_piece *piece)
{
	int		xmax;
	int		nb_piece;
	t_map	*map;

	nb_piece = ft_lstlen(piece);
	xmax = ft_sqrt_map(nb_piece * 4);
	map = ft_set_map(xmax);
	while (!(ft_backtracking(piece, map)))
	{
		printf("map++");
		piece->x = 0;
		piece->y = 0;
		xmax++;
		map = ft_set_map(xmax);
	}
	ft_print_map(map);
	return (0);
}
