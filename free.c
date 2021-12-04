/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:07:14 by lbeata            #+#    #+#             */
/*   Updated: 2021/12/04 18:32:31 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free(t_data *data)
{
	free(data->ar);
	free(data->mutex);
	free(data);
}

int	free_ft(t_data *data)
{
	free(data);
	return (-1);
}

void	ft_free_ar_st(t_array_struc **ar_st)
{
	int	i;
	int	num_philo;

	num_philo = ar_st[0]->data->number_of_philosopher;
	i = 0;
	while (i < num_philo)
	{
		free(ar_st[i]);
		i++;
	}
	free(ar_st);
}
