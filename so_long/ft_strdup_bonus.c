/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:36:24 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 14:36:24 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*array;
	size_t	j;
	size_t	i;

	i = 0;
	j = ft_strlen(s1);
	array = (char *)malloc((j + 1) * sizeof(char));
	if (!array)
		return (NULL);
	while (i <= j)
	{
		array[i] = s1[i];
		i++;
	}
	return (array);
}
