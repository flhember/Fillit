/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:33:49 by flhember          #+#    #+#             */
/*   Updated: 2019/01/14 15:04:50 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
 ** Vérifie le format du fichier d'entrée.
 ** Return 0 s'il y a autre chose que des "." || "#" || trop ou trop peu \n
 ** Return 1 si le format du fichier est valide
 */

int			ft_check_char(char *tetri, int *grid_height)
{
	int		i;
	int		line_width;
	int		tmp;

	i = 0;
	line_width = 0;
	tmp = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] != '.' && tetri[i] != '#' && tetri[i] != '\n')
			return (0);
		while (tetri[i++] == '.' || tetri[i++] == '#')
			line_width++;
		if (tetri[i++] == '\n')
		{
			if (line_width != 4 && tetri[i + 1] != '\0')
				return (0);
			line_width = 0;
			tmp++;
		}
		i++;
	}
	*grid_height = tmp;
	if (tmp != 5)
		return (0);
	return (1);
}

/*
 ** Check que le nombre de tétri est bien compris entre
 ** 1 et 26
 */ 

int			ft_check_tetri(char *tetri, int *grid_height)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;	
	if (!(ft_check_char(tetri, grid_height)))
	{
		printf("return = %d\n", ft_check_char(tetri, grid_height));
		return (0);
	}
	while (tetri[i])
	{
		if (tetri[i] == '#')
			nb++;
		i++;
	}
	if (nb != 4)
		return (0);
	return (1);
}

/*
 ** Check la validité des tetri
 ** Compte le nombre que le nombre de connexion est de 6 min
 */

int			ft_check_tetri_valid(char *tetri, int *grid_height)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(ft_check_tetri(tetri, grid_height)))
		return (0);
	while (tetri[i])
	{
		if (tetri[i] == '#')
		{
			if (tetri[i - 1] == '#')
				j++;
			if (tetri[i - 5] == '#')
				j++;
			if (tetri[i + 1] == '#')
				j++;
			if (tetri[i + 5] == '#')
				j++;
		}
		i++;
	}
	if (j < 6)
		return (0);
	return (1);
}

/*
 ** Ajoute un nouveau maillon a la liste si le tetri est valide
 */

t_piece		*ft_read_file(int fd, t_piece **list, int *grid_height)
{
	int	ret;
	char	buff[TETRI_SIZE];
	t_piece	*tmp;
	int	alpha;

	alpha = 0;
	tmp = *list;
	while ((ret = read(fd, buff, 21)))
	{
		buff[ret] = '\0';
		if ((!ft_check_tetri_valid(buff, grid_height)))
		{
			ft_putendl_fd("Not a valid file", 2);
			return (NULL);
		}
		tmp = ft_lstnewtetri(buff, ft_strlen(buff), alpha);
		ft_lstaddtetri(list, tmp);
		alpha++;
	}
	/*
	   while ((ret = read(fd, buff, 21)))
	   {
	   buff[ret] = '\0';
	   if ((!ft_check_tetri_valid(buff, grid_height)))
	   {
	   ft_putendl_fd("Not a valid file", 2);
	   return (NULL);
	   }
	   }
	   tmp = ft_lstnewtetri(buff, ft_strlen(buff), alpha);
	   ft_lstaddtetri(list, tmp);
	   alpha++;
	   }
	*/
	if (tmp->content_size != (TETRI_SIZE - 1))
	{
		ft_putendl_fd("Not a valid file", 2);
		return (NULL);
	}
return (tmp);
}

/*
 ** Ouvre le fichier et renvoie une liste si le fichier est valide
 ** puis le ferme
 */

t_piece		*get_tetri(const char *file)
{
	int			fd;
	t_piece		*tetri;
	int			grid_height;

	grid_height = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl_fd("open() failed.", 2);
		return (NULL);
	}
	if (!(tetri = ft_read_file(fd, &tetri, &grid_height)))
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (tetri);
}
