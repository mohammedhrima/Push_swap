/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_five_sorting2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:29:39 by mhrima            #+#    #+#             */
/*   Updated: 2023/02/15 21:15:30 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_number_index(t_stack*stack_b, int max_number)
{
	int	i;

	i = 0;
	while (i < stack_b->lenght && stack_b->array_of_nums[i].index != max_number)
		i++;
	return (i);
}

int	sort_more(t_stack *stack_a, t_stack*stack_b, int len)
{
	int	moves;
	int	max_number;
	int	before_max_range;
	int	i;

	init_stack_b(stack_a, stack_b, &moves, len);
	max_number = len - 1;
	before_max_range = 0;
	while (stack_a->lenght < len)
	{
		i = max_number_index(stack_b, max_number);
		before_max_range = 0;
		while (stack_b->array_of_nums[0].index != max_number)
		{
			if (stack_b->array_of_nums[0].index == max_number - 1)
				moves += push_to_stack_b(stack_a, stack_b, &before_max_range);
			else
				moves += move_stack_a(stack_b, i);
		}
		moves += push_to_stack_a(stack_b, stack_a, &max_number,
				before_max_range);
	}
	return (moves);
}
