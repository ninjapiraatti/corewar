/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:25:51 by ksalmi            #+#    #+#             */
/*   Updated: 2019/11/20 17:12:51 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ptr;
	t_list *new;

	if (!(lst))
		return (NULL);
	if (!(ptr = f(lst)))
		return (NULL);
	new = ptr;
	while (lst->next)
	{
		lst = lst->next;
		if (!(ptr->next = f(lst)))
			return (NULL);
		ptr = ptr->next;
	}
	return (new);
}
