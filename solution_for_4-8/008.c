#include "../Libft/libft.h"
#define AND &&
#define DO &&
#define OR |
#define NOT !
#define IS ==
#define EQUAL ==
#define PRINT ft_printf
#define IF

int moves = 0;
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
				printf("Error: there is repetetive number\n");
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
		printf("\n\"verify src len in push\"\n");
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

num *max(stack *X)
{
	int i = 0;
	while (i < X->lenght)
	{
		if (X->array_of_nums[i].index == X->lenght - 1)
			return (X->array_of_nums + i);
		i++;
	}
	return (NULL);
}

num *min(stack *X)
{
	int i = 0;
	while (i < X->lenght)
	{
		if (X->array_of_nums[i].index == 0)
			return (X->array_of_nums + i);
		i++;
	}
	return (NULL);
}

int get_distance(num *array_of_nums)
{
	return (array_of_nums[0].index + 2 * array_of_nums[1].index + array_of_nums[2].index);
}

void sort_3(stack *X, char c)
{
	int i = 0;
	if (X->lenght <= 1)
		printf("\nverify length in sort\n");
	if (X->lenght > 1 && X->array_of_nums[0].index == X->array_of_nums[1].index + 1)
	{
		printf("s%c ", c);
		swap(X);
		moves++;
	}
	if (X->lenght > 2)
	{
		int n = get_distance(X->array_of_nums);
		//	printf("\nn: %d\n", n);
		if (n == 3)
		{
			printf("r%c ", c);
			rotate(X);
			moves++;
		}
		if (n == 5)
		{
			printf("rr%c ", c);
			reverse_rotate(X);
			moves++;
		}
		if (X->array_of_nums[0].index == X->array_of_nums[1].index + 1)
		{
			printf("s%c ", c);
			swap(X);
		}
	}
}

// be aware that a lenght change all the time
void sort1(stack *A, stack *B, int len)
{
	printf("    len/4: %d\n", len / 4);
	printf("    len/2: %d\n", len / 2);
	printf("3*(len/4): %d\n", 3 * (len / 4));
	printf("      len: %d\n", len);
	int ra = 0;
	int rb = 0;
	int p = 0;
	printf("\n1st while loop\n");
	while (B->lenght < len / 2)
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= len / 4 && A->array_of_nums[0].index < 3 * (len / 4))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n2nd while loop\n");
	while (B->lenght < len)
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 3 * (len / 4) || A->array_of_nums[0].index < len / 4)
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
}
void sort2(stack *A, stack *B, int len)
{
	printf("01*(len/16): %d\n", len / 16);
	printf("02*(len/16): %d\n", 2 * (len / 16));
	printf("03*(len/16): %d\n", 3 * (len / 16));
	printf("04*(len/16): %d\n", 4 * (len / 16));
	printf("05*(len/16): %d\n", 5 * (len / 16));
	printf("06*(len/16): %d\n", 6 * (len / 16));
	printf("07*(len/16): %d\n", 7 * (len / 16));
	printf("08*(len/16): %d\n", 8 * (len / 16));
	printf("09*(len/16): %d\n", 9 * (len / 16));
	printf("10*(len/16): %d\n", 10 * (len / 16));
	printf("11*(len/16): %d\n", 11 * (len / 16));
	printf("12*(len/16): %d\n", 12 * (len / 16));
	printf("13*(len/16): %d\n", 13 * (len / 16));
	printf("14*(len/16): %d\n", 14 * (len / 16));
	printf("15*(len/16): %d\n", 15 * (len / 16));
	printf("16*(len/16): %d\n\n", len);
	int ra = 0;
	int rb = 0;
	int p = 0;
	printf("\n1st while loop\n");
	while (B->lenght < len / 4) // 3/8 -> 5/8
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 3 * (len / 8) && A->array_of_nums[0].index < 5 * (len / 8))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n2nd while loop\n");
	while (B->lenght < len / 2) // 1/4 -> 3/4
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= len / 4 && A->array_of_nums[0].index < 3 * (len / 4))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n3rd while loop\n");
	while (B->lenght < 3 * (len / 4)) // 1/8 -> 7/8
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= len / 8 && A->array_of_nums[0].index < 7 * (len / 8))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n4th while loop\n");
	while (B->lenght < len) // 0 -> 1
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 7 * (len / 8) || A->array_of_nums[0].index < len)
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
}

