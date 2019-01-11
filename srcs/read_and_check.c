/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:33:49 by flhember          #+#    #+#             */
/*   Updated: 2019/01/11 09:46:01 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_check_tetri(char *tetri)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (tetri[i])
	{
		if (tetri[i] == '#')
			nb++;
		i++;
	}
	if (nb != 4)
		return (0);
	return (1);
}

int		ft_check_tetri_valid(char *tetri)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (tetri[i])
	{
		if (tetri[i] == '#')
		{
			if (tetri[i - 1] == '#')
				j++;
			if (tetri[i - 5] == '#')
				j++;
			if (tetri[i + 1] == '#')
				j++;
			if (tetri[i + 5] == '#')
				j++;
		}
		i++;
	}
	if (j < 6)
		return (0);
	return (1);
}

int		ft_check(char *tetri)
{
	//if (!(ft_check_char(tetri)))
	//	return (-1);
	if (!(ft_check_tetri(tetri)))
		return (0);
	if (!(ft_check_tetri_valid(tetri)))
		return (0);
	return (1);
}

t_list		*ft_read_file(int fd, t_list **list)
{
	int		ret;
	char	buf[21];
	t_list	*tmp;

	tmp = *list;
	tmp = ft_lstnew("\0", 1);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if ((!ft_check(buf)))
		{
			ft_putendl_fd("Not a valid file", 2);
			return (NULL);
		}
		tmp = ft_lstnew(buf, ft_strlen(buf));
		ft_lstadd(list, tmp);
	}
	return (tmp);
}
