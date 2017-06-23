#include <stdio.h>
#include <stdlib.h>
#define RANDMAX 9

int roundNum(float n)
{
	return (int)(n < 0 ? n - 0.5 : n + 0.5);
}

int main()
{
	for(int i = 0; i < 10; i++)
	{
		float test = -(float)(rand()) / RANDMAX;
		printf("%0.5f\t%d\n", test, roundNum(test));
	}
	return 0;
}
