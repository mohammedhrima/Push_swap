/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:01:18 by mhrima            #+#    #+#             */
/*   Updated: 2023/02/15 20:50:04 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../push_swap.h"

void		swap_array(int *x, int *y);
void		sort_array(int *array_of_numbers, int *array_of_indexes, int len);
void		check_repeated_numbers(int *array, int len);
int			is_sign(char c);
int			contains_number(char *str);
int			is_valid(char *str);
int			is_sorted(t_stack *A);
int			rotate(t_stack *list, char c);
int			reverse_rotate(t_stack *list, char c);
int			push(t_stack *src, t_stack *dest, char c);
int			swap(t_stack *list, char c);
t_stack		*new_stack(int virtual_len, int len);
t_stack		*init_stacks(char **array, int *len);
void		my_exit(char *msg);
#endif
