/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:41:34 by flhember          #+#    #+#             */
/*   Updated: 2019/01/16 11:16:38 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_lstaddtetri(t_piece **alst, t_piece *new)
{
	new->next = *alst;
	*alst = new;
}

/*t_piece	*ft_filling_piece(char *buf, t_piece **new)
{
	t_piece *tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = *new;


}*/


t_piece	*ft_lstnewtetri(char *content, size_t content_size, int nb)
{
	t_piece	*new;
	int		i;

	i = 0;
	new = NULL;
	if (!(new = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		new->alpha = 0;
	}
	else
	{
		if (!(new->content = (char**)malloc(sizeof(char*) * 4)))
			return (NULL);
		while (i < 4)
		{
			if (!(new->content[i] = (char*)malloc(sizeof(char) * 4)))
				return (NULL);
				i++;
		}
		new->content[i] = NULL;
		new->content_size = content_size;
		new->alpha = 65 + nb;
	}
	new->next = NULL;
	return (new);
}
