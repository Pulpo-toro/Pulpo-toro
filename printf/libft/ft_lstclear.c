#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*num;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		if ((*lst)->content)
		{
			del((*lst)->content);
		}
		num = *lst;
		*lst = num->next;
		free(num);
	}
}
