#include "../Libft/libft.h"

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

// rotate (up)
void rotate(stack *list, int len)
{
	num tmp = list->array_of_nums[0];
	ft_memmove(list->array_of_nums, list->array_of_nums + 1, (len - 1) * sizeof(num));
	list->array_of_nums[len - 1] = tmp;
}

// reverse rotate (down)
void reverse_rotate(stack *list, int len)
{
	num tmp = list->array_of_nums[len - 1];
	ft_memmove(list->array_of_nums + 1, list->array_of_nums, (len - 1) * sizeof(num));
	list->array_of_nums[0] = tmp;
}

// push
void push(stack *src, stack *dest)
{
	if (src->lenght)
	{
		num tmp = src->array_of_nums[0];
		rotate(src, src->lenght); // up
		src->lenght--;
		dest->lenght++;
		reverse_rotate(dest, dest->lenght); // down
		dest->array_of_nums[0] = tmp;
	}
	else
	{
		printf("\n\"verify src len in push\"\n");
	}
}

int main(void)
{
	int i;
	// int middle;

	int const_array[] = {3, 2, 14, 17, 13, 5, 26};
	int *array_of_indexes = ft_calloc(1, sizeof(const_array));
	int *array_of_numbers = ft_calloc(1, sizeof(const_array));
	int len = (int)(sizeof(const_array) / sizeof(int));

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
	printf("\nnumbers before sorting:\n");
	i = 0;
	while (i < len)
		printf("%4d ", array_of_numbers[i++]);
	sort_array(array_of_numbers, array_of_indexes, len);
	// get the middle number
	// middle = array_of_numbers[len / 2];
	// feed indexes
	i = 0;
	while (i < len)
	{
		A->array_of_nums[array_of_indexes[i]].index = i;
		i++;
	}
	printf("\n\nnumbers after sorting:\n");
	i = 0;
	while (i < len)
		printf("%4d ", array_of_numbers[i++]);
	printf("\n\nindexes after sorting:\n");
	i = 0;
	while (i < len)
		printf("%4d ", array_of_indexes[i++]);
	printf("\n\nstack A:\n");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].value);
	printf("\n");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].index);
	printf("\n\nstack B:\n");
	i = 0;
	while (i < B->lenght)
		printf("%4d ", B->array_of_nums[i++].value);

	// test rotate, reverse rotate and push
	printf("\n\nA: ");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].value);
	printf("\nB: ");
	i = 0;
	while (i < B->lenght)
		printf("%4d ", B->array_of_nums[i++].value);
	/////////////////////////////////////////////////////
	// printf("\nA's lenght %d\nB's lenght %d\n", A->lenght, B->lenght);
	push(A, B);
	printf("\n\nA: ");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].value);
	printf("\nB: ");
	i = 0;
	while (i < B->lenght)
		printf("%4d ", B->array_of_nums[i++].value);
	push(A, B);
	printf("\n\nA: ");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].value);
	printf("\nB: ");
	i = 0;
	while (i < B->lenght)
		printf("%4d ", B->array_of_nums[i++].value);
	push(A, B);
	printf("\n\nA: ");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].value);
	printf("\nB: ");
	i = 0;
	while (i < B->lenght)
		printf("%4d ", B->array_of_nums[i++].value);
	push(A, B);
	printf("\n\nA: ");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].value);
	printf("\nB: ");
	i = 0;
	while (i < B->lenght)
		printf("%4d ", B->array_of_nums[i++].value);
	push(A, B);
	printf("\n\nA: ");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].value);
	printf("\nB: ");
	i = 0;
	while (i < B->lenght)
		printf("%4d ", B->array_of_nums[i++].value);
	push(A, B);
	printf("\n\nA: ");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].value);
	printf("\nB: ");
	i = 0;
	while (i < B->lenght)
		printf("%4d ", B->array_of_nums[i++].value);
	push(A, B);
	printf("\n\nA: ");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].value);
	printf("\nB: ");
	i = 0;
	while (i < B->lenght)
		printf("%4d ", B->array_of_nums[i++].value);
	push(B, A);
	printf("\n\nA: ");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].value);
	printf("\nB: ");
	i = 0;
	while (i < B->lenght)
		printf("%4d ", B->array_of_nums[i++].value);
	printf("\n\n");
}