#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct number
{
	int next;
	int value;
	int prev;
} num;

void swap_array(int *x, int *y)
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
				swap_array(arr + j, arr + i);
				swap_array(indexes + j, indexes + i);
			}
			i--;
		}
		j++;
	}
}

// int absolute_move(int n)
// {
// 	if (n < 0)
// 		return -n;
// 	return n;
// }

// push number *from one stack to another
void push(num ***from, int *dest, int *len)
{
	static int i;
	int j = 0;
	printf("\nin push: \nfrom: ");
	while (j < *len)
	{
		printf("%d ", (*from)[j]->value);
		j++;
	}

	int value = (*from)[0]->value;
	num **tmp = malloc((*len) * sizeof(void **));
	memcpy(tmp, *from + 1, *len);
	j = 0;
	// printf("\nin push: \ntmp: ");
	while (j < *len - 1)
	{
		tmp[j] = (*from)[j + 1];
		//tmp[j]->prev--;

		j++;
	}
	(*len)--;
	dest[i] = value;
	i++;
	// free(dest);
	//free(*from);
	*from = tmp;
}

// reverse rotate stack
void reverse_rotate(num **arr, int len)
{
	int i = 0;
	num *tmp = arr[len - 1];
	memmove(arr + 1, arr, (len - 1) * sizeof(*arr));
	arr[0] = tmp;
	i = 0;
	while (i < len)
	{
		arr[i]->prev += 1;
		arr[i]->next -= 1;
		// to check after
		if (arr[i]->prev > len)
			arr[i]->prev %= len;
		if (arr[i]->next < 0)
			arr[i]->next += len;
		i++;
	}
}

// rotate stack
void rotate(num **arr, int len)
{
	int i = 0;
	num *tmp = arr[0];
	memmove(arr, arr + 1, (len - 1) * sizeof(*arr));
	arr[len - 1] = tmp;
	i = 0;
	while (i < len)
	{
		arr[i]->next += 1;
		arr[i]->prev -= 1;
		// to check after
		if (arr[i]->next > len)
			arr[i]->next %= len;
		if (arr[i]->prev < 0)
			arr[i]->prev += len;
		i++;
	}
}

void choose_move(num **list, int *len, int *stack_b) // to get the sg=hortest path to dest
{
	int i = 0;
	int step_prev, step_next, the_index = -1;

	while (i < *len)
	{
		if (list[0]->prev == 0 || list[0]->next == *len)
		{
			printf("push to stack b\n");
			push(&list, stack_b, len);
		}
		if (i - list[i]->prev == 0)
		{
			the_index = i;
			printf("\nmove %d ,%d step, to the left\n", list[i]->value, list[i]->prev);
			step_prev = list[i]->prev;
		}
		if (i + list[i]->next == *len)
		{
			the_index = i;
			printf("\nmove %d ,%d step, to the right\n", list[i]->value, list[i]->next);
			step_next = list[i]->next;
		}
		i++;
	}
	if (step_next < step_prev)
	{
		printf("\nrotate\n");
		i = 0;
		while (i < *len)
		{
			printf("%2d: +%d -%d\n", list[i]->value, list[i]->next, list[i]->prev);
			i++;
		}
		rotate(list, *len);
		printf("\n\nafter rotate\n");
		i = 0;
		while (i < *len)
		{
			printf("%2d: +%d -%d\n", list[i]->value, list[i]->next, list[i]->prev);
			i++;
		}
	}
	else
	{
		printf("\nbefore reverse rotate\n");
		i = 0;
		while (i < *len)
		{
			printf("%2d: +%d -%d\n", list[i]->value, list[i]->next, list[i]->prev);
			i++;
		}
		reverse_rotate(list, *len); // put it in while loop, loop throw how much steps to do
		// push(&list, stack_b, len);
		printf("\n\nafter reverse rotate\n");
		i = 0;
		while (i < *len)
		{
			printf("%2d: +%d -%d\n", list[i]->value, list[i]->next, list[i]->prev);
			i++;
		}
	}
}

int main(void)
{
	int i = 0;
	int arr[] = {24, 11, 13, 5, 6, 7, 1};
	int *arr0 = malloc(sizeof(arr));
	int *stack_b = malloc(sizeof(arr));
	memset(stack_b, 0, sizeof(arr));
	memcpy(arr0, arr, sizeof(arr));
	/////////////////////////////////

	int indexes[] = {0, 1, 2, 3, 4, 5, 6};
	int moves_to_do[] = {0, 0, 0, 0, 0, 0};
	int len = (int)(sizeof(arr) / sizeof(int));
	num **list = malloc((len + 1) * sizeof(void *));

	i = 0;
	while (i < len)
	{
		list[i] = malloc(sizeof(num));
		memset(list[i], 0, sizeof(num));
		i++;
	}

	i = 0;
	printf("array of numbers:\n");
	while (i < len)
	{
		printf("%4d ", arr[i]);
		i++;
	}
	sort_array(arr, indexes, len);
	i = 0;
	while (i < len)
	{
		moves_to_do[indexes[i]] = i - indexes[i];
		i++;
	}

	i = 0;
	while (i < len)
	{
		list[i]->value = arr0[i];
		if (moves_to_do[i] < 0)
		{
			list[i]->prev = -(moves_to_do[i]);
			list[i]->next = len + moves_to_do[i];
		}
		else if (moves_to_do[i] > 0)
		{
			list[i]->next = moves_to_do[i];
			list[i]->prev = -(moves_to_do[i] - len);
		}
		else
		{
			list[i]->prev = moves_to_do[i]; //+ len - 1;
			list[i]->next = moves_to_do[i]; //+ len - 1;
		}
		i++;
	}
	printf("\n\n");
	i = 0;
	while (i < len)
	{
		printf("%2d: +%d -%d\n", list[i]->value, list[i]->next, list[i]->prev);
		i++;
	}
	printf("\n");
	choose_move(list, &len, stack_b);
	printf("\n");
}