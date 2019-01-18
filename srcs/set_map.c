/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:47:27 by flhember          #+#    #+#             */
/*   Updated: 2019/01/17 18:55:11 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_print_map(t_map *map)
{
	int		i;

	i = 0;
	while (map->map[i])
	{
		ft_putstr(map->map[i]);
		i++;
	}
}

int		ft_sqrt_map(int nb)
{
	int		rc;

	rc = 1;
	if (nb < 1)
		return (0);
	while (rc < (nb / 2))
	{
		if (rc * rc == nb)
			return (rc);
		else if (rc * rc > nb)
			return (rc);
		rc++;
	}
	return (2);
}

t_map	*ft_filling_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(map->map = (char **)malloc(sizeof(char*) * map->xymax + 1)))
		return (0);
	while (i < map->xymax)
	{
		if (!(map->map[i] = (char*)malloc(sizeof(char) * map->xymax + 1)))
			return (0);
		while (j < map->xymax)
		{
			map->map[i][j] = '.';
			j++;
		}
		map->map[i][j] = '\n';
		map->map[i][++j] = '\0';
		i++;
		j = 0;
	}
	map->map[i] = NULL;
	return (map);
}

t_map	*ft_set_map(int xmax)
{
	t_map	*map;

	map = NULL;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (0);
	map->xymax = xmax;
	map = ft_filling_map(map);
	return (map);
}
