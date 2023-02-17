/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:01:14 by mhrima            #+#    #+#             */
/*   Updated: 2023/02/15 20:41:59 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	my_exit(char *msg)
{
	ft_printf("%s\n", msg);
	exit(0);
}

void	swap_array(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	sort_array(int *array_of_numbers, int *array_of_indexes, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < len)
	{
		i = j + 1;
		while (i < len)
		{
			if (array_of_numbers[j] > array_of_numbers[i])
			{
				swap_array(array_of_numbers + j, array_of_numbers + i);
				swap_array(array_of_indexes + j, array_of_indexes + i);
			}
			i++;
		}
		j++;
	}
}

t_stack	*new_stack(int virtual_len, int len)
{
	t_stack	*list;

	list = my_malloc(sizeof(t_stack));
	list->lenght = virtual_len;
	list->array_of_nums = ft_calloc(len, sizeof(t_num));
	return (list);
}

t_stack	*init_stacks(char **array, int *len)
{
	t_stack	*stack_a;
	int		i;
	int		*array_of_numbers;
	int		*array_of_indexes;

	*len = ft_arrlen(array);
	array_of_numbers = convert_to_integers(*len, array);
	check_repeated_numbers(array_of_numbers, *len);
	array_of_indexes = array_of_integers(*len);
	stack_a = new_stack(*len, *len);
	i = 0;
	while (i < *len)
	{
		stack_a->array_of_nums[i].value = array_of_numbers[i];
		i++;
	}
	sort_array(array_of_numbers, array_of_indexes, *len);
	i = 0;
	while (i < *len)
	{
		stack_a->array_of_nums[array_of_indexes[i]].index = i;
		i++;
	}
	return (stack_a);
}
