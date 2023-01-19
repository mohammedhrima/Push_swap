#include "Libft/libft.h"
int moves = 0;

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

typedef struct number
{
	int next;
	int value;
	int prev;
} num;

// push number *from one stack to another
void push(num ***from, int *dest, int *len)
{
	moves++;
	static int i;
	int j = 0;
	if (*len)
	{
		int value = (*from)[0]->value;
		ft_memmove(*from, *from + 1, (*len - 1) * sizeof(num **));
		dest[--(*len)] = value;
		while (j < *len)
		{
			if (j + (*from)[j]->next > (*len))
				(*from)[j]->next--;
			if ((*from)[j]->next < 0)
				(*from)[j]->next += (*len);
			(*from)[j]->prev = *len - (*from)[j]->next;
			j++;
		}
		i++;
	}
	else
	{
		printf("verify len in push\n");
	}
}

// rotate stack (up)
void rotate(num ***arr, int len)
{
	moves++;
	int i = 0;
	if (len)
	{
		num *tmp = (*arr)[0];
		ft_memmove(*arr, *arr + 1, (len) * sizeof(num **)); // check ft_memmove(*arr, *arr + 1, (len - 1) * sizeof(num));
		(*arr)[len - 1] = tmp;
		i = 0;
		while (i < len)
		{
			if ((*arr)[i]->next == len)
				(*arr)[i]->next = 0;
			(*arr)[i]->next++;
			(*arr)[i]->prev = len - (*arr)[i]->next;
			i++;
		}
	}
	else
	{
		printf("verify len in rotate\n");
	}
}

// reverse rotate stack (down)
void reverse_rotate(num ***arr, int len)
{
	moves++;
	int i = 0;
	if (len)
	{
		num *tmp = (*arr)[len - 1];
		ft_memmove(*arr + 1, *arr, (len) * sizeof(num **));
		(*arr)[0] = tmp;
		i = 0;
		while (i < len)
		{
			if ((*arr)[i]->prev == len)
				(*arr)[i]->prev = 0;
			(*arr)[i]->prev++;
			(*arr)[i]->next = len - (*arr)[i]->prev;
			i++;
		}
	}
	else
	{
		printf("verify len in reverse rotate\n");
	}
}

void swap(num **current, num **next, int len)
{
	// printf("%d: +%d -%d\n", (*current)->value, (*current)->next, (*current)->prev);
	// printf("%d: +%d -%d\n", (*next)->value, (*next)->next, (*next)->prev);
	printf("\nswap\n");
	moves++;
	num *tmp = *current;
	*current = *next;
	*next = tmp;
	if ((*current)->next == len)
		(*current)->next = 0;
	(*current)->next++;
	(*current)->prev = len - (*current)->next;

	if ((*next)->prev == len)
		(*next)->prev = 0;
	(*next)->prev++;
	(*next)->next = len - (*next)->prev;
}

// choose move
int choose_move(num **list, int *len, int *stack_b)
{
	printf("\n============================================================\n");
	int i = 0;
	int step_prev = -1, step_next = -1;
	// printf("%d, %d", list[0]->value, list[1]->value);
	// exit(0);
	while (i < *len)
	{
		if (*len > 0 && list[0]->value == list[1]->value - 1)
			swap(list, list + 1, *len);
		if (list[0]->prev == 0 || list[0]->next == 0)
		{
			printf("\npush %d to stack b\n", list[0]->value);
			push(&list, stack_b, len);
		}
		if (i - list[i]->prev == 0 || i + list[i]->next == *len)
		{
			printf("\nmove %d ,%d step, to the left\n", list[i]->value, list[i]->prev);
			step_next = list[i]->next;
			step_prev = list[i]->prev;
		}
		if (*len > 0 && list[0]->value == list[1]->value - 1)
			swap(list, list + 1, *len);
		i++;
	}
	if (step_next <= step_prev && *len > 0)
	{
		printf("reverse rotate\n");
		reverse_rotate(&list, *len);
		return (0);
	}
	if (step_next > step_prev && *len > 0)
	{
		printf("rotate\n");
		rotate(&list, *len);
		return (0);
	}
	return (1);
}
// -> +
// <- -
int main(void)
{
	// verify array of 3 elements
	int i;
	int array0[] = {2, 1, 4, 3, 6};
	int *array1 = ft_calloc(1, sizeof(array0)); // copy array0 in array1
	int *stack_b = ft_calloc(1, sizeof(array0));
	int *indexes = ft_calloc(1, sizeof(array0));	 // indexes container
	int *moves_to_do = ft_calloc(1, sizeof(array0)); // moves to do
	int len = (int)(sizeof(array0) / sizeof(int));
	int push_len = (int)(sizeof(array0) / sizeof(int));
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
		if (moves_to_do[i] <= 0)
		{
			list[i]->prev = -(moves_to_do[i]);
			list[i]->next = len + moves_to_do[i];
		}
		else if (moves_to_do[i] > 0)
		{
			list[i]->next = moves_to_do[i];
			list[i]->prev = len - moves_to_do[i];
		}
		i++;
	}
	printf("\n======in main======\n");
	i = 0;
	while (i < len)
	{
		printf("%d: +%d -%d | ", list[i]->value, list[i]->next, list[i]->prev);
		i++;
	}
	printf("\n\n");
	//////////////////////////////////////////////////////////////////
	// swap(list, list + 1);
	// printf("\nafter swap\n");
	// i = 0;
	// while (i < len)
	// {
	// 	printf("%d: +%d -%d | ", list[i]->value, list[i]->next, list[i]->prev);
	// 	i++;
	// }
	while (choose_move(list, &len, stack_b) == 0)
	{
		i = 0;
		while (i < len)
		{
			printf("%d: +%d -%d | ", list[i]->value, list[i]->next, list[i]->prev);
			i++;
		}
		printf("\n");
		i = 0;
		while (i < push_len)
		{
			printf("%d ", stack_b[i]);
			i++;
		}
		printf("\n");
	}
	printf("\n============================================================\n");
	printf("number of moves: %d\n", moves);
}
