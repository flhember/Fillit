/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:41:34 by flhember          #+#    #+#             */
/*   Updated: 2019/01/18 15:08:46 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_lstrev(t_piece **lst)
{
	t_piece *prev  = NULL;
	t_piece *current = *lst;
	t_piece *next;
	while (current != NULL)
	{
		next  = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*lst = prev;
}

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
	new->y = 0;
	new->x = 0;
	new->content = reset(ft_strsplit(content, '\n'));
	new->content_size = content_size;
	new->alpha = 65 + nb;
	new->next = NULL;
	new->height = get_tetri_height(new->content);
	new->width = get_tetri_width(new->content);
	return (new);
}
