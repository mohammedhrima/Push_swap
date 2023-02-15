#include "../Libft/libft.h"
#define NOT !
// int moves = 0;

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

void swap_array(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
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

int rotate(stack *list, char c)
{
	if (list->lenght > 1)
	{
		num tmp = list->array_of_nums[0];
		ft_memmove(list->array_of_nums, list->array_of_nums + 1, (list->lenght - 1) * sizeof(num));
		list->array_of_nums[list->lenght - 1] = tmp;
		if (c)
			ft_printf("r%c\n", c);
		return (1);
	}
	return (0);
}

int reverse_rotate(stack *list, char c)
{
	if (list->lenght > 1)
	{
		num tmp = list->array_of_nums[list->lenght - 1];
		ft_memmove(list->array_of_nums + 1, list->array_of_nums, (list->lenght - 1) * sizeof(num));
		list->array_of_nums[0] = tmp;
		if (c)
			ft_printf("r%c\n", c);
		return (1);
	}
	return (0);
}

int push(stack *src, stack *dest, char c)
{
	if (src->lenght)
	{
		num tmp = src->array_of_nums[0];
		rotate(src, 0);
		src->lenght--;
		dest->lenght++;
		reverse_rotate(dest, 0);
		dest->array_of_nums[0] = tmp;
		ft_printf("p%c\n", c);
		return (1);
	}
	return (0);
}

int swap(stack *X, char c)
{
	num tmp = X->array_of_nums[0];
	X->array_of_nums[0] = X->array_of_nums[1];
	X->array_of_nums[1] = tmp;
	if (c)
		ft_printf("s%c\n", c);
	return (1);
}

int sort_three(stack *X, char c)
{
	int moves;
	int n;

	moves = 0;
	if (X->array_of_nums[0].index == X->array_of_nums[1].index + 1)
		moves += swap(X, c);
	if (X->lenght > 2)
	{
		n = X->array_of_nums[0].index + 2 * X->array_of_nums[1].index + X->array_of_nums[2].index;
		if (n == 3)
			moves += rotate(X, c);
		if (n == 5)
			moves += reverse_rotate(X, c);
		if (X->array_of_nums[0].index == X->array_of_nums[1].index + 1)
			moves += swap(X, c);
	}
	return (moves);
}
int printstacks(stack *A, stack *B, int len, int moves)
{
#if 1
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
// to verify
/*
find lkbar men 3 push them to b
sort A
get back from b
*/
int sort_five(stack *A, stack *B)
{
	int i;
	int moves;

	moves = 0;
	while (A->lenght > 3)
	{
		i = 0;
		while (A->array_of_nums[i].index < 3 && A->array_of_nums[A->lenght - i - 1].index < 3)
			i++;
		if (A->array_of_nums[i].index >= 3)
		{
			while (A->array_of_nums[0].index < 3)
				moves += rotate(A, 'a');
		}
		else if (A->array_of_nums[A->lenght - i - 1].index >= 3)
		{
			while (A->array_of_nums[0].index < 3)
				moves += reverse_rotate(A, 'a');
		}
		if (A->array_of_nums[0].index >= 3)
			moves += push(A, B, 'b');
	}
	if (B->lenght > 1 && B->array_of_nums[0].index > B->array_of_nums[1].index)
		moves += swap(B, 'b');
	moves += sort_three(A, 'a');
	while (B->lenght > 0)
	{
		moves += push(B, A, 'a');
		moves += rotate(A, 'a');
	}
	return (moves);
}

int sort_more(stack *A, stack *B, int len)
{
	float min;
	float max;
	int precision;
	int moves;
	int max_len;
	int before_max_range;
	int before_max;
	int i;

	if (len < 250)
		precision = 4;
	if (len >= 250)
		precision = 6;
	if (len >= 500)
		precision = 9;
	min = 0.0;
	max = len / precision;
	moves = 0.0;
#if 0
	while (B->lenght < len)
	{
		while (B->lenght < (int)(max) && A->lenght)
		{
			i = 0;
			while ((A->array_of_nums[i].index < min || A->array_of_nums[i].index >= max) && (A->array_of_nums[A->lenght - i - 1].index < min || A->array_of_nums[A->lenght - i - 1].index >= max))
				i++;

			if (A->array_of_nums[i].index >= min && A->array_of_nums[i].index < max)
			{
				while (A->array_of_nums[0].index < min || A->array_of_nums[0].index >= max)
					moves += rotate(A, 'a');
				// moves += push(A, B, 'b');
				// if (B->array_of_nums[0].index < (max - min) / 2 + min)
				// 	moves += rotate(B, 'b');
			}
			else if (A->array_of_nums[A->lenght - i - 1].index >= min && A->array_of_nums[A->lenght - i - 1].index < max)
			{
				while (A->array_of_nums[0].index < min || A->array_of_nums[0].index >= max)
					moves += reverse_rotate(A, 'a');
				// moves += push(A, B, 'b');
				// if (B->array_of_nums[0].index < (max - min) / 2 + min)
				// 	moves += rotate(B, 'b');
			}
			if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
			{
				moves += push(A, B, 'b');
				if (B->array_of_nums[0].index < (max + min) / 2)
					moves += rotate(B, 'b');
			}
			// else
			// 	moves += rotate(A, 'a');
		}
		min += (len / precision);
		max += (len / precision);
	}
#else
	while (B->lenght < len)
	{
		while (B->lenght < (int)(max) && A->lenght)
		{
			if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
			{
				moves += push(A, B, 'b');
				if (B->array_of_nums[0].index < (max - min) / 2 + min)
					moves += rotate(B, 'b');
			}
			else
				moves += rotate(A, 'a');
		}
		min += (len / precision);
		max += (len / precision);
	}
#endif
	i = 0;
	max_len = len - 1;
	before_max_range = 0;
	before_max = max_len - 1;
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
					moves += push(B, A, 'a');
					before_max_range = 1;
				}
				else
					moves += rotate(B, 'b');
			}
		}
		else
		{
			while (B->array_of_nums[0].index != max_len)
			{
				if (B->array_of_nums[0].index == max_len - 1)
				{
					moves += push(B, A, 'a');
					before_max_range = 1;
				}
				else
					moves += reverse_rotate(B, 'b');
			}
		}
		if (B->array_of_nums[0].index == max_len)
		{
			moves += push(B, A, 'b');
			max_len--;
			if (before_max_range)
			{
				moves += swap(A, 'a');
				max_len--;
			}
		}
	}
	return (moves);
}

