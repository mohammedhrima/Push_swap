#include "../Libft/libft.h"
int moves = 0;

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
				ft_printf("Error: there is repeated numbers in index %d\n", i);
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
	int index; // where it should go
	// int next;
	// int prev;
	int len_of_fronts;
	int len_of_backs;
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

int printstacks(stack *A, stack *B, int len, int moves)
{
#if 1
	if (len > 250)
		mysleep(10);
	else if (len > 50)
		mysleep(80);
	else if (len > 0)
		mysleep(300);

	printf("\e[0;32m\n============================================================================\n");
	int j = 0;
	j = 0;
	printf("stack A\n");
	while (j < A->lenght)
	{
		printf("%4d ", A->array_of_nums[j++].index);
		if (j % 15 == 0)
			printf("|\n");
	}
	j = 0;
	printf("\nstack B\n");
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
		if (A->array_of_nums[i].index < A->array_of_nums[i - 1].index)
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
	int i = 0;
	printf("\n");
	if (X->array_of_nums[0].index == X->array_of_nums[1].index + 1)
	{
		printf("sa\n");
		swap(X);
	}
	int n = get_distance(X->array_of_nums);
	n == 3 && printf("ra\n") && rotate(X);
	n == 5 && printf("rr\n") && reverse_rotate(X);
	X->array_of_nums[0].index == X->array_of_nums[1].index + 1 && printf("sa ") && swap(X);
	printf("\n");
}

