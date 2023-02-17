/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:54:58 by mhrima            #+#    #+#             */
/*   Updated: 2023/02/15 21:31:40 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*readline(int fd)
{
	int		i;
	int		j;
	char	*res;
	char	*tmp;
	char	c;

	i = 0;
	j = 0;
	res = NULL;
	tmp = NULL;
	j = read(fd, &c, 1);
	while (j && c != '\n')
	{
		tmp = ft_strjoin(res, &c);
		free(res);
		res = ft_strdup(tmp);
		free(tmp);
		j = read(fd, &c, 1);
		if (j == 0)
			break ;
		i++;
		res[i] = '\0';
	}
	return (res);
}

int	is_not_valid_move(char *str)
{
	return (
		ft_strcmp(str, "sa") && ft_strcmp(str, "sb") && ft_strcmp(str, "ss")
		&& ft_strcmp(str, "pa") && ft_strcmp(str, "pb") && ft_strcmp(str,
			"ra") && ft_strcmp(str, "rb") && ft_strcmp(str, "rr")
		&& ft_strcmp(str, "rra") && ft_strcmp(str, "rrb") && ft_strcmp(str,
			"rrr"));
}

void	move_stack(char *move, t_stack *stack_a, t_stack *stack_b)
{
	!ft_strcmp(move, "sa") && swap(stack_a, 0);
	!ft_strcmp(move, "sb") && swap(stack_b, 0);
	!ft_strcmp(move, "ss") && swap(stack_a, 0) && swap(stack_b, 0);
	!ft_strcmp(move, "pa") && push(stack_b, stack_a, 0);
	!ft_strcmp(move, "pb") && push(stack_a, stack_b, 0);
	!ft_strcmp(move, "ra") && rotate(stack_a, 0);
	!ft_strcmp(move, "rb") && rotate(stack_b, 0);
	!ft_strcmp(move, "rr") && rotate(stack_a, 0) && rotate(stack_b, 0);
	!ft_strcmp(move, "rra") && reverse_rotate(stack_a, 0);
	!ft_strcmp(move, "rrb") && reverse_rotate(stack_b, 0);
	!ft_strcmp(move, "rrr") && reverse_rotate(stack_a, 0)
		&& reverse_rotate(stack_b, 0);
}

char	**get_move_from_input(void)
{
	char	*str0;
	char	*str1;
	char	*tmp;

	str0 = NULL;
	str1 = readline(0);
	tmp = NULL;
	while (str1)
	{
		if (is_not_valid_move(str1))
			my_exit("Error");
		tmp = ft_strjoin3(str0, str1, " ");
		free(str0);
		free(str1);
		str0 = tmp;
		str1 = readline(0);
	}
	return (ft_split(str0, ' '));
}

int	main(int argc, char **argv)
{
	int		i;
	int		len;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**array_of_moves;

	stack_a = init_stacks(read_arguments(argc, argv), &len);
	stack_b = new_stack(0, len);
	array_of_moves = get_move_from_input();
	i = 0;
	while (array_of_moves && array_of_moves[i])
		move_stack(array_of_moves[i++], stack_a, stack_b);
	if (is_sorted(stack_a))
		my_exit("OK");
	else
		my_exit("KO");
}
