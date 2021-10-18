/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:36:39 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 14:36:53 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	runner;

	if (!str)
		return (0);
	runner = 0;
	while (str[runner] != '\0')
		runner++;
	return (runner);
}
