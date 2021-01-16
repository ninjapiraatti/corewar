/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:22:18 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/03/13 14:43:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "Libft\libft.h"

t_lst	*set_values(t_lst *arr)
{
	arr->len = 0;
	arr->i = 0;
	arr->arguments = "cspdoiuxXf%";
	arr->modifiers = "lhL";
	arr->flags = "-+ 0#";
	return (arr);
}
