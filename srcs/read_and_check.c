/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:33:49 by flhember          #+#    #+#             */
/*   Updated: 2019/01/08 16:26:58 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*int		ft_check_char(char *tetri)
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

int		ft_check_tetri(char *tetri, int size)
{
	(void)size;
//	if ((ft_check_char(tetri)) < 1)
//		return (-1);	
	return (0);
}*/

t_list		*ft_read_file(int fd, t_list *tetrie)
{
	int		ret;
	char	buf[21];
	t_list	*tmp;

	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		//printf("buf :\n%s", buf);
		tmp = ft_lstnew(buf, ft_strlen(buf));
		ft_lstadd(&tetrie, tmp);
		tetrie = tetrie->next;
		//if ((ft_check_tetri(list->content, list->content_size)) < 0)
		//{
	//		ft_putendl_fd("Not a valid file", 2);
	//		return (NULL);
	//	}
	}
	return (tetrie);
}
