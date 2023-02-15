/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:35:47 by mhrima            #+#    #+#             */
/*   Updated: 2023/02/15 20:39:17 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_three(t_stack *X, char c)
{
	int	moves;
	int	n;

	moves = 0;
	if (X->array_of_nums[0].index == X->array_of_nums[1].index + 1)
		moves += swap(X, c);
	if (X->lenght > 2)
	{
		n = X->array_of_nums[0].index + 2 * X->array_of_nums[1].index
			+ X->array_of_nums[2].index;
		if (n == 3)
			moves += rotate(X, c);
		if (n == 5)
			moves += reverse_rotate(X, c);
		if (X->array_of_nums[0].index == X->array_of_nums[1].index + 1)
			moves += swap(X, c);
	}
	return (moves);
}