void sort3(stack *A, stack *B, int len)
{
	printf("01*(len/32): %d\n", len / 32);
	printf("02*(len/32): %d\n", 2 * (len / 32));
	printf("03*(len/32): %d\n", 3 * (len / 32));
	printf("04*(len/32): %d\n", 4 * (len / 32));
	printf("05*(len/32): %d\n", 5 * (len / 32));
	printf("06*(len/32): %d\n", 6 * (len / 32));
	printf("07*(len/32): %d\n", 7 * (len / 32));
	printf("08*(len/32): %d\n", 8 * (len / 32));
	printf("09*(len/32): %d\n", 9 * (len / 32));
	printf("10*(len/32): %d\n", 10 * (len / 32));
	printf("11*(len/32): %d\n", 11 * (len / 32));
	printf("12*(len/32): %d\n", 12 * (len / 32));
	printf("13*(len/32): %d\n", 13 * (len / 32));
	printf("14*(len/32): %d\n", 14 * (len / 32));
	printf("15*(len/32): %d\n", 15 * (len / 32));
	printf("16*(len/32): %d\n\n", 16 * (len / 32));
	printf("17*(len/32): %d\n", 17 * (len / 32));
	printf("18*(len/32): %d\n", 18 * (len / 32));
	printf("19*(len/32): %d\n", 19 * (len / 32));
	printf("20*(len/32): %d\n", 20 * (len / 32));
	printf("21*(len/32): %d\n", 21 * (len / 32));
	printf("22*(len/32): %d\n", 22 * (len / 32));
	printf("23*(len/32): %d\n", 23 * (len / 32));
	printf("24*(len/32): %d\n", 24 * (len / 32));
	printf("25*(len/32): %d\n", 25 * (len / 32));
	printf("26*(len/32): %d\n", 26 * (len / 32));
	printf("27*(len/32): %d\n", 27 * (len / 32));
	printf("28*(len/32): %d\n", 28 * (len / 32));
	printf("29*(len/32): %d\n", 29 * (len / 32));
	printf("30*(len/32): %d\n", 30 * (len / 32));
	printf("31*(len/32): %d\n", 31 * (len / 32));
	printf("32*(len/32): %d\n\n", len);
	int ra = 0;
	int rb = 0;
	int p = 0;
	printf("\n1 while loop\n");
	while (B->lenght < len / 16) // 3/8 -> 5/8
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 15 * (len / 32) && A->array_of_nums[0].index < 17 * (len / 32))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n2 while loop\n");
	while (B->lenght < 2 * (len / 16)) // 1/4 -> 3/4
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 14 * (len / 32) && A->array_of_nums[0].index < 18 * (len / 32))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n3 while loop\n");
	while (B->lenght < 3 * (len / 16)) // 1/8 -> 7/8
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 13 * (len / 32) && A->array_of_nums[0].index < 19 * (len / 32))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n4 while loop\n");
	while (B->lenght < 4 * (len / 16)) // 1/4 -> 3/4
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 12 * (len / 32) && A->array_of_nums[0].index < 20 * (len / 32))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n5 while loop\n");
	while (B->lenght < 5 * (len / 16)) // 1/8 -> 7/8
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 11 * (len / 32) && A->array_of_nums[0].index < 21 * (len / 32))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n6 while loop\n");
	while (B->lenght < 6 * (len / 16)) // 0 -> 1
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 10 * (len / 32) && A->array_of_nums[0].index < 22 * (len / 32))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n7 while loop\n");
	while (B->lenght < 7 * (len / 16)) // 0 -> 1
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 9 * (len / 32) && A->array_of_nums[0].index < 23 * (len / 32))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n8 while loop\n");
	while (B->lenght < 8 * (len / 16)) // 3/8 -> 5/8
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 8 * (len / 32) && A->array_of_nums[0].index < 24 * (len / 32))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n9 while loop\n");
	while (B->lenght < 9 * (len / 16)) // 1/4 -> 3/4
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 7 * (len / 32) && A->array_of_nums[0].index < 25 * (len / 32))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n10 while loop\n");
	while (B->lenght < 10 * (len / 16)) // 1/8 -> 7/8
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 6 * (len / 32) && A->array_of_nums[0].index < 26 * (len / 32))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n11 while loop\n");
	while (B->lenght < 11 * (len / 16)) // 1/4 -> 3/4
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 5 * (len / 32) && A->array_of_nums[0].index < 27 * (len / 32))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n12 while loop\n");
	while (B->lenght < 12 * (len / 16)) // 1/8 -> 7/8
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 4 * (len / 32) && A->array_of_nums[0].index < 28 * (len / 32))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n13 while loop\n");
	while (B->lenght < 13 * (len / 16)) // 0 -> 1
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 3 * (len / 32) && A->array_of_nums[0].index < 29 * (len / 32))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n14 while loop\n");
	while (B->lenght < 14 * (len / 16)) // 0 -> 1
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 2 * (len / 32) && A->array_of_nums[0].index < 30 * (len / 32))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n15 while loop\n");
	while (B->lenght < 15 * (len / 16)) // 0 -> 1
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= (len / 32) && A->array_of_nums[0].index < 31 * (len / 32))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n16 while loop\n");
	while (B->lenght < len) // 0 -> 1
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index < len)
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
}

