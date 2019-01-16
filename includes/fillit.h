/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2018/12/11 15:56:01 by flhember          #+#    #+#             */
/*   Updated: 2019/01/14 14:06:26 by brpinto          ###   ########.fr       */
=======
/*   Created: 2019/01/16 09:49:13 by flhember          #+#    #+#             */
/*   Updated: 2019/01/16 11:17:55 by flhember         ###   ########.fr       */
>>>>>>> Florian
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
<<<<<<< HEAD
	char			*content;
=======
	char			**content;
>>>>>>> Florian
	size_t			content_size;
	int				alpha;
	int				x;
	int				y;
	struct	s_piece	*next;
}					t_piece;

<<<<<<< HEAD
void				ft_lstaddtetri(t_piece **alst, t_piece *new);
t_piece				*ft_lstnewtetri(void const *content, size_t content_size, int nb);
void				search_replace(t_piece **tetri);
void				ft_print_map(t_piece *list);
t_piece				*get_tetri(const char *file);
=======
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


>>>>>>> Florian
#endif
