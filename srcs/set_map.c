/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:47:27 by flhember          #+#    #+#             */
/*   Updated: 2019/01/15 18:14:30 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillittest.h"

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
	return (0);
}

t_map	*ft_filling_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(map->map = (char **)malloc(sizeof(char*) * map->xmax + 1)))
		return (0);
	while (i < map->xmax)
	{
		if (!(map->map[i] = (char*)malloc(sizeof(char) * map->xmax + 1)))
			return (0);
		while (j < map->xmax)
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

t_map	*ft_set_map(int nb_piece)
{
	t_map	*map;

	map = NULL;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (0);
	map->xmax = ft_sqrt_map(nb_piece * 4);
	map->ymax = map->xmax;
	map = ft_filling_map(map);
	return (map);
}


/*
**	ft "main" = creat_map a changer
*/

int		creat_map()
{
	t_map *map;
	int		i = 0;
	map = ft_set_map(5);
	while (map->map[i])
	{
		printf("%s", map->map[i]);
		i++;
	}
	return (0);
}
