/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:32:51 by mhrima            #+#    #+#             */
/*   Updated: 2023/02/15 20:42:08 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	rotate(t_stack *list, char c)
{
	t_num	tmp;

	if (!list)
		my_exit("KO");
	else if (list && list->lenght > 1)
	{
		tmp = list->array_of_nums[0];
		ft_memmove(list->array_of_nums, list->array_of_nums + 1, (list->lenght
				- 1) * sizeof(t_num));
		list->array_of_nums[list->lenght - 1] = tmp;
		if (c)
			ft_printf("r%c\n", c);
		return (1);
	}
	return (0);
}

int	reverse_rotate(t_stack*list, char c)
{
	t_num	tmp;

	if (!list)
		my_exit("KO");
	else if (list && list->lenght > 1)
	{
		tmp = list->array_of_nums[list->lenght - 1];
		ft_memmove(list->array_of_nums + 1, list->array_of_nums, (list->lenght
				- 1) * sizeof(t_num));
		list->array_of_nums[0] = tmp;
		if (c)
			ft_printf("rr%c\n", c);
		return (1);
	}
	return (0);
}

int	push(t_stack *src, t_stack*dest, char c)
{
	t_num	tmp;

	if (src->lenght)
	{
		tmp = src->array_of_nums[0];
		rotate(src, 0);
		src->lenght--;
		dest->lenght++;
		reverse_rotate(dest, 0);
		dest->array_of_nums[0] = tmp;
		if (c)
			ft_printf("p%c\n", c);
		return (1);
	}
	else
		my_exit("KO");
	return (0);
}

int	swap(t_stack*list, char c)
{
	t_num	tmp;

	if (list->lenght)
	{
		tmp = list->array_of_nums[0];
		list->array_of_nums[0] = list->array_of_nums[1];
		list->array_of_nums[1] = tmp;
		if (c)
			ft_printf("s%c\n", c);
		return (1);
	}
	else
		my_exit("KO");
	return (0);
}
