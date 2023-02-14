#include "../../Libft/libft.h"
#include <signal.h>

void swap_array(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void mysleep(int time)
{
	float q = 0.001;
	while (q < time * 10000)
		q += 0.002;
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

void check_repetetive_numbers(int *array, int len)
{
	int i = 0;
	int j = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] == array[j])
			{
				ft_printf("Error: there is repetetive number\n");
				exit(0);
			}
			j++;
		}
		i++;
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

// functions
//  rotate (up)
int rotate(stack *list)
{
	if (list->lenght > 1)
	{
		num tmp = list->array_of_nums[0];
		ft_memmove(list->array_of_nums, list->array_of_nums + 1, (list->lenght - 1) * sizeof(num));
		list->array_of_nums[list->lenght - 1] = tmp;
		return (1);
	}
	return (0);
}

// reverse rotate (down)
int reverse_rotate(stack *list)
{
	if (list->lenght > 1)
	{
		num tmp = list->array_of_nums[list->lenght - 1];
		ft_memmove(list->array_of_nums + 1, list->array_of_nums, (list->lenght - 1) * sizeof(num));
		list->array_of_nums[0] = tmp;
		return (1);
	}
	return (0);
}

// push
int push(stack *src, stack *dest)
{
	if (src->lenght)
	{
		num tmp = src->array_of_nums[0];
		rotate(src); // up
		src->lenght--;
		dest->lenght++;
		reverse_rotate(dest); // down
		dest->array_of_nums[0] = tmp;
		return (1);
	}
	else
	{
		ft_printf("\n\"verify src len in push\"\n");
		return (0);
	}
}

// swap
int swap(stack *X)
{
	num tmp = X->array_of_nums[0];
	X->array_of_nums[0] = X->array_of_nums[1];
	X->array_of_nums[1] = tmp;
	return (1);
}

char **string(void)
{
	static char *str;

	return (&str);
}

// int **array_of_numbers(void)
// {
// 	static int *numbers;

// 	return (&numbers);
// }

// stack **stack_ptr(int index)
// {
// 	static stack **ptr;
// 	if (ptr == NULL)
// 		ptr = malloc(2 * sizeof(stack *));
// 	if (index == 'A')
// 		return (ptr[0]);
// 	if (index == 'B')
// 		return (ptr[1]);

// 	return (NULL);
// }

char *readline(int fd)
{
	int i = 0;
	int j = 0;
	char *res;
	char *tmp;

	char c[1];
	res = NULL;
	tmp = NULL;
	j = read(fd, c, 1);
	while (j && *c != '\n')
	{
		tmp = ft_strjoin(res, c);
		free(res);
		res = tmp;
		j = read(fd, &c, 1);
		if (j == 0)
			break;
		;
		i++;
		res[i] = '\0';
	}

	// if (i && res)
	// 	res[i] = '\0';
	// if (i > 1)
	// {
	// 	res = ft_strjoin(res, " ");
	// }
	return (res);
}

void is_sorted(stack *A)
{
	int i = 1;
	while (i < A->lenght)
	{
		if (A->array_of_nums[i].index > A->array_of_nums[i - 1].index)
			ft_printf("\033[0;31mwa elchriff verify dakchi 3endek\n");
		i++;
	}
}

