/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:18:21 by lbeata            #+#    #+#             */
/*   Updated: 2021/12/04 18:52:31 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil_bonus.h"

void	cast_printf(t_data *data, char *str, int index)
{
	long long int	time;

	if (data->number_eat == data->num_each_eat)
		exit (1);
	sem_wait(data->deth);
	time = ft_time_1(data);
	printf("%lli %i %s", time, index + 1, str);
	sem_post(data->deth);
}

void	routine_1(t_data *data)
{
	int			index;
	pthread_t	live;

	if (pthread_create(&live, NULL, &check_life, data) != 0)
		exit(1);
	index = data->id;
	while (data->take_of != -1)
	{
		sem_wait(data->forks);
		cast_printf(data, "has taken a fork\n", index);
		cast_printf(data, "has taken a fork\n", index);
		cast_printf(data, "is eating\n", index);
		ft_usleep(data->time_to_eat);
		data->number_eat += 1;
		data->time_to_die_cont = ft_time_1(data) + data->time_to_die;
		sem_post(data->forks);
		cast_printf(data, "is sleeping\n", index);
		ft_usleep(data->time_to_sleep);
		cast_printf(data, "is thinking\n", index);
		data->status = 1;
	}
}
