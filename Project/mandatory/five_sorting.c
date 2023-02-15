/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:00:33 by mhrima            #+#    #+#             */
/*   Updated: 2023/02/15 20:38:33 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	split_stacks_for_five(t_stack *A, t_stack *B)
{
	int	i;
	int	moves;

	moves = 0;
	while (B->lenght < 2)
	{
		i = 0;
		while (A->array_of_nums[i].index >= 2 && A->array_of_nums[A->lenght - i
				- 1].index >= 2)
			i++;
		if (A->array_of_nums[i].index < 2)
		{
			while (A->array_of_nums[0].index >= 2)
				moves += rotate(A, 'a');
		}
		else if (A->array_of_nums[A->lenght - i - 1].index < 2)
		{
			while (A->array_of_nums[0].index >= 2)
				moves += reverse_rotate(A, 'a');
		}
		if (A->array_of_nums[0].index < 2)
			moves += push(A, B, 'b');
	}
	return (moves);
}

int	sort_five(t_stack *A, t_stack *B)
{
	int	i;
	int	moves;

	moves = split_stacks_for_five(A, B);
	i = 0;
	while (i < A->lenght)
	{
		A->array_of_nums[i].index -= 2;
		i++;
	}
	if (B->array_of_nums[0].index < B->array_of_nums[1].index)
		moves += swap(B, 'b');
	moves += sort_three(A, 'a');
	while (B->lenght > 0)
		moves += push(B, A, 'a');
	return (moves);
}
