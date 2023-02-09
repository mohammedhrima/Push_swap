#include "../Libft/libft.h"
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
void rotate(stack *list)
{
	num tmp = list->array_of_nums[0];
	ft_memmove(list->array_of_nums, list->array_of_nums + 1, (list->lenght - 1) * sizeof(num));
	list->array_of_nums[list->lenght - 1] = tmp;
}

// reverse rotate (down)
void reverse_rotate(stack *list)
{
	num tmp = list->array_of_nums[list->lenght - 1];
	ft_memmove(list->array_of_nums + 1, list->array_of_nums, (list->lenght - 1) * sizeof(num));
	list->array_of_nums[0] = tmp;
}

// push
void push(stack *src, stack *dest)
{
	if (src->lenght)
	{
		num tmp = src->array_of_nums[0];
		rotate(src); // up
		src->lenght--;
		dest->lenght++;
		reverse_rotate(dest); // down
		dest->array_of_nums[0] = tmp;
		moves++;
	}
	else
	{
		printf("\n\"verify src len in push\"\n");
	}
}

// swap
void swap(stack *X)
{
	num tmp = X->array_of_nums[0];
	X->array_of_nums[0] = X->array_of_nums[1];
	X->array_of_nums[1] = tmp;
}

int get_distance(num *array_of_nums)
{
	return (array_of_nums[0].index + 2 * array_of_nums[1].index + array_of_nums[2].index);
}

void sort_3(stack *X)
{
	int i = 0;
	if (X->lenght <= 0)
		printf("\nverify length in sort\n");
	if (X->lenght > 1 && X->array_of_nums[0].index == X->array_of_nums[1].index + 1)
	{
		printf("s ");
		swap(X);
	}
	if (X->lenght > 2)
	{
		int n = get_distance(X->array_of_nums);
		if (n == 3)
		{
			printf("r ");
			rotate(X);
		}
		if (n == 5)
		{
			printf("rr ");
			reverse_rotate(X);
		}
		if (X->array_of_nums[0].index == X->array_of_nums[1].index + 1)
		{
			printf("s ");
			swap(X);
		}
	}
}
// solution for 4 - 6
void sort(stack *A, stack *B)
{
	int len_of_numbers_to_send_to_B = 0;
	len_of_numbers_to_send_to_B = A->lenght - 3;
	// printf("%d\n",len_of_numbers_to_send_to_B);
	int i = 0;
	while (i < A->lenght)
	{
		if (A->array_of_nums[0].index < len_of_numbers_to_send_to_B)
		{
			printf("p ");
			A->array_of_nums[0].index -= (A->lenght - 1); // to verify
			push(A, B);
		}
		if (A->array_of_nums[i].index < len_of_numbers_to_send_to_B)
		{
			if (i <= A->lenght / 2 + A->lenght % 2)
			{
				// up
				printf("r ");
				rotate(A);
				i = 0;
			}
			else if (i > A->lenght / 2 + A->lenght % 2)
			{
				// down
				printf("rr ");
				reverse_rotate(A);
				i = 0;
			}
		}
		i++;
	}
	sort_3(A);
	sort_3(B);
}

int main(void)
{
	int i;
	// int const_array[] = {0, 4, 11};
	// int const_array[] = {0, 11, 4};
	// int const_array[] = {4, 0, 11};
	// int const_array[] = {4, 11, 0};
	// int const_array[] = {11, 0, 4};
	int const_array[] = {1, 9, 2, 7, 0, 4};
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

	printf("A: ");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].value);
	printf("\n");
	////////////////////////////////////////////////////////////////////////////////
	sort(A, B);
	printf("\n============================\n");
	printf("A: ");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].value);
	printf("\n");
	printf("B: ");
	i = 0;
	while (i < B->lenght)
		printf("%4d ", B->array_of_nums[i++].value);
	printf("\n");
}