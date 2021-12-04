/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:34:35 by lbeata            #+#    #+#             */
/*   Updated: 2021/12/04 18:52:16 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check(argc, argv) == -1)
		return (-1);
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (-1);
	data->time_ms_start = 0;
	if (write_information_in_data(data, argv, argc) == -1)
	{
		ft_free(data);
		return (-1);
	}
	go_to_thead_0(data);
	sem_close(data->forks);
	sem_close(data->deth);
	sem_unlink("forks");
	sem_unlink("deth");
	ft_free(data);
	return (0);
}

int	go_to_thead_0(t_data *data)
{
	ft_time(data);
	sem_unlink("forks");
	sem_unlink("deth");
	data->forks = sem_open("forks", O_CREAT, S_IRWXU, (data->num_phi / 2));
	data->deth = sem_open("deth", O_CREAT, S_IRWXU, 1);
	go_to_thead(data);
	return (0);
}

int	go_to_thead(t_data *data)
{
	int			i;
	int			variable;

	data->pid = malloc(sizeof(int) * data->num_phi);
	if (data->pid == NULL)
		return (-1);
	i = 0;
	while (i < data->num_phi)
	{
		data->pid[i] = fork();
		if (data->pid[i] == 0)
		{
			data->id = i;
			routine_1(data);
		}
		i++;
	}
	waitpid(-1, &variable, 0);
	i = 0;
	if (variable == 0)
	{
		while (i < data->num_phi)
			kill(data->pid[i++], SIGTERM);
	}
	return (free_ft(data));
}

void	*check_life(void *m)
{
	int				number_philo;
	t_data			*data;
	long long int	time;

	data = (t_data *)m;
	number_philo = data->num_phi;
	while (data->take_of != -1)
	{
		time = ft_time_1(data);
		if (data->time_to_die_cont - time <= 0)
		{
			sem_wait(data->deth);
			data->take_of = -1;
			printf("%lli %i died\n", time, data->id + 1);
			exit(0);
		}
	}
	return (0);
}
