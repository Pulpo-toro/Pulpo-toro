/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:37:10 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 14:37:11 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				j;

	if (n == 0)
		return (0);
	i = 0;
	if (ft_strlen(s1) < 5)
		return (-1);
	while (s1[i] != '.')
		i++;
	j = i;
	i = 0;
	while (s1[j] != '\0' && s2[i] != '\0' && s1[j] == s2[i] && i + 1 < n)
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[j] - (unsigned char)s2[i]);
}
