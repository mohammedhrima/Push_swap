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

#if 1
void sort_stacks(stack *A, stack *B, int middle_index)
{
	int i = 0;
	int j = 0;
	printf("\nmiddle index : %d \n", middle_index);
	while (i < middle_index)
	{
		if (A->array_of_nums[0].index >= middle_index)
		{
			// printf("\npush(%d) \n", A->array_of_nums[0].value);
			push(A, B);
			j = 0;
			// while (j < A->lenght)
			// 	printf("%d ", A->array_of_nums[j++].value);
			// printf("\n");
			i++;
		}
		j = 0;
		while (j < A->lenght && A->array_of_nums[0].index < middle_index)
		{
			// printf("\n\"%d | %d\"\n", A->array_of_nums[j].value, A->array_of_nums[A->lenght - j - 1].value);
			if (A->array_of_nums[j].index > middle_index)
			{
				// printf("r(%d) ", A->array_of_nums[j].value);
				rotate(A); // up
				moves++;
				break;
			}
			if (A->array_of_nums[A->lenght - j - 1].index > middle_index)
			{
				// printf("rr(%d) ", A->array_of_nums[j].value);
				reverse_rotate(A); // down
				moves++;
				break;
			}
			j++;
		}
	}
}
#else
void sort_stacks(stack *A, stack *B, int middle_index)
{
	int i = 0;
	printf("\nmiddle index : %d \n", middle_index);
	while (i < middle_index)
	{
		if (A->array_of_nums[0].index >= middle_index)
		{
			push(A, B);
			i++;
		}
		rotate(A);
		moves++;
	}
}
#endif
int main(void)
{
	int i;
	// int middle;

	int const_array[] = {101, 0, 102, 3, 4, 25, 1, 15, 10, 13, 2, 5, 100, 26, 11};
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
	printf("\n");
	sort_array(array_of_numbers, array_of_indexes, len);
	printf("\n");

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
	sort_stacks(A, B, len / 2);
	printf("\n\nA: ");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].value);
	printf("\nB: ");
	i = 0;
	while (i < B->lenght)
		printf("%4d ", B->array_of_nums[i++].value);
	printf("\n\nnumber of moves %d\n", moves);
	/////////////////////////////////////////////////////

	printf("\n\n");
}