/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:34:50 by ksalmi            #+#    #+#             */
/*   Updated: 2019/11/01 21:34:39 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*link;

	if (*alst)
	{
		link = *alst;
		while (link)
		{
			del(link->content, link->content_size);
			link = link->next;
		}
		free(*alst);
		*alst = NULL;
	}
}
