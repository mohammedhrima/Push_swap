#include "../Libft/libft.h"
int moves = 0;
#define NOT !

void swap_array(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void mysleep(int time)
{
	float q = 0;
	while (q < time * 200)
		q += 0.001;
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
			if (array_of_numbers[j] > array_of_numbers[i])
			{
				swap_array(array_of_numbers + j, array_of_numbers + i);
				swap_array(array_of_indexes + j, array_of_indexes + i);
			}
			i--;
		}
		j++;
	}
}
void check_repeated_numbers(int *array, int len)
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
				ft_printf("Error\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

// moves
// struct
typedef struct number
{
	int value;
	int index;
} num;

typedef struct stack
{
	num *array_of_nums;
	int lenght;
} stack;

int rotate(stack *list) // (up)
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

int reverse_rotate(stack *list) // (down)
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
	return (0);
}

// swap
int swap(stack *X)
{
	num tmp = X->array_of_nums[0];
	X->array_of_nums[0] = X->array_of_nums[1];
	X->array_of_nums[1] = tmp;
	return (1);
}

int printstacks(stack *A, stack *B, int len, int moves)
{
#if 0
	// if (len > 250)
	// 	mysleep(2);
	// else if (len > 50)
	// 	mysleep(80);
	// else if (len > 0)
	// 	mysleep(300);

	printf("\e[0;32m\n============================================================================\n");
	int j = 0;
	int k = 0;
	printf("stack A   \n");
	while (j < A->lenght)
	{
		printf("%4d ", A->array_of_nums[j++].index);
		if (j % 15 == 0)
			printf("|\n");
	}
	j = 0;
	printf("\n\nstack B\n");
	while (j < B->lenght)
	{
		printf("%4d ", B->array_of_nums[j++].index);
		if (j % 15 == 0) // (j % (len / 8) == 0)
			printf("|\n");
	}
	printf("\n============================================================================\n");
	printf("number of moves: %d\n", moves);
#endif
	return (1);
}

void is_sorted(stack *A)
{
	int i = 1;
	while (i < A->lenght)
	{
		if (A->array_of_nums[i].value < A->array_of_nums[i - 1].value)
			ft_printf("\033[0;31mwa elchriff verify dakchi 3endek %d < %d\n", A->array_of_nums[i].index, A->array_of_nums[i - 1].index);
		i++;
	}
}
///////////////////////////////////////////////////////////////////////////
// 3 sorting
int get_distance(num *array_of_nums)
{
	return (array_of_nums[0].index + 2 * array_of_nums[1].index + array_of_nums[2].index);
}
void sort_three(stack *X)
{
	// printf("\n");
	if (X->array_of_nums[0].index == X->array_of_nums[1].index + 1)
	{
		printf("sa\n");
		moves += swap(X);
	}
	if (X->lenght > 2)
	{
		int n = get_distance(X->array_of_nums);
		n == 3 && printf("ra\n") && rotate(X) && moves++;
		n == 5 && printf("rr\n") && reverse_rotate(X) && moves++;
		X->array_of_nums[0].index == X->array_of_nums[1].index + 1 && printf("sa\n") && swap(X) && moves++;
	}
	// printf("\n");
}

void sort_more(stack *A, stack *B, int len)
{
	int ra = 0;
	int rb = 0;
	int sa = 0;
	int sb = 0;
	int p = 0;
	float min; // for 2n
	float max; // for 2n
	int i;
	// int max;
	int precision;
	if (len < 250)
		precision = 4;
	if (len >= 250)
		precision = 6;
	if (len >= 500)
		precision = 10;

	i = 0;
#if 1 // working algorithm
	min = 0;
	max = len / precision;
	while (B->lenght < len)
	{
		while (B->lenght < (int)(max) && A->lenght)
		{
			ra = 0;
			rb = 0;
			if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
			{
				moves += push(A, B);
				ft_printf("pb\n");
				if (B->array_of_nums[0].index < (max - min) / 2 + min)
					rb = rotate(B);
			}
			else
				ra = rotate(A);
			ra &&rb &&ft_printf("rr\n") && moves++ &&printstacks(A, B, len, moves);
			ra && !rb && ft_printf("ra\n") && moves++ && printstacks(A, B, len, moves);
			rb && !ra && ft_printf("rb\n") && moves++ && printstacks(A, B, len, moves);
		}
		min += (len / precision);
		max += (len / precision);
	}
	printstacks(A, B, len, moves);
	// exit(0);
	int max_len = len - 1;
	int before_max_range = 0;
	int before_max = max_len - 1;
	i = 0;
	ra = 0;
	rb = 0;
	sa = 0;
	sb = 0;
	while (A->lenght < len)
	{
		i = 0;
		before_max_range = 0;
		while (i < B->lenght && B->array_of_nums[i].index != max_len)
			i++;
		if (i < B->lenght / 2)
		{
			while (B->array_of_nums[0].index != max_len)
			{
				if (B->array_of_nums[0].index == max_len - 1)
				{
					moves += push(B, A);
					ft_printf("pb\n") && printstacks(A, B, len, moves);
					before_max_range = 1;
				}
				else
					moves += rotate(B);
			}
		}
		else
		{
			while (B->array_of_nums[0].index != max_len)
			{
				if (B->array_of_nums[0].index == max_len - 1)
				{
					moves += push(B, A);
					before_max_range = 1;
				}
				else
					moves += reverse_rotate(B);
			}
		}

		if (B->array_of_nums[0].index == max_len)
		{
			moves += push(B, A);
			max_len--;
			if (before_max_range)
			{
				moves += swap(A);
				ft_printf("sa\n") && printstacks(A, B, len, moves);;
				max_len--;
			}
			ft_printf("pa\n") && printstacks(A, B, len, moves);;
		}
	}

#endif
}

