/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:56:01 by flhember          #+#    #+#             */
/*   Updated: 2019/01/11 15:40:27 by flhember         ###   ########.fr       */
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
	void			*content;
	size_t			content_size;
	int				alpha;
	int				x;
	int				y;
	struct	s_piece	*next;

}					t_piece;

t_piece				*ft_read_file(int fd, t_piece **list);
void				ft_lstaddtetri(t_piece **alst, t_piece *new);
t_piece				*ft_lstnewtetri(void const *content, size_t content_size, int nb);
void				search_replace(t_piece **tetri);
void				ft_print_map(t_piece *list);

#endif
