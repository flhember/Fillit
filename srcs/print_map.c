/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:26:19 by flhember          #+#    #+#             */
/*   Updated: 2019/01/11 12:01:25 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	search_replace(t_piece **tetri)
{
	int		i;
	t_piece	*tmp;

	tmp = *tetri;
	i = 0;
	while (tmp)
	{
		while (((char*)(tmp)->content)[i])
		{
			if (((char*)(tmp)->content)[i] == '#')
				((char*)(tmp)->content)[i] = tmp->alpha;
			i++;
		}
		tmp = tmp->next;
	}
}

