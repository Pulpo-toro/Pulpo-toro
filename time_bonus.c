/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:26:28 by lbeata            #+#    #+#             */
/*   Updated: 2021/12/04 18:18:42 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil_bonus.h"

void	ft_time(t_data *data)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (data->time_ms_start == 0)
	{
		data->time_ms_start = (tv.tv_usec / 1000) + (tv.tv_sec * 1000);
	}
}

long long int	ft_time_1(t_data *data)
{
	struct timeval	tv;
	long long int	time;

	time = data->time_ms_start;
	gettimeofday(&tv, NULL);
	return ((tv.tv_usec / 1000) + (tv.tv_sec * 1000) - time);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000L + time.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	unsigned long	time;

	time = get_time() + ms;
	while ((get_time() < time))
		usleep(10);
}
