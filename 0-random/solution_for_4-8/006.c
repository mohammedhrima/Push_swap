#include "../Libft/libft.h"
#define AND &&
#define DO &&
#define OR |
#define NOT !
#define IS ==
#define EQUAL ==
#define PRINT ft_printf
#define IF

int moves = 0;
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
				printf("Error: there is repetetive number\n");
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
		printf("\n\"verify src len in push\"\n");
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

num *max(stack *X)
{
	int i = 0;
	while (i < X->lenght)
	{
		if (X->array_of_nums[i].index == X->lenght - 1)
			return (X->array_of_nums + i);
		i++;
	}
	return (NULL);
}

num *min(stack *X)
{
	int i = 0;
	while (i < X->lenght)
	{
		if (X->array_of_nums[i].index == 0)
			return (X->array_of_nums + i);
		i++;
	}
	return (NULL);
}

int get_distance(num *array_of_nums)
{
	return (array_of_nums[0].index + 2 * array_of_nums[1].index + array_of_nums[2].index);
}

void sort_3(stack *X, char c)
{
	int i = 0;
	if (X->lenght <= 1)
		printf("\nverify length in sort\n");
	if (X->lenght > 1 && X->array_of_nums[0].index == X->array_of_nums[1].index + 1)
	{
		printf("s%c ", c);
		swap(X);
		moves++;
	}
	if (X->lenght > 2)
	{
		int n = get_distance(X->array_of_nums);
		//	printf("\nn: %d\n", n);
		if (n == 3)
		{
			printf("r%c ", c);
			rotate(X);
			moves++;
		}
		if (n == 5)
		{
			printf("rr%c ", c);
			reverse_rotate(X);
			moves++;
		}
		if (X->array_of_nums[0].index == X->array_of_nums[1].index + 1)
		{
			printf("s%c ", c);
			swap(X);
		}
	}
}
// void sort_32(stack *X, char c)
// {

// }

// void sort(stack *A, stack *B, int len)
// {
// 	int i = 0;
// 	while (i < A->lenght)
// 	{
// 		if (A->array_of_nums[0].index < len / 4)
// 		{
// 			push(A, B);
// 			moves++;
// 		}
// 		else
// 		{
// 			rotate(A); // down}
// 			i++;
// 		}
// 		i = 0;
// 		while (i < A->lenght)
// 		{
// 			if (A->array_of_nums[0].index < len / 2)
// 			{
// 				push(A, B);
// 			}
// 			else
// 			{
// 				rotate(A); // down
// 			}
// 			i++;
// 		}
// 		i = 0;
// 		while (i < A->lenght)
// 		{
// 			if (A->array_of_nums[0].index < 3 * (len / 4))
// 			{
// 				push(A, B);
// 			}
// 			else
// 			{
// 				rotate(A); // down
// 			}
// 			i++;
// 		}
// 		while (A->lenght > 0)
// 		{
// 			push(A, B);
// 		}
// 	}
// }

// be aware that a lenght change all the time
void sort_more(stack *A, stack *B, int len)
{
	printf("    len/4: %d\n", len / 4);
	printf("    len/2: %d\n", len / 2);
	printf("3*(len/4): %d\n", 3 * (len / 4));
	printf("      len: %d\n", len);
	int ra = 0;
	int rb = 0;
	int p = 0;
	printf("2nd while loop\n");
	while (B->lenght < len / 2)
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= len / 4 && A->array_of_nums[0].index < 3 * (len / 4))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			if (rb)
				rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
			moves++;
		else
			moves += (ra + rb);
	}
	printf("2nd while loop\n");
	while (B->lenght < len)
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 3 * (len / 4) || A->array_of_nums[0].index < len / 4)
		{
			if (A->array_of_nums[0].index >= 3 * (len / 4))
				rb++;
			moves += push(A, B);
			if (rb)
				rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
			moves++;
		else
			moves += (ra + rb);
	}
}

int main(void)
{
	int i;
	int const_array[] = {495, 163, 138, 375, 274, 220, 19, 456, 293, 255, 430, 222, 89, 31, 38, 397, 62, 278, 473, 329, 491, 447, 3, 352, 76, 146, 243, 483, 112, 322, 269, 33, 81, 364, 393, 408, 304, 297, 4, 71, 53, 95, 77, 471, 61, 385, 282, 426, 290, 315, 359, 86, 478, 91, 43, 403, 378, 466, 337, 402, 223, 84, 59, 227, 476, 380, 247, 179, 177, 169, 373, 140, 224, 17, 207, 118, 279, 445, 136, 454, 55, 339, 159, 481, 182, 377, 65, 312, 318, 265, 85, 411, 372, 193, 472, 196};

	int *array_of_indexes = ft_calloc(1, sizeof(const_array));
	int *array_of_numbers = ft_calloc(1, sizeof(const_array));
	int len = (int)(sizeof(const_array) / sizeof(int));
	check_repetetive_numbers(const_array, len);

	// copy const_array to the heap in array_of_numbers
	ft_memcpy(array_of_numbers, const_array, sizeof(const_array));

	i = 0;
	while (i < len)
	{
		array_of_indexes[i] = i;
		i++;
	}

	// setup stack A and B
	stack *A = ft_calloc(1, sizeof(stack));
	stack *B = ft_calloc(1, sizeof(stack));

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

	printf("\n=========== MAIN ===========\n");
	sort_array(array_of_numbers, array_of_indexes, len);
	// feed indexes
	i = 0;
	while (i < len)
	{
		A->array_of_nums[array_of_indexes[i]].index = i;
		i++;
	}
	// sort_3(A, 'a');
	sort_more(A, B, len);

	printf("\nafter sorting\nA: \n");
	i = 0;
	// while (i < A->lenght)
	// 	printf("%4d ", A->array_of_nums[i++].value);
	// printf("\nin:");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].index);
	printf("\n\n");
	printf("\nB: \n");
	i = 0;
	// while (i < B->lenght)
	// 	printf("%4d ", B->array_of_nums[i++].value);
	// printf("\nin:");
	i = 0;
	while (i < B->lenght)
	{
		printf("%4d ", B->array_of_nums[i++].index);
		if (i%(len / 4) == 0)
			printf("\n");
	}
	printf("\n\n");
	printf("moves : %d\n\n", moves);

	return (0);
}