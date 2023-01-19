#include <stdio.h>

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void sort_array(int *arr, int len)
{
	int i, j;
	i = 0;
	j = 0;
	while (j < len)
	{
		i = len - 1;
		while (i > j)
		{
			if (arr[j] > arr[i])
				swap(arr + j, arr + i);
			i--;
		}
		j++;
	}
}

int main(void)
{
	int arr1[] = {12, 11, 13, 5, 6, 7,0};
	int i = 0;
	sort_array(arr1, sizeof(arr1)/sizeof(int));
	while (i < sizeof(arr1) / sizeof(int))
	{
		printf("%d ", arr1[i]);
		i++;
	}
}