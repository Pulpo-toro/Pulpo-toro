/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:35:47 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 14:35:48 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_lstadd_back(t_list **lst, t_list *new_1)
{
	if (!lst || !new_1)
	{
		return ;
	}
	if (!(*lst))
	{
		*lst = new_1;
		return ;
	}
	ft_lstlast(*lst)->next = new_1;
}