int main(void)
{
	int i;
	int const_array[] = {280, 464, 73, 225, 29, 61, 167, 112, 54, 430, 454, 59, 183, 126, 306, 187, 16, 107, 475, 216, 410, 194, 243, 108, 88, 467, 367, 258, 376, 304, 416, 307, 42, 397, 462, 234, 30, 481, 95, 281, 377, 14, 363, 451, 155, 129, 399, 294, 417, 431, 371, 324, 249, 272, 494, 172, 434, 328, 401, 290, 261, 453, 218, 489, 440, 274, 221, 334, 151, 105, 235, 296, 239, 144, 245, 142, 445, 103, 326, 203, 344, 192, 157, 251, 384, 325, 321, 393, 352, 135, 442, 67, 347, 405, 96, 49};
	int *array_of_indexes = ft_calloc(1, sizeof(const_array));
	int *array_of_numbers = ft_calloc(1, sizeof(const_array));
	int len = (int)(sizeof(const_array) / sizeof(int));
	check_repetetive_numbers(const_array, len);

	// copy const_array to the heap in array_of_numbers
	ft_memcpy(array_of_numbers, const_array, sizeof(const_array));

	i = 0;
	while (i < len)
	{
		array_of_indexes[i] = i;
		i++;
	}

	// setup stack A and B
	stack *A = ft_calloc(1, sizeof(stack));
	stack *B = ft_calloc(1, sizeof(stack));

	A->array_of_nums = ft_calloc(len, sizeof(num));
	A->lenght = len;

	B->array_of_nums = ft_calloc(len, sizeof(num));
	B->lenght = 0;

	// feed numbers
	i = 0;
	while (i < len)
	{
		A->array_of_nums[i].value = array_of_numbers[i];
		i++;
	}

	printf("\n=========== MAIN ===========\n");
	sort_array(array_of_numbers, array_of_indexes, len);
	// feed indexes
	i = 0;
	while (i < len)
	{
		A->array_of_nums[array_of_indexes[i]].index = i;
		i++;
	}
	// sort_3(A, 'a');
	// sort1(A, B, len);
	// sort2(A, B, len);
	sort3(A, B, len);

	printf("\nafter sorting\nA: \n");
	i = 0;
	// while (i < A->lenght)
	// 	printf("%4d ", A->array_of_nums[i++].value);
	// printf("\nin:");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].index);
	printf("\n\n");
	printf("\nB: \n");
	i = 0;
	while (i < B->lenght)
	{
		printf("%4d ", B->array_of_nums[i++].value);
		if (i % (len / 32) == 0)
			printf("\n");
	}
	printf("\nin:\n");
	i = 0;
	while (i < B->lenght)
	{
		printf("%4d ", B->array_of_nums[i++].index);
		if (i % (len / 32) == 0)
			printf("\n");
	}
	printf("\n\n");
	printf("moves : %d\n\n", moves);

	return (0);
}