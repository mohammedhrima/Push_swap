/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:35:07 by mhrima            #+#    #+#             */
/*   Updated: 2023/02/15 21:14:19 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int		len;
	int		moves;
	t_stack	*stack_a;
	t_stack	*stack_b;

	moves = 0;
	stack_a = init_stacks(read_arguments(argc, argv), &len);
	stack_b = new_stack(0, len);
	if (is_sorted(stack_a))
		exit(0);
	if (len <= 3 && len > 1)
		moves += sort_three(stack_a, 'a');
	else if (len <= 5)
		moves += sort_five(stack_a, stack_b);
	else if (len > 5)
		moves += sort_more(stack_a, stack_b, len);
}
