/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:28:25 by ksalmi            #+#    #+#             */
/*   Updated: 2019/11/07 14:39:55 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*current;

	if (new)
	{
		if (!(*alst))
			*alst = new;
		else
		{
			current = *alst;
			while (current->next)
				current = current->next;
			current->next = new;
		}
	}
}