void sort_more(stack *A, stack *B, int len)
{
	int ra = 0;
	int rb = 0;
	float min; // for 2n
	float max; // for 2n
	int i;
	int j;
	// int max;
	int precision;
	if (len < 250)
		precision = 8; // 5 is best for range of 100
	if (len >= 250)
	{
		precision = 8;
	}
#if 0
	min = len / 2 + len % precision;
	max = len / 2 - len % precision;
	while (B->lenght < len)
	{
		min -= (len / precision + len % precision);
		max += (len / precision + len % precision);
		while (B->lenght < (int)(max - min) && A->lenght)
		{
			ra = 0;
			rb = 0;
			if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
			{
				moves += push(A, B);
				ft_printf("pb\n");
				if (B->array_of_nums[0].index <= len / 2)
					rb = rotate(B);
			}
			else
				ra = rotate(A);
			ra &&rb &&ft_printf("rr\n") && moves++ &&printstacks(A, B, len, moves);
			ra && !rb && ft_printf("ra\n") && moves++ && printstacks(A, B, len, moves);
			rb && !ra && ft_printf("rb\n") && moves++ && printstacks(A, B, len, moves);
		}
	}

	int max_len = len - 1;
	i = 0;
	int before_max = 0;
	while (A->lenght < len)
	{
		i = 0;
		before_max = 0;
		while (i < B->lenght / 2 && B->array_of_nums[i].index != max_len && B->array_of_nums[B->lenght - i - 1].index != max_len)
		{
			i++;
		}
		if (B->array_of_nums[i].index == max_len)
		{
			while (i > 0)
			{
				if (B->array_of_nums[i].index == max_len - 1 && B->array_of_nums[B->lenght - i - 1].index == max_len - 1)
				{
					moves += push(B, A);
					ft_printf("pa\n");
					before_max = 1;
					i--;
				}
				i--;
				moves += rotate(B);
				ft_printf("rb\n") && printstacks(A, B, len, moves);
			}
		}
		else if (B->array_of_nums[B->lenght - i - 1].index == max_len)
		{
			while (i >= 0)
			{
				if (B->array_of_nums[i].index == max_len - 1 && B->array_of_nums[B->lenght - i - 1].index == max_len - 1)
				{
					moves += push(B, A);
					ft_printf("pa\n");
					before_max = 1;
					i--;
				}
				i--;
				moves += reverse_rotate(B);
				ft_printf("rrb\n") && printstacks(A, B, len, moves);
			}
		}
		if (B->array_of_nums[0].index == max_len)
		{
			moves += push(B, A);
			max_len--;
			if (before_max)
			{
				moves += swap(B);
				max_len--;
			}
			ft_printf("pa\n") && printstacks(A, B, len, moves);
		}
	}
#elif 1
	i = 0;
	j = 0;
	int next;
	int top_longest_sequence = 2;			  // len of sequence
	int top_head_sequence = -1;				  // the index of head (before the begenning of array)
	int bottom_longest_sequence = 2;		  // len of sequence
	int bottom_head_sequence = A->lenght + 1; // the index of head (after the end of array)
	int sequence_head_index = -1;
	int sequence_len = 2;
	int top = 0;
	int bottom = 0;

	while (i < A->lenght) // up
	{
		next = A->array_of_nums[i].index + 1;
		if (A->array_of_nums[i].index == A->lenght)
			next = 0;
		A->array_of_nums[i].len_of_fronts = 0;
		j = i;
		while (j < A->lenght)
		{
			if (A->array_of_nums[j].index == next)
			{
				next++;
				A->array_of_nums[i].len_of_fronts++;
			}
			j++;
		}
		if (i > 0)
		{
			j = 0;
			while (j < i)
			{
				if (A->array_of_nums[j].index == next)
				{
					next++;
					A->array_of_nums[i].len_of_fronts++;
				}
				j++;
			}
		}
		if (A->array_of_nums[i].len_of_fronts == top_longest_sequence && i < top_head_sequence) // close to the top
		{
			// found same sequence but close to the top
			top_head_sequence = A->array_of_nums[i].index;
		}
		if (A->array_of_nums[i].len_of_fronts > top_longest_sequence)
		{
			top_head_sequence = A->array_of_nums[i].index;			  // index of closest sequence
			top_longest_sequence = A->array_of_nums[i].len_of_fronts; // len of that sequence
		}
		i++;
	}

	i = 0;
	j = 0;
	int prev;
	while (i < A->lenght) // down
	{
		prev = A->array_of_nums[i].index + 1;
		if (A->array_of_nums[i].index == A->lenght)
			prev = 0;
		A->array_of_nums[i].len_of_backs = 0;
		j = i;
		while (j > 0)
		{
			if (A->array_of_nums[j].index == prev)
			{
				prev++;
				A->array_of_nums[i].len_of_backs++;
			}
			j--;
		}
		if (i < A->lenght - 1)
		{
			j = A->lenght - 1;
			while (j > i)
			{
				if (A->array_of_nums[j].index == prev)
				{
					prev++;
					A->array_of_nums[i].len_of_backs++;
				}
				j--;
			}
		}
		if (A->array_of_nums[i].len_of_backs == bottom_longest_sequence && i > bottom_head_sequence) // close to the bottom
		{
			// found same sequence but close to the top
			bottom_head_sequence = A->array_of_nums[i].index;
		}
		if (A->array_of_nums[i].len_of_backs > bottom_longest_sequence)
		{
			bottom_head_sequence = A->array_of_nums[i].index;			// index of closest sequence
			bottom_longest_sequence = A->array_of_nums[i].len_of_backs; // len of that sequence
		}
		i++;
	}

	printf("\n==========================================================\n");
	i = 0;
	while (i < A->lenght)
	{
		printf("%d ", A->array_of_nums[i].index);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < A->lenght)
	{
		printf("A->array_of_nums[%d].index:%2d, how much next numbers: %d, how much behind numbers: %d\n", i, A->array_of_nums[i].index, A->array_of_nums[i].len_of_fronts, A->array_of_nums[i].len_of_backs);
		i++;
	}
	if (top_longest_sequence > bottom_longest_sequence)
	{
		sequence_head_index = top_longest_sequence;
		sequence_len = top_longest_sequence;
		top = 1;
	}
	if (top_longest_sequence < bottom_longest_sequence)
	{
		sequence_head_index = bottom_longest_sequence;
		sequence_len = bottom_longest_sequence;
		bottom = 1;
	}
	if (top_longest_sequence == bottom_longest_sequence)
	{
		sequence_len = top_longest_sequence;
		if (top_head_sequence < A->lenght - bottom_head_sequence)
		{
			sequence_head_index = top_head_sequence;
			top = 1;
		}
		else
		{
			sequence_head_index = bottom_head_sequence;
			bottom = 1;
		}
	}
	printf("\n\nbest sequence's, it's head is in index %d -> %d, len: %d ", sequence_head_index, A->array_of_nums[sequence_head_index].index, sequence_len);
	if (top)
		printf("from top\n");
	if (bottom)
		printf("from botton\n");

	printf("\n===================================================================================\n");
	i = 0;
	while (B->lenght < sequence_len)
	{
		if (bottom)
			reverse_rotate(A);
		if (top)
			rotate(A);
		i++;
	}

#endif
}
#if 0
void sort_five(stack *A, stack *B)
{
	int i = 0;
	int to_find = 0;
	printf("A.lenght:%d, to_find:%d\n", A->lenght, to_find);
	while (A->lenght > 3)
	{
		while (A->array_of_nums[i].index != to_find && A->array_of_nums[A->lenght - i - 1].index != to_find)
			i++;
		if (A->array_of_nums[i].index == to_find)
		{
			while (i > 0)
			{
				i--;
				moves += rotate(A);
				ft_printf("ra "); // && printstacks(A, B, len);
			}
		}
		if (A->array_of_nums[A->lenght - i - 1].index == to_find)
		{
			while (i >= 0)
			{
				i--;
				moves += reverse_rotate(A);
				ft_printf("rra "); //&& printstacks(A, B, len);
			}
		}
		if (A->array_of_nums[0].index == to_find)
		{
			moves += push(A, B);
			to_find = 0;
			ft_printf("pa "); // && printstacks(A, B, len);
		}
	}
}
#endif

