/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:36:51 by mhrima            #+#    #+#             */
/*   Updated: 2023/02/15 20:31:13 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing.h"

int	*array_of_integers(int len)
{
	int	i;
	int	*array;

	array = my_malloc((len + 1) * sizeof(int));
	i = 0;
	while (i < len)
	{
		array[i] = i;
		i++;
	}
	return (array);
}

int	*convert_to_integers(int len, char **array)
{
	int			*array_of_numbers;
	long int	number;
	int			i;

	array_of_numbers = my_malloc((len + 1) * sizeof(int));
	i = 0;
	while (i < len)
	{
		if (ft_strlen(array[i]) > 13)
			my_exit("Error");
		number = ft_atoi(array[i]);
		if (number > INT_MAX || number < INT_MIN)
			my_exit("Error");
		array_of_numbers[i] = (int)number;
		i++;
	}
	return (array_of_numbers);
}

void	check_input(int there_is_numbers, char *arg)
{
	int	j;

	j = 0;
	while (there_is_numbers && arg[j])
	{
		if ((arg[j] == ' ' && arg[j + 1] != '\0' && arg[j + 1] != ' '
				&& !is_sign(arg[j + 1]) && !ft_isdigit(arg[j + 1]))
			|| (is_sign(arg[j]) && !ft_isdigit(arg[j + 1]))
			|| (ft_isdigit(arg[j]) && !ft_isdigit(arg[j + 1]) && arg[j
					+ 1] != '\0' && arg[j + 1] != ' '))
			my_exit("Error");
		j++;
	}
	if (!there_is_numbers)
		my_exit("Error");
}

char	**read_arguments(int argc, char **argv)
{
	char	*str;
	char	*tmp;
	int		i;
	int		there_is_numbers;

	if (argc < 2)
		exit(0);
	i = 1;
	str = NULL;
	while (i < argc)
	{
		there_is_numbers = is_valid(argv[i]);
		check_input(there_is_numbers, argv[i]);
		tmp = ft_strjoin3(str, " ", argv[i]);
		free(str);
		str = tmp;
		i++;
	}
	return (ft_split3(str, ' '));
}
