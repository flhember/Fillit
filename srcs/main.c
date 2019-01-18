/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:03:11 by flhember          #+#    #+#             */
/*   Updated: 2019/01/17 19:01:54 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_piece	*tetri;

	if (argc <= 1 || argc > 2)
	{
		ft_putendl_fd("Usage: [1 source_file]", 2);
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (-1);
	if (!(tetri = ft_read_file(fd, &tetri)))
	{
		close(fd);
		return (-1);
	}	
	printf("ja");
	ft_resolution(tetri);
	close(fd);
	return (0);
}
