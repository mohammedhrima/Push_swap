/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:01:58 by mhrima            #+#    #+#             */
/*   Updated: 2023/02/15 20:39:30 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	check_repeated_numbers(int *array, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] == array[j])
				my_exit("Error");
			j++;
		}
		i++;
	}
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	contains_number(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (!contains_number(str))
		return (0);
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]) && !is_sign(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int	is_sorted(t_stack *A)
{
	int	i;

	i = 1;
	while (i < A->lenght)
	{
		if (A->array_of_nums[i].value < A->array_of_nums[i - 1].value)
			return (0);
		i++;
	}
	return (1);
}