void sort_five(stack *A, stack *B)
{
	printstacks(A, B, 0, moves);
	int len = A->lenght;
	while (A->lenght > 3)
	{
		if (A->array_of_nums[0].index < len - 3)
		{
			moves += push(A, B);
			printf("p\n") && printstacks(A, B, len, moves);;
		}
		else
			moves += rotate(A);
		printf("r\n") && printstacks(A, B, len, moves);;
	}
	if (B->array_of_nums[0].index < B->array_of_nums[1].index)
	{
		moves += swap(B);
		printf("sb\n") && printstacks(A, B, len, moves);;
	}

	printstacks(A, B, 0, moves);
	int i = 0;
	while (i < A->lenght)
	{
		A->array_of_nums[i].index = (A->array_of_nums[i].index - B->lenght);
		i++;
	}

	sort_three(A);

	printstacks(A, B, 0, moves);
	while (B->lenght > 0)
		moves += push(B, A);

	printstacks(A, B, 0, moves);

	printstacks(A, B, 0, moves);
}

int main(int argc, char **argv)
{
	// printf("hey\n");
	int i = 0;
	int j;
	char *str;
	char **array;
	if (argc < 2)
	{
		// ft_printf("please provide more arguments\n");
		exit(0);
	}

	i = 2;
	str = argv[1];
	while (i < argc)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	array = ft_split(str, ' ');
	/*
	 ./push_swap 42 41 1 5 " "
	 ./push_swap 42 41 1 5 """"
	 int_max >  ula < in_max
	 - +
	*/
	i = 0;
	while (array && array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (!ft_isdigit(array[i][j]) || ((array[i][j] == '+' || array[i][j] == '-') && j < ft_strlen(array[i]) && (array[i][j + 1] < '0' || array[i][j + 1] > '9')))
			{
				if (array[i][j] != ' ')
				{
					ft_printf("Error\n");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}

	int len;
	len = ft_arrlen(array);

	// allocate needed memory for array of numbers ,indexes  and feed them
	int *array_of_numbers = my_malloc((len + 1) * sizeof(int));
	int *array_of_indexes = my_malloc((len + 1) * sizeof(int));
	char **array_of_moves;
	i = 0;
	while (i < len)
	{
		array_of_numbers[i] = ft_atoi(array[i]);
		i++;
	}
	check_repeated_numbers(array_of_numbers, len);
	// array of indexes
	i = 0;
	while (i < len)
	{
		array_of_indexes[i] = i;
		i++;
	}
	// allocate stacks
	stack *A = my_malloc(sizeof(stack));
	stack *B = my_malloc(sizeof(stack));

	A->array_of_nums = ft_calloc(len, sizeof(num));
	A->lenght = len;

	B->array_of_nums = ft_calloc(len, sizeof(num));
	B->lenght = 0;

	// feed numbers
	i = 0;
	while (i < len)
	{
		A->array_of_nums[i].value = array_of_numbers[i];
		i++;
	}
	sort_array(array_of_numbers, array_of_indexes, len);
	// feed indexes
	i = 0;
	while (i < len)
	{
		A->array_of_nums[array_of_indexes[i]].index = i;
		i++;
	}
	// if (len < 2)
	// {
	// 	ft_printf("Error\n");
	// 	exit(0);
	// }
	if (len <= 3 && len > 1)
		sort_three(A);
	else if (len <= 5)
		sort_five(A, B);
	else if (len > 5)
		sort_more(A, B, len);
	printstacks(A, B, len, moves);
#if 0
	printf("\n\n\n=========== MAIN ===========\n");
	printf("\nafter sorting\nA: \n");
	i = 0;

	printf("\nA: \n");
	while (i < A->lenght)
	{
		printf("%4d ", A->array_of_nums[i].value);
		if (i % 20 == 0) //(A->lenght / 8)
			printf("|\n");
		else if (i % 10 == 0)
			printf("|\n");
		i++;
	}
	printf("\nB: \n");
	i = 0;
	while (i < B->lenght)
	{
		printf("%4d ", B->array_of_nums[i].value);
		if (B->lenght > 3 && i % 10 == 0) //(A->lenght / 8)
			printf("|\n");
		i++;
	}
	printf("\n\n");
#endif
	// printf("moves : %d\nA.lenght : %d\nB.lenght: %d\n", moves, A->lenght, B->lenght);
	if ((len <= 3 && moves > 2) || (len > 3 && len <= 5 && moves > 12) || (len > 5 && len <= 100 && moves > 1100) ||
		(len > 100 && len <= 500 && moves > 11500))
		printf("Bad number of moves");
	else
		printf("Good number of moves\n\n");
	is_sorted(A);
#if 0
	i = 0;
	while (i < len)
	{
		printf("%4d ", A->array_of_nums[i++].value);
		if (i % 15 == 0)
			printf("|\n");
	}
	printf("\n");
#endif
	// system("leaks push_swap");
	return (0);
}