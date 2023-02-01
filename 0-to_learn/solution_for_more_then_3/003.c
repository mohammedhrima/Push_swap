#include "../Libft/libft.h"
#include <string.h>

void swap_array(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
void sort_array(int *arr, int *index_start, int len)
{
	int i, j, tmp1, tmp2;
	i = 0;
	j = 0;
	while (j < len)
	{
		i = len - 1;
		while (i > j)
		{
			if (arr[j] < arr[i])
			{
				swap_array(arr + j, arr + i);
				swap_array(index_start + j, index_start + i);
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

// reverse rotate (down)
void reverse_rotate(num **arr, int len)
{
	if (len > 1)
	{
		num *tmp = arr[len - 1];
		ft_memmove(arr + 1, arr, len * sizeof(num *));
		arr[0] = tmp;
	}
	else
		printf("verify len in reverse rotate\n");
}

// rotate (up)
void rotate(num **arr, int len)
{
	if (len > 1)
	{
		num *tmp = arr[0];
		ft_memmove(arr, arr + 1, len * sizeof(num *));
		(arr)[len - 1] = tmp;
	}
	else
		printf("verify len in rotate\n");
}

// swap
void swap(num **num1, num **num2)
{
	printf("\nswap\n");
	num *tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

// push
void push(num **src, num **dest, int len)
{

	if (len > 3)
	{
		num *value = (src)[0];
		ft_memmove(src, src + 1, (len - 1) * sizeof(num *));
		ft_memmove(dest + 1, dest, (len - 1) * sizeof(num *));
		(dest)[0] = value;
		src[len - 1] = NULL;
	}
	else
	{
		printf("verify len in push\n");
	}
}

// choose move , it sorts depends on array of index_start 0,1,2,3,....
// it sorts regulary from bigger to smaller
int choose_move(num **stack_a, num **stack_b, int len)
{
	int i = 0;
	while (i < len)
	{
		printf("| %2d, from %2d to %2d |\n", stack_a[i]->value, i, stack_a[i]->index);
		if (i < len / 2)
		{
			// stack a
		}
		else
		{
			// stack b
			push(stack_a + i, stack_b, len / 2);
		}
		i++;
	}
	return (0);
}

// -> +
// <- -
int main(void)
{
	// init array of numbers
	// verify conflit between array0 and array1
	int i;
	int array0[] = {13, 24, 14, 12, 3, 5, 26};
	int *array1 = ft_calloc(1, sizeof(array0));	   // used to copy array0 in heap
	int len = (int)(sizeof(array0) / sizeof(int)); // len of array0
	int push_len = len;							   // copy of len
	ft_memcpy(array1, array0, sizeof(array0));	   // copy array0 to the heap (in array1)

	// index of elements in array of numbers (index container)
	int *index_start = ft_calloc(1, sizeof(array0));
	// int *index_end = ft_calloc(1, sizeof(array0));
	// array of structs
	num **stack_a = ft_calloc(len + 1, sizeof(void *));
	num **stack_b = ft_calloc(len + 1, sizeof(void *));

	// feed arrays with data
	i = 0;
	while (i < len)
	{
		index_start[i] = i;
		i++;
	}
	// array of moves to do
	int *moves_to_do = ft_calloc(1, sizeof(array0));
	// check copied numbers in heap
	printf("numbers:\n");
	i = 0;
	while (i < len)
	{
		printf("%4d ", array0[i]);
		i++;
	}
	printf("\n");
	// sort array0 to get moves made to sort numbers
	// (index_start will be change depends on array0)
	sort_array(array0, index_start, len);
	printf("\n==========in main==========\n");
	printf("+ index_start after sorting: \n");
	i = 0;
	while (i < len)
	{
		printf("%4d ", index_start[i]);
		i++;
	}
	printf("\n\n");
	// exit(0);
	i = 0;
	while (i < len)
	{
		//	printf("%4d should go to %4d\n", array1[index_start[i]], i);
		stack_a[index_start[i]] = ft_calloc(1, sizeof(num));
		stack_a[index_start[i]]->index = i;
		stack_a[index_start[i]]->value = array1[index_start[i]];
		i++;
	}
	printf("\n==========end main==========\n");
	choose_move(stack_a, stack_b, push_len);
}
