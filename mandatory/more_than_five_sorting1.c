/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_five_sorting1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:01:43 by mhrima            #+#    #+#             */
/*   Updated: 2023/02/15 21:14:50 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	set_precision(int len)
{
	int	precision;

	if (len < 250)
		precision = 4;
	if (len >= 250)
		precision = 6;
	if (len >= 500)
		precision = 9;
	return (precision);
}

void	init_stack_b(t_stack *stack_a, t_stack *stack_b, int *moves, int len)
{
	float	min;
	float	max;
	int		precision;

	precision = set_precision(len);
	min = 0.0;
	max = len / precision;
	*moves = 0.0;
	while (stack_b->lenght < len)
	{
		while (stack_b->lenght < (int)(max) && stack_a->lenght)
		{
			if (stack_a->array_of_nums[0].index >= min
				&& stack_a->array_of_nums[0].index < max)
			{
				(*moves) += push(stack_a, stack_b, 'b');
				if (stack_b->array_of_nums[0].index < (max - min) / 2 + min)
					(*moves) += rotate(stack_b, 'b');
			}
			else
				(*moves) += rotate(stack_a, 'a');
		}
		min += (len / precision);
		max += (len / precision);
	}
}

int	push_to_stack_a(t_stack*stack_b, t_stack *stack_a, int *maximum_len,
		int before_max_range)
{
	int	moves;

	moves = 0;
	if (stack_b->array_of_nums[0].index == *maximum_len)
	{
		moves += push(stack_b, stack_a, 'b');
		(*maximum_len)--;
		if (before_max_range)
		{
			moves += swap(stack_a, 'a');
			(*maximum_len)--;
		}
	}
	return (moves);
}

int	push_to_stack_b(t_stack *stack_a, t_stack *stack_b, int *before_max_range)
{
	int	moves;

	moves = 0;
	moves += push(stack_b, stack_a, 'a');
	*before_max_range = 1;
	return (moves);
}

int	move_stack_a(t_stack *stack_b, int i)
{
	int	moves;

	moves = 0;
	if (i < stack_b->lenght / 2)
		moves += rotate(stack_b, 'b');
	else
		moves += reverse_rotate(stack_b, 'b');
	return (moves);
}
