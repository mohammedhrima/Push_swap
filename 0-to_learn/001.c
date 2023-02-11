#include <stdio.h>

#define and &&
#define OR ||
#define less <
#define than
#define do ?
#define else :
#define IF

int main(void)
{

	int x = 96;

	// x < 20 ? printf("1") : printf("2");
	IF x less than 20 do printf("1") else printf("2");

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
	z = 5 / 2;
	printf("%d\n", z);
	printf("%f\n", (float)7 / 2);
}