/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:33:49 by flhember          #+#    #+#             */
/*   Updated: 2019/01/09 16:32:45 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_check_char(char *tetri)
{
	int		i;

	i = 0;
	while (tetri[i])
	{
		if (tetri[i] == '.' && tetri[i] == '#')
			i++;
		else if ((tetri[i] == '\n' && (tetri[i - 1] == '.')) ||
				(tetri[i - 1] == '#'))
			i++;
		else if (tetri[i] == '\n' && tetri[i - 1] == '\n')
			i++;
		else
			return (-1);
	}
	return (0);
}

int		ft_check_tetrie(char *tetrie)
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
}

t_list		*ft_read_file(int fd, t_list **list)
{
	int		ret;
	char	buf[21];
	t_list	*tmp;
	//t_list	*tetrie;

	tmp = *list;
	tmp = ft_lstnew("\0", 1);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if ((!ft_check_tetri(buf)))
		{
			ft_putendl_fd("Not a valid file", 2);
			return (NULL);
		}	
		tmp = ft_lstnew(buf, ft_strlen(buf));
		ft_lstadd(list, tmp);
	}
	return (tmp);
}
