/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:34:35 by lbeata            #+#    #+#             */
/*   Updated: 2021/12/04 18:04:24 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	if (check(argc, argv) == -1)
		return (-1);
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (-1);
	data->time_ms_start = 0;
	if (write_information_in_data(data, argv, argc) == -1)
		return (free_ft(data));
	if (go_to_thead_0(data) == -1)
		return (free_ft(data));
	i = 0;
	while (i < data->number_of_philosopher)
	{
		pthread_mutex_destroy(&data->mutex[i]);
		pthread_detach(data->ar[i]);
		i++;
	}
	pthread_mutex_destroy(&data->to_write);
	ft_free(data);
	return (0);
}

int	go_to_thead_0(t_data *data)
{
	int	i;

	data->ar = malloc(sizeof(pthread_t) * data->number_of_philosopher);
	if (data->ar == NULL)
		return (-1);
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->number_of_philosopher);
	if (data->mutex == NULL)
		return (-1);
	i = 0;
	while (i < data->number_of_philosopher)
	{
		pthread_mutex_init(&data->mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->to_write, NULL);
	go_to_thead(data, data->ar);
	return (0);
}

int	check_life_1(t_array_struc **ar_st, int number_philo, int j)
{
	int				i;
	long long int	time;

	i = 0;
	while (i < number_philo)
	{
		time = ft_time_1(ar_st[i]);
		if ((ar_st[i]->time_to_die) - time <= 0)
		{
			if (ar_st[i]->data->take_of != -1)
			{
				pthread_mutex_lock(&ar_st[i]->data->to_write);
				ar_st[i]->data->take_of = -1;
				printf("%lli %i died\n", time, i + 1);
				return (-1);
			}
		}
		if (ar_st[0]->data->num_each_eat >= 0
			&& ar_st[i]->number_eat >= ar_st[0]->data->num_each_eat)
			j++;
		i++;
	}
	return (j);
}

int	check_life(t_array_struc **ar_st)
{
	int				i;
	int				number_philo;
	int				j;

	number_philo = ar_st[0]->data->number_of_philosopher;
	j = 0;
	while (ar_st[0]->data->take_of != -1)
	{
		j = check_life_1(ar_st, number_philo, j);
		if (j == ar_st[0]->data->number_of_philosopher)
		{
			pthread_mutex_lock(&ar_st[i]->data->to_write);
			ar_st[0]->data->take_of = -1;
		}
		j = 0;
		i = 0;
	}
	return (0);
}

int	go_to_thead(t_data *data, pthread_t *ar)
{
	t_array_struc	**ar_st;
	int				i;

	ar_st = creat_array_struc(data);
	if (ar_st == NULL)
		return (-1);
	i = 0;
	ft_time(data);
	while (i < data->number_of_philosopher)
	{
		ar_st[i]->id = i;
		if (pthread_create(ar + i, NULL, &routine, ar_st[i]) != 0)
			return (-1);
		i++;
	}
	check_life(ar_st);
	ft_free_ar_st(ar_st);
	return (0);
}
