#include "Libft/libft.h"

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

// rotate stack
void rotate(num **arr, int len)
{
	int i = 0;
	num *tmp = arr[0];
	ft_memmove(arr, arr + 1, (len - 1) * sizeof(*arr));
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

// reverse rotate stack
void reverse_rotate(num **arr, int len)
{
	int i = 0;
	num *tmp = arr[len - 1];
	ft_memmove(arr + 1, arr, (len - 1) * sizeof(*arr));
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

// push number *from one stack to another
void push(num ***from, int *dest, int *len)
{
	static int i;
	int j = 0;
	printf("in push: \nfrom: ");
	while (j < *len)
	{
		printf("%d ", (*from)[j]->value);
		j++;
	}

	int value = (*from)[0]->value;
	ft_memmove(*from, *from + 1, *len);
	// num **tmp = (num **)malloc((*len) * sizeof(num *));
	// ft_memcpy(tmp, *from + sizeof(num**), *len);
	j = 0;
	// printf("\nin push: \ntmp: ");
	// while (j < *len - 1)
	// {
	// 	tmp[j] = (*from)[j + 1];
	// 	// tmp[j]->prev--;
	// 	j++;
	// }
	//(*len)--;
	dest[i] = value;
	i++;
	// free(dest);
	// free(*from);
	//*from = tmp;
}

int choose_move(num **list, int *len, int *stack_b) // to get the shortest path to dest
{
	int i = 0;
	int step_prev, step_next, the_index = -1;
	while (i < *len)
	{
		if (list[0]->prev == 0 || list[0]->next == *len)
		{
			printf("\n\npush to stack b\n");
			push(&list, stack_b, len);
			printf("\n\nafter pushing\n");
			int j = 0;
			while (j < *len)
			{
				if (j + list[j]->next > *len) // to check
					list[j]->next -= 1;
				if (j - list[j]->prev < 0) // to check
					list[j]->prev -= 1;
				printf("%2d: +%d -%d | ", list[j]->value, list[j]->next, list[j]->prev);
				j++;
			}
			printf("\n\nstack b\n");
			j = 0;
			while (j < 7)
			{
				printf("%d ", stack_b[j]);
				j++;
			}
			// exit(0);
		}
		if (i - list[i]->prev == 0)
		{
			the_index = i;
			printf("\n\nmove %d ,%d step, to the left\n", list[i]->value, list[i]->prev);
			step_prev = list[i]->prev;
		}
		if (i + list[i]->next == *len)
		{
			the_index = i;
			printf("\n\nmove %d ,%d step, to the right\n", list[i]->value, list[i]->next);
			step_next = list[i]->next;
		}
		i++;
	}
	if (step_next <= step_prev)
	{
		printf("\n\nrotate\n");
		// i = 0;
		// while (i < *len)
		// {
		// 	printf("%2d: +%d -%d\n", list[i]->value, list[i]->next, list[i]->prev);
		// 	i++;
		// }
		rotate(list, *len);
		printf("after rotate\n");
		i = 0;
		while (i < *len)
		{
			printf("%2d: +%d -%d | ", list[i]->value, list[i]->next, list[i]->prev);
			i++;
		}
		return (0);
	}
	else if (step_next > step_prev)
	{
		printf("\n\nreverse rotate\n");
		reverse_rotate(list, *len);
		printf("after reverse rotate\n");
		i = 0;
		while (i < *len)
		{
			printf("%2d: +%d -%d | ", list[i]->value, list[i]->next, list[i]->prev);
			i++;
		}
		return (0);
	}
	else
	{
		printf("\n\n\"verify choose_move\"\n");
	}
	return (1);
}

int main(void)
{
	int i;
	int array0[] = {32, 11, 13, 5, 6, 7, 25};
	int *array1 = ft_calloc(1, sizeof(array0)); // copy array0 in array1
	int *stack_b = ft_calloc(1, sizeof(array0));
	int *indexes = ft_calloc(1, sizeof(array0));	 // indexes container
	int *moves_to_do = ft_calloc(1, sizeof(array0)); // moves to do
	int len = (int)(sizeof(array0) / sizeof(int));
	ft_memcpy(array1, array0, sizeof(array0));

	i = 0;
	while (i < len)
	{
		indexes[i] = i;
		i++;
	}

	num **list = ft_calloc(len + 1, sizeof(void *));
	i = 0;
	while (i < len)
	{
		list[i] = ft_calloc(1, sizeof(num));
		i++;
	}

	i = 0;
	printf("array of numbers:\n");
	while (i < len)
	{
		printf("%4d ", array0[i]);
		i++;
	}
	sort_array(array0, indexes, len);
	i = 0;
	while (i < len)
	{
		moves_to_do[indexes[i]] = i - indexes[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		list[i]->value = array1[i];
		if (moves_to_do[i] < 0)
		{
			list[i]->prev = -(moves_to_do[i]);
			list[i]->next = len + moves_to_do[i];
		}
		else if (moves_to_do[i] > 0)
		{
			list[i]->next = moves_to_do[i];
			list[i]->prev = len - moves_to_do[i];
		}
		else
		{
			list[i]->prev = moves_to_do[i]; //+ len - 1;
			list[i]->next = moves_to_do[i]; //+ len - 1;
		}
		i++;
	}
	printf("\n\n======in main======\n");
	i = 0;
	while (i < len)
	{
		printf("%2d: +%d -%d | ", list[i]->value, list[i]->next, list[i]->prev);
		i++;
	}
	// while (choose_move(list, &len, stack_b) == 0)
	// {
	// 	;
	// }
	choose_move(list, &len, stack_b);
	// choose_move(list, &len, stack_b);
	// choose_move(list, &len, stack_b);

	// printf("\n\nstack b\n");
	// i = 0;
	// while (i < 7)
	// {
	// 	printf("%d ", stack_b[i]);
	// 	i++;
	// }
	printf("\n");
}