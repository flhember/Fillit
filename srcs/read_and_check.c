/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:33:49 by flhember          #+#    #+#             */
/*   Updated: 2019/01/11 15:08:02 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_check_char(char *tetri, int *grid_height)
{
	int		i;
	int		line_width;
	int		tmp;

	i = 0;
	line_width = 0;
	tmp = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] != '.' && tetri[i] != '#' && tetri[i] != '\n')
			return (0);
		while (tetri[i] == '.' || tetri[i] == '#')
		{
			line_width++;
			i++;
		}
		if (tetri[i] == '\n')
		{
			if (line_width != 4 && tetri[i + 1] != '\0')
				return (0);
			line_width = 0;
			tmp++;
			i++;
		}
	}
	*grid_height = tmp;
	if (tmp != 5)
		return (0);
	return (1);
}

/* int		ft_check_tetri(char *tetri)
{
	int		i;

	i = 0;
	while (tetrie[i] != '#')
	{
		i++;

	}

	return (0);
} */

int		ft_check_tetri(char *tetri, int *grid_height)
{
	if (!(ft_check_char(tetri, grid_height)))
		return (0);
	//if (!(ft_check_tetri(tetri)))
	//	return (0);
	return (1);
}

t_list		*ft_read_file(int fd, t_list **list)
{
	int		ret;
	char	buff[21];
	t_list	*tmp;
	int grid_height;

	tmp = *list;
	tmp = ft_lstnew("\0", 1);
	grid_height = 0;
	while ((ret = read(fd, buff, 21)))
	{
		buff[ret] = '\0';
		if ((!ft_check_tetri(buff, &grid_height)))
		{
			if (ft_strlen(buff) != 20 && grid_height != 4)
			{
				ft_putendl_fd("Not a valid file", 2);
				return (NULL);
			}
		}
		tmp = ft_lstnew(buff, ft_strlen(buff));
		ft_lstadd(list, tmp);
	}
	return (tmp);
}
