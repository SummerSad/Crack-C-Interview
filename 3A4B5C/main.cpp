#include <stdio.h>
#define UNSOLVED -1
//fn=3f(n-1)+4f(n-2)+5f(n-3)

int calc_0dequy(int n)
{
	int *arr = new int[n + 1];
	arr[0] = 3;
	arr[1] = 4;
	arr[2] = 5;
	for(int i = 3; i <= n; i++)
	{
		arr[i] = 3 * arr[i - 1] + 4 * arr[i - 2] + 5 * arr[i - 3];
	}
	int result = arr[n];
	delete[]arr;
	return result;
}

int calc_dequy(int *arr, int n)
{
	if(arr[n] == UNSOLVED)
	{
		arr[n] = 3 * calc_dequy(arr, n - 1) + 4 * calc_dequy(arr, n - 2) + 5 * calc_dequy(arr, n - 3);
	}
	return arr[n];
}

int show_dequy(int n)
{
	int *arr = new int[n + 1];
	arr[0] = 3;
	arr[1] = 4;
	arr[2] = 5;
	for(int i = 3; i <= n; i++)
	{
		arr[i] = UNSOLVED;
	}
	int result = calc_dequy(arr, n);
	delete[]arr;
	return result;
}

int test(int n)
{
	if(n == 0)
		return 3;
	if(n == 1)
		return 4;
	if(n == 2)
		return 5;
	return 3 * test(n - 1) + 4 * test(n - 2) + 5 * test(n - 3);
}

int main()
{
	for(int i = 0; i < 50; i++)
	{
		printf("%d %d\n", calc_0dequy(i), show_dequy(i));
		//printf("%d\n", test(i));
	}
	return 0;
}
