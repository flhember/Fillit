/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:03:11 by flhember          #+#    #+#             */
/*   Updated: 2019/01/16 14:45:07 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	t_piece		*tetri;

	if (argc <= 1 || argc > 2)
	{
		ft_putendl_fd("fillit: error\nUsage: [1 source_file]", 2);
		return (0);
	}
	if (!(tetri = get_tetri(argv[1])))
	{
		ft_putendl_fd("error\n", 2);
		return (0);
	}
	if (!(tetri = ft_read_file(fd, &tetri)))
	{
		close(fd);
		return (1);
	}
	ft_resolution(&tetri);
	close(fd);
	return (0);
}
