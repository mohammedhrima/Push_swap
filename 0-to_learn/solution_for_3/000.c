#include <stdio.h>

int get_distance(int *num)
{
	return (num[0] + 2 * num[1] + num[2]);
}

int main(void)
{
	int arr[] = {2, 0, 1};
	printf("%d\n", get_distance(arr));
}