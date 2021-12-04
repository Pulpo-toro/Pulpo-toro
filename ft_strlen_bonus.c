/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:36:52 by lbeata            #+#    #+#             */
/*   Updated: 2021/12/04 18:19:19 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil_bonus.h"

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
