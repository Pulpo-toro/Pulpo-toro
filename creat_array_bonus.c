/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_array_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:30:15 by lbeata            #+#    #+#             */
/*   Updated: 2021/12/04 18:19:51 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil_bonus.h"

int	write_information_in_data_1(t_data *data, char **argv)
{
	data->time_ms_start = 0;
	data->status = 0;
	data->take_of = 0;
	data->time_ms = 0;
	data->id = 0;
	data->number_eat = 0;
	data->num_phi = ft_atoi(argv[1]);
	if (data->num_phi == -1)
		return (-1);
	if (data->num_phi == 0)
	{
		write(2, "Error: Incorrect symbol\n", 24);
		return (-1);
	}
	data->time_to_die = ft_atoi(argv[2]);
	if (data->time_to_die == -1)
		return (-1);
	data->time_to_eat = ft_atoi(argv[3]);
	if (data->time_to_eat == -1)
		return (-1);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->time_to_sleep == -1)
		return (-1);
	return (0);
}

int	write_information_in_data(t_data *data, char **argv, int argc)
{
	if (write_information_in_data_1(data, argv) == -1)
		return (-1);
	data->time_to_die_cont = data->time_to_die;
	if (data->num_phi == 1)
	{
		printf("%i %i has taken a fork\n", 0, 1);
		printf("%i %i died\n", data->time_to_die, 1);
		return (-1);
	}
	if (argc == 6)
	{
		data->num_each_eat = ft_atoi(argv[5]);
		if (data->num_each_eat == -1)
			return (-1);
	}
	else
		data->num_each_eat = -1;
	return (1);
}
