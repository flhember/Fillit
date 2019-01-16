/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 09:49:13 by flhember          #+#    #+#             */
/*   Updated: 2019/01/16 17:45:32 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../Libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h> // a retirer !!!!!!!!!!!!!!!!!

typedef struct		s_piece
{
	char			**content;
	size_t			content_size;
	int				alpha;
	int				x;
	int				y;
	struct	s_piece	*next;

}					t_piece;

typedef	struct		s_map
{
	char			**map;
	int				xmax;
	int				ymax;
}					t_map;

t_piece				*ft_read_file(int fd, t_piece **list);
void				ft_lstaddtetri(t_piece **alst, t_piece *new);
t_piece				*ft_lstnewtetri(char *content, size_t content_size, int nb);
int					ft_resolution(t_piece **tetri);
int					ft_sqrt_map(int	nb);
t_map				*ft_set_map(int xmax);
void				ft_print_map(t_map *map);
char				**reset(char **content);


#endif
