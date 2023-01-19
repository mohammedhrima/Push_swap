#include "../Libft/libft.h"
#include <string.h>

// struct
typedef struct number
{
	int value;
	int index; // where it should go
} num;

// swap
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

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
	if (arr[0] > arr[1] && arr[1] > arr[2])
		return (0);
	if (arr[0] < arr[1] && arr[0] > arr[2])
	{
		printf("swap 0\n");
		swap(arr, arr + 1);
		return (0);
	}
	if (arr[2] < arr[1] || arr[0] < arr[2])
	{
		printf("rotate (up)\n");
		rotate(arr, len); // down
		if (arr[0] < arr[1])
		{
			printf("swap 1\n");
			swap(arr, arr + 1);
			return (0);
		}
		return (0);
	}
	if (arr[1] < arr[2] || arr[2] > arr[1])
	{
		printf("reverse rotate (down)\n");
		reverse_rotate(arr, len); // down
		if (arr[0] < arr[1])
		{
			printf("swap 2\n");
			swap(arr, arr + 1);
			return (0);
		}
		return (0);
	}
	return (0);
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
}
