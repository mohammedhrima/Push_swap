#include "../Libft/libft.h"
#define AND &&
#define DO &&
#define OR |
#define NOT !
#define IS ==
#define EQUAL ==
#define PRINT ft_printf
#define IF
int main_spliter = 0;
int moves = 0;
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
	printf("len: %d\n", len);
	printf("01*(len/3): %d\n", len / 3);
	printf("02*(len/3): %d\n", 2 * (len / 3));
	printf("03*(len/3): %d\n", 3 * (len / 3));

	int ra = 0;
	int rb = 0;
	int p = 0;

	printf("\n1st while loop\n");
	float min = 14 * (len / 27);
	float max = 14 * (len / 27);

	float len2;
	len2 = 0;
	while (min > 0 && max < len)
	{
		min -= (len / 27);
		max += (len / 27);
		len2 = (int)max - (int)min;
		while (B->lenght < (int)len2) // 3/8 -> 5/8
		{
			ra = 0;
			rb = 0;
			if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index <= max)
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
	}
	printf("\n\non exit:\nmin:%f\nmax:%f\nlen: %d\n", min, max, len);
}

void sort4(stack *A, stack *B, int len)
{
	// printf("01*(len/16): %d\n", len / 16);
	// printf("02*(len/16): %d\n", 2 * (len / 16));
	// printf("03*(len/16): %d\n", 3 * (len / 16));
	// printf("04*(len/16): %d\n", 4 * (len / 16));
	// printf("05*(len/16): %d\n", 5 * (len / 16));
	// printf("06*(len/16): %d\n", 6 * (len / 16));
	// printf("07*(len/16): %d\n", 7 * (len / 16));
	// printf("08*(len/16): %d\n", 8 * (len / 16));
	// printf("09*(len/16): %d\n", 9 * (len / 16));
	// printf("10*(len/16): %d\n", 10 * (len / 16));
	// printf("11*(len/16): %d\n", 11 * (len / 16));
	// printf("12*(len/16): %d\n", 12 * (len / 16));
	// printf("13*(len/16): %d\n", 13 * (len / 16));
	// printf("14*(len/16): %d\n", 14 * (len / 16));
	// printf("15*(len/16): %d\n", 15 * (len / 16));
	// printf("16*(len/16): %d\n", len);
	int ra = 0;
	int rb = 0;
	int p = 0;
	float min; // for 2n
	float max; // for 2n
	float len2 = 0;
	float len3 = 0;

#if 0
	if (len % 2 == 0)
	{
		min = 0;			  // for 2n
		max = (float)len / 2; // for 2nd
		len2 = max - min;
		printf("\nstart:\nB.lenght = %d\nmin = %f\nmax = %f\nlen2 = %f\n\n\n", B->lenght, min, max, len2);
		while (B->lenght < len / 2)
		{
			ra = 0;
			rb = 0;
			if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
			{
				moves += push(A, B);
				printf("p ");
				if (B->array_of_nums[0].index >= (min + max) / 2)
					rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
			}
			else
				ra = rotate(A);
			ra &&rb &&printf("rr ") && moves++;
			ra && !rb && printf("ra ") && moves++;
			rb && !ra && printf("rb ") && moves++;
		}
		while (B->lenght < len)
			moves += push(A,B);
	}
#elif 0 // 183 moves
	if (len % 4 == 0)
	{
		min = len / 4;			  // for 2n
		max = 3 * (float)len / 4; // for 2nd
		len2 = max - min;
		printf("\nstart:\nB.lenght = %d\nmin = %f\nmax = %f\nlen2 = %f\n\n\n", B->lenght, min, max, len2);
		while (B->lenght < len2)
		{
			ra = 0;
			rb = 0;
			if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
			{
				moves += push(A, B);
				printf("p ");
				if (B->array_of_nums[0].index >= (min + max) / 2)
					rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
			}
			else
				ra = rotate(A);
			ra &&rb &&printf("rr ") && moves++;
			ra && !rb && printf("ra ") && moves++;
			rb && !ra && printf("rb ") && moves++;
		}
		min = 0;		  // for 2n
		max = (float)len; // for 2nd
		len2 = max - min;
		while (B->lenght < len2)
		{
			ra = 0;
			rb = 0;
			if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
			{
				moves += push(A, B);
				printf("p ");
				if (B->array_of_nums[0].index >= (min + max) / 2)
					rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
			}
			else
				ra = rotate(A);
			ra &&rb &&printf("rr ") && moves++;
			ra && !rb && printf("ra ") && moves++;
			rb && !ra && printf("rb ") && moves++;
		}
	}
#elif 0
	if (len % 2 == 0) // this rule is always true // do < 1
	{
		int spliter;
		printf("\n\"split to 2 range of %d\"\n", len / 2);
		main_spliter = 2;
		spliter = 2;
		if (len % 4 == 0)
		{
			spliter = 4;
			printf("\n\"split to 4 range of %d\"\n", len / 4);
			main_spliter = 4;
			if (len % 8 == 0)
			{
				printf("\n\"split to 8 range of %d\"\n", len / 8);
				spliter = 8;
				main_spliter = 8;
				if (len % 16 == 0)
				{
					// printf("\n\"split to 16 range of %d\"\n", len / 16);
					// spliter = 16;
					// main_spliter = 16;
					// if (len % 32 == 0)
					// {
					// 	printf("\n\"split to 32 range of %d\"\n", len / 32);
					// 	spliter = 32;
					// 	main_spliter = 32;
					// }
				}
			}
		}

		// the end
		// the midle - step
		// spliter = 2;
		min = (float)len / 2 - (float)len / spliter; // for 2nd
		max = (float)len / 2 + (float)len / spliter; // for 2nd
		//////////////////////////////////////////////////
		printf("\n\nstart :\nA.lenght = %d\nB.lenght = %d\nmin = %f\nmax = %f\nnew B.lenght = %f\n\n", A->lenght, B->lenght, min, max, max - min);
		while (max - min <= len)
		{
			while (B->lenght < (max - min))
			{
				ra = 0;
				rb = 0;
				if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
				{
					moves += push(A, B);
					printf("p ");
					if (B->array_of_nums[0].index < (min + max) / 2)
						rb = rotate(B); // rotate can ruturn 0 if len is les than 2
				}
				else
					ra = rotate(A);
				ra &&rb &&printf("rr ") && moves++;
				ra && !rb && printf("ra ") && moves++;
				rb && !ra && printf("rb ") && moves++;
			}
			min = min - (float)len / spliter; // for 2nd
			max = max + (float)len / spliter; // for 2nd
		}
	}
#elif 0
	if (len % 2 == 0) // this rule is always true // do < 1
	{
		int spliter;
		printf("\n\"split to 2 range of %d\"\n", len / 2);
		main_spliter = 2;
		spliter = 2;
		if (len % 4 == 0)
		{
			spliter = 4;
			printf("\n\"split to 4 range of %d\"\n", len / 4);
			main_spliter = 4;
			if (len % 8 == 0)
			{
				// printf("\n\"split to 8 range of %d\"\n", len / 8);
				// spliter = 8;
				// main_spliter = 8;
			}
		}

		// the end
		// the midle - step
		// spliter = 2;

		//	spliter *= 2;
		len2 = 0;
		float step = (float)len / (spliter);
		//////////////////////////////////////////////////
		// printf("\n\nstart :\nA.lenght = %d\nB.lenght = %d\nmin = %f\nmax = %f\nnew B.lenght = %f\n\n", A->lenght, B->lenght, min1, max, max - min1);
		printf("step is %f\n", step);
		printf("limit1 %f / %d | limit2 %f / %d \n", (len - step / 2), (int)(len - step / 2), step / 2, (int)step / 2);
		int i = 0;
		while ((int)len2 < len)
		{
			len2 = len2 + (float)len / (spliter);
			// printf("len2: %f\n", len2);
			// exit(0);

			while (B->lenght < (int)len2)
			{
				ra = 0;
				rb = 0;
				if (
					((A->array_of_nums[0].index >= 0) && (A->array_of_nums[0].index < step / 2)) ||
					((A->array_of_nums[0].index >= (int)(len - step / 2)) && (A->array_of_nums[0].index < (int)(len))))
				{
					moves += push(A, B);
					printf("p ");
					// if (B->array_of_nums[0].index % 12 >= 3)
					// 	rb = reverse_rotate(B); // rotate can ruturn 0 if len is les than 2
				}
				else
					ra = rotate(A);
				ra &&rb &&printf("rr ") && moves++;
				ra && !rb && printf("ra ") && moves++;
				rb && !ra && printf("rb ") && moves++;

				i++;
			}
			step += (float)len / (spliter);
		}
		while (A->lenght < len / 2)
		{
			if (B->array_of_nums[0].index < len / 2)
			{
				moves += push(B, A);
				moves += rotate(A);
			}
			else
				moves += rotate(B);
		}
		while (A->lenght < len)
		{
			moves += push(B, A);
		}
	}
#elif 1
	if (len % 2 == 0)
	{
		min = (float)len / 2; // for 2n
		max = (float)len / 2; // for 2nd
		len2 = max - min;
		printf("\nstart:\nB.lenght = %d\nmin = %f\nmax = %f\nlen2 = %f\n\n\n", B->lenght, min, max, len2);
		while (max - min < len)
		{
			min -= (float)len / 8;
			max += (float)len / 8;
			while (B->lenght < max - min)
			{
				ra = 0;
				rb = 0;
				if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
				{
					moves += push(A, B);
					ft_printf("p ");
					if (B->array_of_nums[0].index >= len / 2)
						rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
				}
				else
					ra = rotate(A);
				ra &&rb &&ft_printf("rr ") && moves++;
				ra && !rb && ft_printf("ra ") && moves++;
				rb && !ra && ft_printf("rb ") && moves++;
			}
		}
		int i = 0;
		printf("\n");
		while (i < B->lenght)
		{
			printf("%4d ", B->array_of_nums[i++].index);
			if (i % (B->lenght / 8) == 0)
				printf("/\n");
		}
		printf("\n");

		// exit(0);
		int to_push_index = 0;
		i = 0;
		while (A->lenght < len)
		{
			i = 0;
			// mysleep();
			// ft_printf("seach for index=%d in B, B.lenght=%d, B->array_of_nums[B->lenght - i - 1].index=%d\n", to_push_index, B->lenght , B->array_of_nums[B->lenght - i - 1].index);
			while (i < B->lenght / 2 && B->array_of_nums[i].index != to_push_index && B->array_of_nums[B->lenght - i - 1].index != to_push_index)
			{
				// ft_printf("a -> i:%d, B.lenght:%d\n", i, B->lenght);
				// mysleep();
				i++;
			}
			if (B->array_of_nums[i].index == to_push_index)
			{
				// ft_printf("b -> i:%d, index is %d\n", i, B->array_of_nums[i].index);
				// mysleep();
				while (i > 0)
				{
					i -= rotate(B);
					moves++;
				}
				// printf("wsalt 1 index: %d\n", B->array_of_nums[0].index);
				// exit(0);
			}
			else if (B->array_of_nums[B->lenght - i - 1].index == to_push_index)
			{
				// ft_printf("c -> i:%d, index is %d\n", i, B->array_of_nums[i].index);
				// mysleep();
				while (i >= 0)
				{
					i -= reverse_rotate(B);
					moves++;
				}
				// printf("wsalt 2 index: %d\n", B->array_of_nums[0].index);
				// exit(0);
			}
			if (B->array_of_nums[0].index == to_push_index)
			{
				// ft_printf("push %d to A \n", B->array_of_nums[0].index);
				mysleep(6);
				// mysleep();
				moves += push(B, A);
				to_push_index++;
				printf("\n====================================================\n");
				int j = 0;
				j = 0;
				printf("stack A\n");
				while (j < A->lenght)
				{
					printf("%4d ", A->array_of_nums[j++].index);
					if (j % (len / 8) == 0)
						printf("|\n");
				}
				j = 0;
				printf("\nstack B\n");
				while (j < B->lenght)
				{
					printf("%4d ", B->array_of_nums[j++].index);
					if (j % (len / 8) == 0)
						printf("|\n");
				}
				printf("\n====================================================\n");
			}
		}
	}
#else
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
#endif
}

