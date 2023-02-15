/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:52:39 by mhrima            #+#    #+#             */
/*   Updated: 2023/02/15 21:15:13 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include "./parsing/parsing.h"
# include "./utils/structs.h"
# include "./utils/utils.h"

int		sort_three(t_stack *X, char c);
int		sort_five(t_stack *A, t_stack *B);
int		sort_more(t_stack *A, t_stack *B, int len);
int		max_number_index(t_stack *stack_b, int max_number);
int		set_precision(int len);
void	init_stack_b(t_stack *stack_a, t_stack *stack_b, int *moves, int len);
int		push_to_stack_a(t_stack *stack_b, t_stack *stack_a, int *maximum_len,
			int before_max_range);
int		push_to_stack_b(t_stack *stack_a, t_stack *stack_b,
			int *before_max_range);
int		move_stack_a(t_stack *stack_b, int i);

#endif
