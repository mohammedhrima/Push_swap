#include "../Libft/libft.h"
#define AND &&
#define DO &&
#define OR |
#define NOT !
#define IS ==
#define EQUAL ==
#define PRINT ft_printf
#define IF
int main_spliter = 0;
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

int printstacks(stack *A, stack *B, int len)
{
	// mysleep(4);
	// printf("\n=============================================================\n");
	// int j = 0;
	// j = 0;
	// printf("stack A\n");
	// while (j < A->lenght)
	// {
	// 	printf("%4d ", A->array_of_nums[j++].index);
	// 	if (j % (len / 8) == 0)
	// 		printf("|\n");
	// }
	// j = 0;
	// printf("\nstack B\n");
	// while (j < B->lenght)
	// {
	// 	printf("%4d ", B->array_of_nums[j++].index);
	// 	if (j % (len / 8) == 0)
	// 		printf("|\n");
	// }
	// printf("\n=============================================================\n");
	// return (1);
}

int get_distance(num *array_of_nums)
{
	return (array_of_nums[0].index + 2 * array_of_nums[1].index + array_of_nums[2].index);
}

void is_sorted(stack *A)
{
	int i = 1;
	while (i < A->lenght)
	{
		if (A->array_of_nums[i].index > A->array_of_nums[i - 1].index)
			ft_printf("\033[0;31mwa elchriff verify dakchi 3endek\n");
		i++;
	}
}

void sort_3(stack *X, char c)
{
	int i = 0;
	if (X->lenght <= 1)
		ft_printf("\nverify length in sort\n");
	if (X->lenght > 1 && X->array_of_nums[0].index == X->array_of_nums[1].index + 1)
	{
		ft_printf("s%c ", c);
		swap(X);
		moves++;
	}
	if (X->lenght > 2)
	{
		int n = get_distance(X->array_of_nums);
		if (n == 3)
		{
			ft_printf("r%c ", c);
			rotate(X);
			moves++;
		}
		if (n == 5)
		{
			ft_printf("rr%c ", c);
			reverse_rotate(X);
			moves++;
		}
		if (X->array_of_nums[0].index == X->array_of_nums[1].index + 1)
		{
			ft_printf("s%c ", c);
			swap(X);
		}
	}
}

// be aware that a lenght change all the time

void sort4(stack *A, stack *B, int len)
{
	int ra = 0;
	int rb = 0;
	float min; // for 2n
	float max; // for 2n
	int spliter;
	
	spliter = 8;
	min = (float)len / 2; // for 2n
	max = (float)len / 2; // for 2nd
	while (max - min < len)
	{
		min -= (float)len / spliter;
		max += (float)len / spliter;
		while (B->lenght < (int)(max - min))
		{
			ra = 0;
			rb = 0;
			if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
			{
				moves += push(A, B);
				ft_printf("p ");
				if (B->array_of_nums[0].index >= len / 2)
					rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
			}
			else
				ra = rotate(A);
			ra &&rb &&ft_printf("rr ") && moves++ &&printstacks(A, B, len);
			ra && !rb && ft_printf("ra ") && moves++ && printstacks(A, B, len);
			rb && !ra && ft_printf("rb ") && moves++ && printstacks(A, B, len);
		}
	}
	int i;
	int to_push_index = 0;
	i = 0;
	while (A->lenght < len)
	{
		i = 0;
		while (i < B->lenght / 2 && B->array_of_nums[i].index != to_push_index && B->array_of_nums[B->lenght - i - 1].index != to_push_index)
			i++;
		if (B->array_of_nums[i].index == to_push_index)
		{
			while (i > 0)
			{
				i--;
				moves += rotate(B);
				ft_printf("rb ") && printstacks(A, B, len);
			}
		}
		else if (B->array_of_nums[B->lenght - i - 1].index == to_push_index)
		{
			while (i >= 0)
			{
				i--;
				moves += reverse_rotate(B);
				ft_printf("rrb ") && printstacks(A, B, len);
			}
		}
		if (B->array_of_nums[0].index == to_push_index)
		{
			moves += push(B, A);
			to_push_index++;
			ft_printf("p ") && printstacks(A, B, len);
		}
	}
}

int main(void)
{
	int i;
	int const_array[] = {709, 896, 356, 367, 748, 229, 130, 422, 761, 525, 528, 464, 281, 624, 655, 676, 869, 554, 967, 662, 478, 597, 309, 480, 723, 858, 920, 337, 440, 961, 877, 636, 370, 466, 825, 186, 992, 98, 382, 871, 911, 972, 643, 334, 913, 984, 223, 379, 672, 61, 584, 788, 518, 120, 732, 628, 305, 685, 50, 46, 135, 621, 300, 932, 496, 757, 386, 531, 738, 908, 714, 921, 140, 74, 592, 357, 299, 951, 758, 657, 476, 137, 990, 596, 502, 196, 182, 16, 749, 840, 550, 879, 322, 930, 13, 465, 277, 559, 933, 73};
	int *array_of_indexes = ft_calloc(1, sizeof(const_array));
	int *array_of_numbers = ft_calloc(1, sizeof(const_array));
	int len = (int)(sizeof(const_array) / sizeof(int));
	check_repetetive_numbers(const_array, len);

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

	sort_array(array_of_numbers, array_of_indexes, len);
	// feed indexes
	i = 0;
	while (i < len)
	{
		A->array_of_nums[array_of_indexes[i]].index = i;
		i++;
	}
	sort4(A, B, len);
	printf("\n\n\n=========== MAIN ===========\n");
	printf("\nafter sorting\nA: \n");
	i = 0;
	i = 0;
	while (i < A->lenght)
	{
		printf("%4d ", A->array_of_nums[i++].index);
		if (i % (A->lenght / 8) == 0)
			printf("|\n");
	}
	printf("\nB: \n");

	i = 0;
	while (i < B->lenght)
	{
		printf("%4d ", B->array_of_nums[i++].index);
		if (i % (B->lenght / 8) == 0)
			printf("|\n");
	}
	printf("\n");
	i = 0;
	while (i < A->lenght)
	{
		printf("%4d ", A->array_of_nums[i++].value);
		if (i % (A->lenght / 8) == 0)
			printf("|\n");
	}
	printf("\n\n");

	printf("moves : %d\nA.lenght : %d\nB.lenght: %d\n", moves, A->lenght, B->lenght);
	is_sorted(A);
	return (0);
}