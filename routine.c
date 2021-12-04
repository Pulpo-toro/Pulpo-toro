/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:06:54 by lbeata            #+#    #+#             */
/*   Updated: 2021/12/04 19:03:16 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	cast_printf(t_array_struc *array_struc, char *str, int index)
{
	long long int	time;

	if (array_struc->data->take_of != -1)
	{
		pthread_mutex_lock(&array_struc->data->to_write);
		time = ft_time_1(array_struc);
		printf("%lli %i %s", time, index + 1, str);
		pthread_mutex_unlock(&array_struc->data->to_write);
	}
}

void	routine_1(t_array_struc *ar_st)
{
	int	index;
	int	index_next;

	index = ar_st->id;
	index_next = (index + 1) % ar_st->data->number_of_philosopher;
	pthread_mutex_lock(&ar_st->data->mutex[index]);
	cast_printf(ar_st, "has taken a fork\n", index);
	pthread_mutex_lock(&ar_st->data->mutex[index_next]);
	cast_printf(ar_st, "has taken a fork\n", index);
	cast_printf(ar_st, "is eating\n", index);
	ar_st->number_eat += 1;
	ar_st->time_to_die = ft_time_1(ar_st) + ar_st->data->time_to_die;
	ft_usleep(ar_st->data->time_to_eat);
	pthread_mutex_unlock(&ar_st->data->mutex[index_next]);
	pthread_mutex_unlock(&ar_st->data->mutex[index]);
	cast_printf(ar_st, "is sleeping\n", index);
	ft_usleep(ar_st->data->time_to_sleep);
	cast_printf(ar_st, "is thinking\n", index);
	ar_st->data->status = 1;
}

void	*routine(void *m)
{
	t_array_struc	*array_struc;
	int				index;

	array_struc = (t_array_struc *)m;
	index = array_struc->id;
	if (array_struc->data->status == 0)
	{
		if (index % 2 == 1)
			ft_usleep(array_struc->data->time_to_eat / 2);
	}
	while (array_struc->data->take_of != -1)
		routine_1(array_struc);
	return (m);
}
