/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:33:49 by flhember          #+#    #+#             */
/*   Updated: 2019/01/09 18:24:50 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_check_char(char *tetri)
{
	// mauvais retour si line_width < 3
	int		i;
	int		line_width;

	i = 0;
	line_width = 0;
	while (tetri[i] != '\0')
	{
		while (tetri[i] != '\n')
		{
			if (tetri[i] == '.' || tetri[i] == '#' || tetri[i] == '\n')
			{
				if (line_width > 3)
					return (-1);
				ft_putnbr(line_width);
				ft_putchar ('\n');
				line_width++;
				i++;
			}
			else
				return (-1);
		}
		line_width = 0;
		i++;
	}
	return (1);
}

/* int		ft_check_tetrie(char *tetrie)
{
	int		i;

	i = 0;
	while (tetrie[i] != '#')
	{
		i++;

	}

	return (0);
}

int		ft_check_tetri(char *tetrie)
{
	if (!(ft_check_char(tetrie)))
		return (-1);
	if (!(ft_check_tetrie(tetrie)))
		return (-1);
	return (0);
} */

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
		ft_putendl(tmp->content);
		ft_check_char(tmp->content);
		ft_putnbr(ft_check_char(tmp->content));
		ft_putchar('\n');
	//	if ((!ft_check_tetri(buf)))
	//	{
	//		ft_putendl_fd("Not a valid file", 2);
	//		return (NULL);
	//	}	
		tmp = ft_lstnew(buf, ft_strlen(buf));
		ft_lstadd(list, tmp);
	}
	return (tmp);
}
