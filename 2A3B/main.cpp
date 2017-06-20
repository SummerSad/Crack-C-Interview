#include <stdio.h>

//f(n)=2f(n-1)+3f(n-2)
int f_calc(int n, int a)
{
	int *arr = new int[n + 1];
	arr[0] = a;
	arr[1] = 2 * a;
	for(int i = 2; i <= n; i++)
	{
		arr[i] = 2 * arr[i - 1] + 3 * arr[i - 2];
	}
	int result = arr[n];
	delete[]arr;
	return result;
}

int main()
{
	for(int i = 0; i < 15; i++)
	{
		printf("%d\n", f_calc(i, 3));
	}
	return 0;
}
