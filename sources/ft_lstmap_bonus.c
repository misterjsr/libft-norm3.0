/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:23:09 by jeserran          #+#    #+#             */
/*   Updated: 2021/05/13 00:30:53 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*tmp;
	t_list		*mapped;

	(void)(*del);
	if (f == NULL || lst == NULL)
		return (NULL);
	tmp = ft_lstnew(f(lst->content));
	if (tmp == NULL)
		return (NULL);
	mapped = tmp;
	while (lst->next != NULL)
	{
		lst = lst->next;
		tmp->next = ft_lstnew(f(lst->content));
		if (tmp->next == NULL)
			return (NULL);
		tmp = tmp->next;
	}
	return (mapped);
}
