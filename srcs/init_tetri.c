/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:41:34 by flhember          #+#    #+#             */
/*   Updated: 2019/01/17 19:09:57 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_lstaddtetri(t_piece **alst, t_piece *new)
{
	new->next = *alst;
	*alst = new;
}

int		get_tetri_width(char **tetri)
{
	int		i;
	int		j;
	int		xmax;
	int		width;

	i = 0;
	width = 0;
	xmax = 0;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j] != '\0')
		{
			if (tetri[i][j] == '#' && j > xmax)
				xmax = j;
			j++;
		}
		i++;
	}
	width = xmax + 1;
	//printf("width = %d\n", width);
	return (width);
}

int		get_tetri_height(char **tetri)
{
	int		i;
	int		j;
	int		k;
	int		height;

	i = 0;
	height = 0;
	while (tetri[i])
	{
		j = 0;
		k = 0;
		while (tetri[i][j] != '\0')
		{
			if (tetri[i][j] == '#')
				k = 1;
			j++;
		}
		if (k == 1)
			height++;
		i++;
	}
	//printf("height = %d\n", height);
	return (height);
}

t_piece	*ft_lstnewtetri(char *content, size_t content_size, int nb)
{
	t_piece	*new;
	int		i;

	i = 0;
	new = NULL;
	if (!(new = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	printf("i");
	new->y = 0;
	printf("u");
	new->x = 0;
	printf("y");
	new->content = reset(ft_strsplit(content, '\n'));
	printf("t");
	new->content_size = content_size;
	printf("r");
	new->alpha = 65 + nb;
	printf("q");
	new->next = NULL;
	printf("w");
	new->height = get_tetri_height(new->content);
	printf("e");
	new->width = get_tetri_width(new->content);
	return (new);
}
