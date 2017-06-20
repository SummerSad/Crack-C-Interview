#include <stdio.h>
#include <stdlib.h>

void Nhap(int *&arr, int n)
{
	if(n < 1)
		return;
	for(int i = 0; i < n; i++)
	{
		//realloc with sizeof
		arr = (int *)realloc(arr, sizeof(int) * (i + 1));
		printf("%dth: ", i);
		scanf("%d", &arr[i]);
	}
}

void findMax(int *arr, int n)
{
	if(n < 2)
		return;
	int Max, SecondMax;
	Max = SecondMax = arr[0];
	for(int i = 0; i < n; i++)
	{
		if(arr[i] > Max)
			Max = arr[i];
	}
	for(int i = 0; i < n; i++)
	{
		if(arr[i] > SecondMax && arr[i] < Max)
			SecondMax = arr[i];
	}
	printf("%d %d\n", Max, SecondMax);
}

typedef bool(*SoSanh)(int, int);

bool LonHon(int x, int y)
{
	return x > y;
}

void Test(int x, int y, SoSanh X)
{
	if(X(x, y))
		printf("True\n");
	else
		printf("False\n");
}

int main()
{
	int *arr = NULL;
	Nhap(arr, 5);
	findMax(arr, 5);
	free(arr);
	Test(4, 3, LonHon);
	return 0;
}
