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
void reverse_rotate(int *arr, int len)
{
	if (len > 1)
	{
		int tmp = arr[len - 1];
		ft_memmove(arr + 1, arr, (len) * sizeof(int));
		arr[0] = tmp;
	}
}

// rotate (up)
void rotate(int *arr, int len)
{
	if (len > 1)
	{
		int tmp = arr[0];
		ft_memmove(arr, arr + 1, (len) * sizeof(int));
		arr[len - 1] = tmp;
	}
}
// choose move , it sorts depends on array of index_start 0,1,2,3,....
// it sorts regulary from bigger to smaller
int choose_move(int *arr, int len)
{

}

// -> +
// <- -
int main(void)
{
	// init array of numbers
	// verify cinflit between array0 and array1
	int i;
	// int array0[] = {13, 24, 14};
	// int array0[] = {13, 14, 24};
	// int array0[] = {14, 24, 13};
	// int array0[] = {13, 14, 24};
	// int array0[] = {24, 13, 14};
	int array0[] = {24, 14, 13};

	int *array1 = ft_calloc(1, sizeof(array0));	   // used to copy array0 in heap
	int len = (int)(sizeof(array0) / sizeof(int)); // len of array0
	int push_len = len;							   // copy of len
	ft_memcpy(array1, array0, sizeof(array0));	   // copy array0 to the heap (in array1)
	// create stack b
	int *stack_b = ft_calloc(1, sizeof(array0));
	// index of elements in array of numbers (index container)
	int *index_start = ft_calloc(1, sizeof(array0));
	int *index_end = ft_calloc(1, sizeof(array0));
	i = 0;
	while (i < len)
	{
		index_start[i] = i;
		index_end[i] = i;
		i++;
	}
	// array of moves to do
	int *moves_to_do = ft_calloc(1, sizeof(array0));
	// check copied numbers in heap
	printf("array of numbers:\n");
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
	printf("\n======in main======\n");
	printf("+ index after sorting: \n");
	i = 0;
	while (i < len)
	{
		printf("%4d ", index_start[i]);
		i++;
	}
	printf("\n\n");
	i = 0;
	while (i < len)
	{
		printf("%4d should go to %4d\n", index_end[index_start[i]], i);
		i++;
	}
	printf("\n");
	// i = 0;
	// while (i < len)
	// {
	// 	printf("%d ", array1[i]);
	// 	i++;
	// }
	// printf("\n");
	// exit(0);
	choose_move(array1, len);
	i = 0;
	while (i < len)
	{
		printf("%d ", array1[i]);
		i++;
	}
	printf("\n");
	choose_move(array1, len);
	i = 0;
	while (i < len)
	{
		printf("%d ", array1[i]);
		i++;
	}
	printf("\n");
	choose_move(array1, len);
	choose_move(array1, len);
	choose_move(array1, len);


}
