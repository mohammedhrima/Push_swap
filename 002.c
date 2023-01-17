#include <stdio.h>
#include <string.h>
#include "Libft/libft.h"

// swap the two first numbers of stack
void swap(int *arr, size_t len)
{
	if (len / sizeof(int) > 1)
	{
		int tmp = arr[0];
		arr[0] = arr[1];
		arr[1] = tmp;
	}
}
// push number from one stack to another
void push(int **from, size_t from_len, int **to, size_t to_len)
{
	int *ptr1 = my_malloc(from_len - sizeof(int));
	int *ptr2 = my_malloc(to_len + sizeof(int));

	ft_memcpy(ptr1, *from + 1, from_len - sizeof(int));
	*ptr2 = **from;
	ft_memcpy(ptr2 + 1, *to, to_len);
	free(*from);
	*from = ptr1;
	free(*to);
	*to = ptr2;
}
// rotate stack
void rotate(int *arr, size_t len)
{
	int tmp = arr[0];
	ft_memcpy(arr, arr + 1, len - sizeof(int));
	arr[len / sizeof(int) - 1] = tmp;
}
// reverse rotate stack
void reverse_rotate(int *arr, size_t len)
{
	int tmp = arr[len / sizeof(int) - 1];
	ft_memmove(arr + 1, arr, len - sizeof(int));
	arr[0] = tmp;
}

int main(void)
{
	size_t i;
	int x[] = {7, 2, 3, 1, 6, 5};
	int y[] = {17, 12, 13, 11, 16, 15};
	size_t a_size = sizeof(x);
	size_t b_size = sizeof(y);

	// copy them in heap
	int *a = malloc(sizeof(x));
	int *b = malloc(sizeof(y));
	ft_memcpy(a, x, sizeof(x));
	ft_memcpy(b, y, sizeof(y));

	// loop throw them to check there content
	i = 0;
	ft_printf("\na = ");
	while (i < a_size / sizeof(int))
		ft_printf("%d ", a[i++]);
	ft_printf("\nb = ");
	i = 0;
	while (i < b_size / sizeof(int))
		ft_printf("%d ", b[i++]);
	ft_printf("\n\n");

	// test pushing
	// ft_printf("after pushing: \n");
	// push(&a, sizeof(x), &b, sizeof(y));
	// i = 0;
	// ft_printf("\na = ");
	// while (i < sizeof(x) / sizeof(int) - 1)
	// 	ft_printf("%d ", a[i++]);
	// ft_printf("\nb = ");
	// i = 0;
	// while (i < sizeof(y) / sizeof(int) + 1)
	// 	ft_printf("%d ", b[i++]);
	// ft_printf("\n\n");

	// test swaping
	//  ft_printf("after swaping: \n");
	//  swap(a, a_size);
	//  swap(b, b_size);
	//  i = 0;
	//  ft_printf("\na = ");
	//  while (i < a_size / sizeof(int))
	//  	ft_printf("%d ", a[i++]);
	//  ft_printf("\nb = ");
	//  i = 0;
	//  while (i < b_size / sizeof(int))
	//  	ft_printf("%d ", b[i++]);
	//  ft_printf("\n\n");

	// test rotate
	// ft_printf("after rotating: \n");
	// rotate(a, a_size);
	// rotate(b, b_size);
	// i = 0;
	// ft_printf("\na = ");
	// while (i < a_size / sizeof(int))
	// 	ft_printf("%d ", a[i++]);
	// ft_printf("\nb = ");
	// i = 0;
	// while (i < b_size / sizeof(int))
	// 	ft_printf("%d ", b[i++]);
	// ft_printf("\n\n");

	// test reverse rotate
	// ft_printf("after reverse rotating: \n");
	// reverse_rotate(a, a_size);
	// reverse_rotate(b, b_size);
	// i = 0;
	// ft_printf("\na = ");
	// while (i < a_size / sizeof(int))
	// 	ft_printf("%d ", a[i++]);
	// ft_printf("\nb = ");
	// i = 0;
	// while (i < b_size / sizeof(int))
	// 	ft_printf("%d ", b[i++]);
	// ft_printf("\n\n");
}
