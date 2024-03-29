/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:21:27 by pkuussaa          #+#    #+#             */
/*   Updated: 2021/03/18 05:55:14 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_2d_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*count_label_size(t_statement *state, int arg_i, int label_i, int check)
{
	int		start;
	int		end;
	int		count;
	int		result;
	char	*res;

	start = arg_i < label_i ? arg_i : label_i;
	end = arg_i > label_i ? arg_i : label_i;
	count = 0;
	result = 0;
	while (start > count)
	{
		state = state->next;
		count++;
	}
	while (end > count)
	{
		result = arg_i > label_i ? result - state->size : result + state->size;
		count++;
		state = state->next;
	}
	res = ft_itoa(result);
	if (check == 0)
		return (free_strjoin(ft_strdup("%"), res));
	return (res);
}

char	*count_label_index(char *str, t_statement *tmp, int count, int index)
{
	int			i[2];
	char		**arr;
	t_statement	*state;

	state = tmp;
	arr = ft_strsplit(str, ':');
	ft_strdel(&str);
	str = arr[0][0] == '%' ? ft_strdup(arr[1]) : ft_strdup(arr[0]);
	i[1] = arr[0][0] == '%' ? 0 : 1;
	while (state)
	{
		i[0] = -1;
		if (state->label)
			while (state->label[++i[0]])
				if (ft_strcmp(str, state->label[i[0]]) == 0)
				{
					free_2d_array(arr);
					ft_strdel(&str);
					return (count_label_size(tmp, index, count, i[1]));
				}
		count++;
		state = state->next;
	}
	error_management("error while converting labels, no such label");
	return (NULL);
}

void	convert_labels(t_statement *tmp, int i, int count)
{
	t_statement	*state;
	char		*temp;

	state = tmp;
	while (state)
	{
		i = 0;
		if (state->args)
		{
			while (state->args[i] != NULL)
			{
				if (ft_strchr(state->args[i], ':'))
				{
					temp = count_label_index(state->args[i], tmp, 0, count);
					state->args[i] = ft_strdup(temp);
					ft_strdel(&temp);
				}
				i++;
			}
		}
		count++;
		state = state->next;
	}
}
