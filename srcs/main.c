/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:03:11 by flhember          #+#    #+#             */
/*   Updated: 2018/12/14 21:30:30 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_check_file_nbline(char *file)
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	while (file[i])
	{
		k++;
		i++;
		if (k == 20)
		{
			if (file[i] != '\n' && file[i] != '\0')
				return (-1);
			k = 0;
			i++;
		}
	}
	if (k != 0)
		return (-1);
	return (0);
}

/*int		ft_check_file_charline(char *file)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (file[i])
	{

	}
	return (0);
}*/

int		ft_check_file(char *file)
{
	if ((ft_check_file_nbline(file)) < 0 )
		return (1);
	//if ((ft_check_file_charline(file)) < 0 )
	//	return (1);
	return (0);
}

int		ft_read_files(int fd)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*buf_final;

	buf_final = ft_strdup("");
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (ret == -1)
		{
			ft_putendl_fd("read() failed.", 2);
			return (1);
		}
		buf[ret] = '\0';
		buf_final = ft_strjoinfree(buf_final, buf, 1);
	}
	if ((ft_check_file(buf_final)) == 1)
	{
		ft_putendl_fd("not a valide file", 2);
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;

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
	if ((ft_read_files(fd)) == 1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
