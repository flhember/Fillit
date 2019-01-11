/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:03:11 by flhember          #+#    #+#             */
/*   Updated: 2019/01/11 10:22:57 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*tetrie;

	if (argc <= 1 || argc > 2)
	{
		ft_putendl_fd("fillit: error\nUsage: [1 source_file]", 2);
		return (1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putendl_fd("open() failed.", 2);
		return (1);
	}
	if (!(tetrie = ft_read_file(fd, &tetrie)))
	{
		close(fd);
		return (1);
	}
	//ft reso;
	close(fd);
	return (0);
}
