/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:56:01 by flhember          #+#    #+#             */
/*   Updated: 2019/01/14 14:06:26 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../Libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h> // a retirer !!!!!!!!!!!!!!!!!

# define TETRI_SIZE 21

typedef struct		s_piece
{
	char			*content;
	size_t			content_size;
	int				alpha;
	int				x;
	int				y;
	struct	s_piece	*next;
}					t_piece;

void				ft_lstaddtetri(t_piece **alst, t_piece *new);
t_piece				*ft_lstnewtetri(void const *content, size_t content_size, int nb);
void				search_replace(t_piece **tetri);
void				ft_print_map(t_piece *list);
t_piece				*get_tetri(const char *file);
#endif
