#include <stdio.h>

// return position
bool binarySearch(int *A, int from, int to, int x, int &pos)
{
	if(from == to)
	{
		if(A[from] == x)
		{
			pos = from;
			return true;
		}
		return false;
	}
	int mid = from + (to - from) / 2; //trick
	bool flag_1 = binarySearch(A, from, mid, x, pos);
	bool flag_2 = binarySearch(A, mid + 1, to, x, pos);
	if(flag_1)
		return true;
	if(flag_2)
		return true;
	return false;
}

int main()
{
	int A[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};
	int size = sizeof(A) / sizeof(A[0]);
	int pos;
	for(int i = 0; i < 12; i++)
	{
		if(binarySearch(A, 0, size - 1, i, pos))
			printf("%d\n", pos);
		else
			printf("None\n");
	}
	return 0;
}
