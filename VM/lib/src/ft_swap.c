/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:15:01 by ksalmi            #+#    #+#             */
/*   Updated: 2019/11/04 17:23:38 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b)
{
	char *aa;
	char *bb;
	char temp;

	aa = (char *)a;
	bb = (char *)b;
	temp = *aa;
	*aa = *bb;
	*bb = temp;
}
