#include "../Libft/libft.h"
#include <signal.h>

void swap_array(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void mysleep(int time)
{
	float q = 0.001;
	while (q < time * 10000)
		q += 0.002;
}

void sort_array(int *array_of_numbers, int *array_of_indexes, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < len)
	{
		i = len - 1;
		while (i > j)
		{
			if (array_of_numbers[j] < array_of_numbers[i])
			{
				swap_array(array_of_numbers + j, array_of_numbers + i);
				swap_array(array_of_indexes + j, array_of_indexes + i);
			}
			i--;
		}
		j++;
	}
}

void check_repetetive_numbers(int *array, int len)
{
	int i = 0;
	int j = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] == array[j])
			{
				ft_printf("Error: there is repetetive number\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

// struct
typedef struct number
{
	int value;
	int index; // where it should go
} num;

typedef struct stack
{
	num *array_of_nums;
	int lenght;
} stack;

// functions
//  rotate (up)
int rotate(stack *list)
{
	if (list->lenght > 1)
	{
		num tmp = list->array_of_nums[0];
		ft_memmove(list->array_of_nums, list->array_of_nums + 1, (list->lenght - 1) * sizeof(num));
		list->array_of_nums[list->lenght - 1] = tmp;
		return (1);
	}
	return (0);
}

// reverse rotate (down)
int reverse_rotate(stack *list)
{
	if (list->lenght > 1)
	{
		num tmp = list->array_of_nums[list->lenght - 1];
		ft_memmove(list->array_of_nums + 1, list->array_of_nums, (list->lenght - 1) * sizeof(num));
		list->array_of_nums[0] = tmp;
		return (1);
	}
	return (0);
}

// push
int push(stack *src, stack *dest)
{
	if (src->lenght)
	{
		num tmp = src->array_of_nums[0];
		rotate(src); // up
		src->lenght--;
		dest->lenght++;
		reverse_rotate(dest); // down
		dest->array_of_nums[0] = tmp;
		return (1);
	}
	else
	{
		ft_printf("\n\"verify src len in push\"\n");
		return (0);
	}
}

// swap
int swap(stack *X)
{
	num tmp = X->array_of_nums[0];
	X->array_of_nums[0] = X->array_of_nums[1];
	X->array_of_nums[1] = tmp;
	return (1);
}

char **string(void)
{
	static char *str;

	return (&str);
}

void readline(int fd)
{
	int i = 0;

	char c;
	i += read(fd, &c, 1);
	while (i && c != '\n')
	{
		*string() = ft_strjoin(*string(), &c);
		i += read(fd, &c, 1);
	}
	*string() = ft_strjoin(*string(), " ");

}

void handle_signal(int sig)
{
	ft_printf("|%s|\n", *string());
	exit(0);
}

int main(int argc, char **argv)
{
	int i = 2;
	char *str;
	if (argc < 2)
	{
		ft_printf(" please provide more arguments\n");
		exit(0);
	}
	signal(SIGINT, handle_signal);

	str = argv[1];
	while (i < argc)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		i++;
	}

	char **array = ft_split(str, ' ');
	int *array_of_numbers;

	i = 0;
	int j;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (!ft_isdigit(array[i][j++]))
			{
				ft_printf("verify that there is only numbers\n");
				exit(1);
			}
		}
		i++;
	}

	i = 0;
	// ft_printf("|");
	// while (array[i])
	// {
	// 	ft_printf("|%s|", array[i++]);
	// }
	// ft_printf("|\n");
	/////////////////////////////////////////////////////////////////
	int len = i;
	// allocate needed memory for array of numbers ,indexes  and feed them
	array_of_numbers = my_malloc((len + 1) * sizeof(int));
	int *array_of_indexes = my_malloc((len + 1) * sizeof(int));
	i = 0;
	while (i < len)
	{
		array_of_numbers[i] = ft_atoi(array[i]);
		i++;
	}
	i = 0;
	// ft_printf("|");
	// while (i < len)
	// {
	// 	ft_printf("|%d|", array_of_numbers[i++]);
	// }
	// ft_printf("|\n");
	check_repetetive_numbers(array_of_numbers, len);
	// create array of indexes
	i = 0;
	while (i < len)
	{
		array_of_indexes[i] = i;
		i++;
	}

	// allocate stacks
	stack *A = ft_calloc(1, sizeof(stack));
	stack *B = ft_calloc(1, sizeof(stack));

	A->array_of_nums = ft_calloc(len, sizeof(num));
	A->lenght = len;

	B->array_of_nums = ft_calloc(len, sizeof(num));
	B->lenght = 0;

	// feed stack A
	i = 0;
	while (i < len)
	{
		A->array_of_nums[i].value = array_of_numbers[i];
		i++;
	}
	char *str1;
	while (1)
	{
		readline(0);
	}
	ft_printf("\n===============================================\n");
	// system("leaks a.out");
}