int ft_issign(char c)
{
	return (c == '+' || c == '-');
}
int contains_number(char *str)
{
	int i = 0;
	while (str && str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}
int is_valid(char *str)
{
	int i = 0;

	if (!contains_number(str))
		return (0);
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_issign(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int is_sorted(stack *A)
{
	int i = 1;
	while (i < A->lenght)
	{
		if (A->array_of_nums[i].value < A->array_of_nums[i - 1].value)
		{
			// ft_printf("\033[0;31mwa elchriff verify dakchi 3endek %d < %d\n", A->array_of_nums[i].index, A->array_of_nums[i - 1].index);
			return (0);
		}
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int len;
	char *str;
	char **array;
	long int number;
	int there_is_numbers;
	int *array_of_numbers;
	int *array_of_indexes;
	int moves = 0;

	if (argc < 2)
		exit(0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		there_is_numbers = is_valid(argv[i]);
		while (there_is_numbers && argv[i][j])
		{
			if (argv[i][j] == ' ' && argv[i][j + 1] != '\0' && argv[i][j + 1] != ' ' && !ft_issign(argv[i][j + 1]) && !ft_isdigit(argv[i][j + 1]))
			{
				there_is_numbers = 0;
				break;
			}
			if (ft_issign(argv[i][j]) && !ft_isdigit(argv[i][j + 1]))
			{
				there_is_numbers = 0;
				break;
			}
			if (ft_isdigit(argv[i][j]) && !ft_isdigit(argv[i][j + 1]) && argv[i][j + 1] != '\0' && argv[i][j + 1] != ' ')
			{
				there_is_numbers = 0;
				break;
			}
			j++;
		}
		if (!there_is_numbers)
		{
			ft_printf("Error\n");
			exit(0);
		}
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	array = ft_split(str, ' ');
	len = ft_arrlen(array);
	array_of_numbers = my_malloc((len + 1) * sizeof(int));
	i = 0;
	while (i < len)
	{
		if (ft_strlen(array[i]) > 13)
		{
			ft_printf("Error\n");
			exit(0);
		}
		number = ft_atoi(array[i]);
		if (number > INT_MAX || number < INT_MIN)
		{
			ft_printf("Error\n");
			exit(0);
		}
		array_of_numbers[i] = (int)number;
		i++;
	}
	check_repeated_numbers(array_of_numbers, len);
	array_of_indexes = my_malloc((len + 1) * sizeof(int));
	i = 0;
	while (i < len)
	{
		array_of_indexes[i] = i;
		i++;
	}
	stack *A = my_malloc(sizeof(stack));
	stack *B = my_malloc(sizeof(stack));

	A->array_of_nums = ft_calloc(len, sizeof(num));
	A->lenght = len;
	B->array_of_nums = ft_calloc(len, sizeof(num));
	B->lenght = 0;

	i = 0;
	while (i < len)
	{
		A->array_of_nums[i].value = array_of_numbers[i];
		i++;
	}
	sort_array(array_of_numbers, array_of_indexes, len);
	i = 0;
	while (i < len)
	{
		A->array_of_nums[array_of_indexes[i]].index = i;
		i++;
	}
	if (is_sorted(A))
		exit(0);
	if (len <= 3 && len > 1)
		moves += sort_three(A, 'a');
	else if (len <= 5)
		moves += sort_five(A, B);
	else if (len > 5)
		moves += sort_more(A, B, len);
	if ((len <= 3 && moves > 2) || (len > 3 && len <= 5 && moves > 12) || (len > 5 && len <= 100 && moves > 1100) ||
		(len > 100 && len <= 500 && moves > 11500))
		printf("Bad number of moves %d\n", moves);
	else
		printf("Good number of moves %d\n", moves);
	i = 0;
	while (i < A->lenght)
	{
		printf("%d ", A->array_of_nums[i++].value);
	}
	printf("\n");
	if (is_sorted(A) == 0)
		ft_printf("\033[0;31mwa elchriff verify dakchi 3endek %d < %d\n", A->array_of_nums[i].index, A->array_of_nums[i - 1].index);
}