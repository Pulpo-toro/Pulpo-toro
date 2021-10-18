/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:44:07 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 15:44:09 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**array;

	if (argc > 2)
	{
		write (2, "Error\n", 7);
		return (-1);
	}
	if (ft_strncmp(argv[1], ".ber", 4) == 0)
		fd = open(argv[1], O_RDONLY);
	else
	{
		write (2, "Error\n", 7);
		return (-1);
	}
	if (ft_fd(fd) == -1)
		return (-1);
	array = read_of_ber(fd, 1);
	close (fd);
	if (array == NULL)
		return (-1);
	so_long(array);
	return (1);
}

int	ft_fd(int fd)
{
	if (fd == -1)
	{
		write (2, "Error\n", 7);
		return (-1);
	}
	return (1);
}
