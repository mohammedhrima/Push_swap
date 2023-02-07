#include <stdio.h>

int main(void)
{
	int x = 96;
	int y = 0;
	int z = 0;
	int push = 12;
	while (x >= push)
	{
		z += x;
		z += push;
		x -= push;
	}
//	z += (2*push);
	printf("%d\n", z);
}