#include "../Libft/libft.h"

typedef struct number
{
	int value;
	int index;
} num;

typedef struct stack
{
	num *array_of_nums;
	int lenght;
} stack;

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

void check_repeated_numbers(int *array, int len)
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
				ft_printf("Error\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

int rotate(stack *list)
{
	if (!list)
	{
		printf("KO\n");
		exit(0);
	}
	else if (list && list->lenght > 1)
	{
		num tmp = list->array_of_nums[0];
		ft_memmove(list->array_of_nums, list->array_of_nums + 1, (list->lenght - 1) * sizeof(num));
		list->array_of_nums[list->lenght - 1] = tmp;
		return (1);
	}
	return (0);
}

int reverse_rotate(stack *list)
{
	if (!list)
	{
		printf("KO\n");
		exit(0);
	}
	else if (list && list->lenght > 1)
	{
		num tmp = list->array_of_nums[list->lenght - 1];
		ft_memmove(list->array_of_nums + 1, list->array_of_nums, (list->lenght - 1) * sizeof(num));
		list->array_of_nums[0] = tmp;
		return (1);
	}
	return (0);
}

int push(stack *src, stack *dest)
{
	if (src->lenght)
	{
		num tmp = src->array_of_nums[0];
		rotate(src);
		src->lenght--;
		dest->lenght++;
		reverse_rotate(dest);
		dest->array_of_nums[0] = tmp;
		return (1);
	}
	return (0);
}

int swap(stack *X)
{
	num tmp = X->array_of_nums[0];
	X->array_of_nums[0] = X->array_of_nums[1];
	X->array_of_nums[1] = tmp;
	return (1);
}

char *readline(int fd)
{
	int i = 0;
	int j = 0;
	char *res;
	char *tmp;

	char c;
	res = NULL;
	tmp = NULL;
	j = read(fd, &c, 1);
	while (j && c != '\n')
	{
		tmp = ft_strjoin(res, &c);
		res = tmp;
		j = read(fd, &c, 1);
		if (j == 0)
			break;
		i++;
		res[i] = '\0';
	}

	return (res);
}

int ft_issign(char c)
{
	return (c == '+' || c == '-');
}
int contains_number(char *str)
{
	int i = 0;
	while (str && str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}
int is_valid(char *str)
{
	int i = 0;

	if (!contains_number(str))
		return (0);
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_issign(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int is_sorted(stack *A)
{
	int i = 1;
	while (i < A->lenght)
	{
		if (A->array_of_nums[i].value < A->array_of_nums[i - 1].value)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int len;
	char *str;
	char **array;
	long int number;
	int there_is_numbers;
	int *array_of_numbers;
	int *array_of_indexes;
	int moves = 0;

	if (argc < 2)
		exit(0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		there_is_numbers = is_valid(argv[i]);
		while (there_is_numbers && argv[i][j])
		{
			if (argv[i][j] == ' ' && argv[i][j + 1] != '\0' && argv[i][j + 1] != ' ' && !ft_issign(argv[i][j + 1]) && !ft_isdigit(argv[i][j + 1]))
			{
				there_is_numbers = 0;
				break;
			}
			if (ft_issign(argv[i][j]) && !ft_isdigit(argv[i][j + 1]))
			{
				there_is_numbers = 0;
				break;
			}
			if (ft_isdigit(argv[i][j]) && !ft_isdigit(argv[i][j + 1]) && argv[i][j + 1] != '\0' && argv[i][j + 1] != ' ')
			{
				there_is_numbers = 0;
				break;
			}
			j++;
		}
		if (!there_is_numbers)
		{
			ft_printf("Error\n");
			exit(0);
		}
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	array = ft_split(str, ' ');
	len = ft_arrlen(array);
	array_of_numbers = my_malloc((len + 1) * sizeof(int));
	i = 0;
	while (i < len)
	{
		if (ft_strlen(array[i]) > 13)
		{
			ft_printf("Error\n");
			exit(0);
		}
		number = ft_atoi(array[i]);
		if (number > INT_MAX || number < INT_MIN)
		{
			ft_printf("Error\n");
			exit(0);
		}
		array_of_numbers[i] = (int)number;
		i++;
	}
	check_repeated_numbers(array_of_numbers, len);
	array_of_indexes = my_malloc((len + 1) * sizeof(int));
	i = 0;
	while (i < len)
	{
		array_of_indexes[i] = i;
		i++;
	}
	stack *A = my_malloc(sizeof(stack));
	stack *B = my_malloc(sizeof(stack));

	A->array_of_nums = ft_calloc(len, sizeof(num));
	A->lenght = len;
	B->array_of_nums = ft_calloc(len, sizeof(num));
	B->lenght = 0;

	i = 0;
	while (i < len)
	{
		A->array_of_nums[i].value = array_of_numbers[i];
		i++;
	}
	sort_array(array_of_numbers, array_of_indexes, len);
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
			ft_printf("Error");
			exit(0);
		}
		str0 = ft_strjoin(str0, str1);
		free(str1);
		tmp = ft_strjoin(str0, " ");
		free(str0);
		str0 = tmp;
		str1 = readline(0);
	}

	char **array_of_moves = ft_split(str0, ' ');
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
	if (is_sorted(A) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
