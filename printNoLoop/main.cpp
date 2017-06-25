#include <stdio.h>

// print 1->100 without loop
// using recursion

void printN(int n)
{
	if(n > 0)
	{
		printf("%d\n", n);
		printN(n - 1);
	}

}

int main()
{
	printN(10);
	return 0;
}