int main(int argc, char **argv)
{
	int i = 2;
	char *str;
	if (argc < 2)
	{
		ft_printf(" please provide more arguments\n");
		exit(0);
	}
	// signal(SIGINT, handle_signal);

	str = argv[1];
	while (i < argc)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		i++;
	}

	char **array = ft_split(str, ' ');
	// int *array_of_numbers;

	i = 0;
	int j;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (!ft_isdigit(array[i][j++]))
			{
				ft_printf("verify that there is only numbers\n");
				exit(1);
			}
		}
		i++;
	}

	i = 0;
	// ft_printf("/");
	// while (array[i])
	// {
	// 	// ft_printf("|%s|", array[i]);
	// 	i++; //
	// }
	// ft_printf("/\n");
	/////////////////////////////////////////////////////////////////
	int len;
	len = i;
	len = ft_arrlen(array);
	// allocate needed memory for array of numbers ,indexes  and feed them
	int *array_of_numbers = my_malloc((len + 1) * sizeof(int));
	int *array_of_indexes = my_malloc((len + 1) * sizeof(int));
	char **array_of_moves;
	i = 0;
	while (i < len)
	{
		array_of_numbers[i] = ft_atoi(array[i]);
		i++;
	}
	i = 0;
	// ft_printf("|");
	// while (i < len)
	// {
	// 	ft_printf("|%d|", array_of_numbers[i]);
	// 	i++;
	// }
	// ft_printf("|\n");
	check_repetetive_numbers(array_of_numbers, len);
	// create array of indexes
	i = 0;
	while (i < len)
	{
		array_of_indexes[i] = i;
		i++;
	}

	// allocate stacks
	stack *A = my_malloc(sizeof(stack));
	stack *B = my_malloc(sizeof(stack));

	A->array_of_nums = my_malloc(len * sizeof(num));
	A->lenght = len;

	B->array_of_nums = my_malloc(len * sizeof(num));
	B->lenght = 0;

	// feed stack A
	i = 0;
	while (i < len)
	{
		A->array_of_nums[i].value = array_of_numbers[i];
		i++;
	}
	sort_array(array_of_numbers, array_of_indexes, len);
	// feed indexes
	i = 0;
	while (i < len)
	{
		A->array_of_nums[array_of_indexes[i]].index = i;
		i++;
	}
	char *str0 = NULL;
	char *str1 = readline(0);
	char *tmp;
	int err = 0;
	while (str1)
	{
		if (ft_strcmp(str1, "sa") &&
			ft_strcmp(str1, "sb") &&
			ft_strcmp(str1, "ss") &&
			ft_strcmp(str1, "pa") &&
			ft_strcmp(str1, "pb") &&
			ft_strcmp(str1, "ra") &&
			ft_strcmp(str1, "rb") &&
			ft_strcmp(str1, "rr") &&
			ft_strcmp(str1, "rra") &&
			ft_strcmp(str1, "rrb") &&
			ft_strcmp(str1, "rrr"))
		{
			ft_printf("\nenter a valid move \"%s\"\n", str1);
			exit(1);
		}
		str0 = ft_strjoin(str0, str1);
		free(str1);
		tmp = ft_strjoin(str0, " ");
		free(str0);
		str0 = tmp;
		str1 = readline(0);
	}
	if (err)
		exit(1);
	// my_free(str1);
	array_of_moves = ft_split(str0, ' ');
	i = 0;
	while (array_of_moves && array_of_moves[i])
	{
		!ft_strcmp(array_of_moves[i], "sa") && swap(A);
		!ft_strcmp(array_of_moves[i], "sb") && swap(B);
		!ft_strcmp(array_of_moves[i], "ss") && swap(A) && swap(B);
		!ft_strcmp(array_of_moves[i], "pa") && push(B, A);
		!ft_strcmp(array_of_moves[i], "pb") && push(A, B);
		!ft_strcmp(array_of_moves[i], "ra") && rotate(A);
		!ft_strcmp(array_of_moves[i], "rb") && rotate(B);
		!ft_strcmp(array_of_moves[i], "rr") && rotate(A) && rotate(B);
		!ft_strcmp(array_of_moves[i], "rra") && reverse_rotate(A);
		!ft_strcmp(array_of_moves[i], "rrb") && reverse_rotate(B);
		!ft_strcmp(array_of_moves[i], "rrr") && reverse_rotate(A) && reverse_rotate(B);
		i++;
	}

	ft_printf("\n===============================================\n");
	i = 0;
	while (i < B->lenght)
	{
		printf("%4d ", B->array_of_nums[i++].value);
		if (B->lenght / 8 && i % (B->lenght / 8) == 0)
			printf("|\n");
	}
	printf("\n");
	i = 0;
	while (i < A->lenght)
	{
		printf("%4d ", A->array_of_nums[i++].value);
		if (A->lenght / 8 && i % (A->lenght / 8) == 0)
			printf("|\n");
	}
	printf("\n\n");

	printf("A.lenght : %d\nB.lenght: %d\n", A->lenght, B->lenght);
	is_sorted(A);
	// my_free_all();
	system("leaks a.out");
}