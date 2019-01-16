/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:41:34 by flhember          #+#    #+#             */
/*   Updated: 2019/01/16 14:58:04 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_lstaddtetri(t_piece **alst, t_piece *new)
{
	new->next = *alst;
	*alst = new;
}

/*char	**ft_filling_piece(char *buf, char **piece)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i])
	{
		
		
	}
	return (piece);
}
*/
t_piece	*ft_lstnewtetri(char *content, size_t content_size, int nb)
{
	t_piece	*new;
	int		i;

	i = 0;
	new = NULL;
	if (!(new = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	new->content = ft_strsplit(content, '\n');
	new->content_size = content_size;
	new->alpha = 65 + nb;
	new->next = NULL;
	return (new);
}