int main(int argc, char **argv)
{
	// printf("hey\n");
	int i = 2;
	int j;
	char *str;
	char **array;
	if (argc < 2)
	{
		ft_printf("please provide more arguments\n");
		exit(-1);
	}

	str = argv[1];
	while (i < argc)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	array = ft_split(str, ' ');

	i = 0;
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
		// A->array_of_nums[array_of_indexes[i]].next = i + 1;
		// if (i == len - 1)
		// 	A->array_of_nums[array_of_indexes[i]].next = 0;
		// A->array_of_nums[array_of_indexes[i]].prev = i - 1;
		// if (i == 0)
		// 	A->array_of_nums[array_of_indexes[i]].prev = len - 1;
		A->array_of_nums[array_of_indexes[i]].len_of_fronts = 0;
		A->array_of_nums[array_of_indexes[i]].len_of_backs = 0;
		i++;
	}
	if (len < 2)
	{
		ft_printf("Error\n");
		exit(0);
	}
	else if (len <= 3)
		sort_three(A);
	else if (len <= 5)
		; // sort_five(A, B);
	else
		sort_more(A, B, len);

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

	printf("moves : %d\nA.lenght : %d\nB.lenght: %d\n", moves, A->lenght, B->lenght);
	if ((len <= 3 && moves > 2) || (len > 3 && len <= 5 && moves > 12) || (len > 5 && len <= 100 && moves > 1100) ||
		(len > 100 && len <= 500 && moves > 11500))
		printf("Bad number of moves");
	else
		printf("Good number of moves\n\n");
	is_sorted(A);
#endif
	// i = 0;
	// while (i < len)
	// {
	// 	printf("%4d ", array_of_numbers[i++]);
	// 	if (i % 15 == 0)
	// 		printf("|\n");
	// }
	// printf("\n");
	return (0);
}