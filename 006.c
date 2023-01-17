#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void sort_array(int *arr, int *indexes, int len)
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
				swap(arr + j, arr + i);
				swap(indexes + j, indexes + i);
			}
			i--;
		}
		j++;
	}
}

typedef struct number
{
	int next;
	int value;
	int prev;
} num;

int main(void)
{
	int i = 0;
	int arr1[] = {12, 11, 13, 5, 6, 7, 0};
	int arr[] = {12, 11, 13, 5, 6, 7, 0};
	int indexes[] = {0, 1, 2, 3, 4, 5, 6};
	int moves_to_do[] = {0, 0, 0, 0, 0, 0};
	num *list[7];

	i = 0;
	while (i < 7)
	{
		list[i] = malloc(sizeof(num));
		memset(list[i], 0, sizeof(num));
		i++;
	}

	i = 0;
	printf("array of numbers:\n");
	while (i < sizeof(arr) / sizeof(int))
	{
		printf("%4d ", arr[i]);
		i++;
	}
	// printf("\n\nindexes of numbers:\n");
	// i = 0;
	// while (i < sizeof(arr) / sizeof(int))
	// {
	// 	printf("%4d ", i);
	// 	i++;
	// }
	// printf("\n========================================");
	sort_array(arr, indexes, sizeof(arr) / sizeof(int));
	// printf("\n\narray of numbers after sorting:\n");
	// i = 0;
	// while (i < sizeof(arr) / sizeof(int))
	// {
	// 	printf("%4d ", arr[i]);
	// 	i++;
	// }
	// printf("\n\nindexes of numbers after sorting:\n");
	// i = 0;
	// while (i < sizeof(arr) / sizeof(int))
	// {
	// 	printf("%4d ", indexes[i]);
	// 	i++;
	// }
	// printf("\n========================================");
	// printf("\n\nmoves made:\n");
	// i = 0;
	// while (i < sizeof(arr) / sizeof(int))
	// {
	// 	printf("%4d ", i - indexes[i]);
	// 	i++;
	// }
	// printf("\n========================================");
	// printf("\n\nmoves to do:\n");
	i = 0;
	while (i < sizeof(arr) / sizeof(int))
	{
		moves_to_do[indexes[i]] = i - indexes[i];
		i++;
	}
	// printf("->\n");
	// i = 0;
	// while (i < sizeof(arr) / sizeof(int))
	// {
	// 	if (moves_to_do[i] < 0)
	// 		printf("%4d ", (int)(sizeof(arr) / sizeof(int)) + moves_to_do[i]);
	// 	else
	// 		printf("%4d ", moves_to_do[i]);
	// 	i++;
	// }
	// printf("\n");
	// printf("<-\n");
	// i = 0;
	// while (i < sizeof(arr) / sizeof(int))
	// {
	// 	if (moves_to_do[i] > 0)
	// 		printf("%4d ", -(moves_to_do[i] - (int)(sizeof(arr) / sizeof(int))));
	// 	else
	// 		printf("%4d ", -(moves_to_do[i]));
	// 	i++;
	// }
	i = 0;
	while (i < 7)
	{
		list[i]->value = arr1[i];
		if (moves_to_do[i] < 0)
		{
			list[i]->prev = -(moves_to_do[i]);
			list[i]->next = (int)(sizeof(arr) / sizeof(int)) + moves_to_do[i];
		}
		else if (moves_to_do[i] > 0)
		{
			list[i]->next = moves_to_do[i];
			list[i]->prev = -(moves_to_do[i] - (int)(sizeof(arr) / sizeof(int)));
		}
		else
		{
			list[i]->prev = moves_to_do[i];
			list[i]->next = moves_to_do[i];
		}
		i++;
	}
	printf("\n\n");
	i = 0;
	while (i < 7)
	{
		printf("%2d: +%d -%d\n", list[i]->value, list[i]->next, list[i]->prev);
		i++;
	}
	printf("\n\n");
}