int main(void)
{
	int i;
	int const_array[] = {207, 449, 397, 80, 36, 173, 15, 476, 278, 294, 469, 123, 309, 360, 174, 226, 269, 348, 120, 393, 71, 37, 3, 330, 296, 266, 19, 389, 222, 428, 368, 47, 273, 67, 444, 167, 46, 337, 45, 251, 95, 256, 314, 401, 253, 417, 20, 70, 244, 26, 487, 394, 456, 274, 268, 146, 317, 184, 431, 158, 91, 371, 416, 230, 189, 405, 66, 287, 407, 69, 440, 7, 483, 223, 38, 111, 76, 272, 126, 98, 64, 249, 399, 433, 132, 43, 261, 234, 50, 9, 387, 131, 144, 326, 151, 343, 478, 201, 51, 413};
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
	sort4(A, B, len);
	printf("\n\n\n=========== MAIN ===========\n");
	printf("\nafter sorting\nA: \n");
	i = 0;
	// while (i < A->lenght)
	// 	printf("%4d ", A->array_of_nums[i++].value);
	// printf("\nin:");
	i = 0;
	// int ranges = len / main_spliter;
	while (i < A->lenght)
	{
		printf("%4d ", A->array_of_nums[i++].index);
		if (i % (A->lenght / 8) == 0)
			printf("/\n");
	}
	printf("\nB: \n");
	// i = 0;
	// while (i < B->lenght)
	// {
	// 	printf("%4d ", B->array_of_nums[i++].value);
	// 	if (i % (len / 32) == 0)
	// 		printf("\n");
	// }
	// printf("\nin:\n");

	i = 0;
	while (i < B->lenght)
	{
		printf("%4d ", B->array_of_nums[i++].index);
		if (i % (B->lenght / 8) == 0)
			printf("/\n");
	}
	printf("\n\n");
	printf("moves : %d\nA.lenght : %d\nB.lenght: %d\n", moves, A->lenght, B->lenght);

	return (0);
}