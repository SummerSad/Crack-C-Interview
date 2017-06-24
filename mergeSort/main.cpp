#include <stdio.h>

void merge(int *A, int from, int mid, int to)
{
	// merge (from->mid) with (mid+1->to)
	if(from != mid || mid != to)
	{
		int size_1 = mid - from + 1;
		int *A1 = new int[size_1];
		int size_2 = to - mid;
		int * A2 = new int[to - mid];
		for(int i = 0; i < size_1; i++)
		{
			A1[i] = A[i + from];
		}
		for(int i = 0; i < size_2; i++)
		{
			A2[i] = A[i + from + size_1];
		}
		int i, j, k;
		i = j = 0;
		k = from;
		while(i < size_1 && j < size_2)
		{
			if(A1[i] < A2[j])
			{
				A[k++] = A1[i++];
			}
			else
			{
				A[k++] = A2[j++];
			}
		}
		if(i == size_1)
		{
			while(j < size_2)
			{
				A[k++] = A2[j++];
			}
		}
		else
		{
			while(i < size_1)
			{
				A[k++] = A1[i++];
			}
		}
		delete[]A1;
		delete[]A2;
	}

}

void mergeSort(int *A, int from, int to)
{
	if(from < to)
	{
		int mid = from + (to - from) / 2;
		mergeSort(A, from, mid);
		mergeSort(A, mid + 1, to);
		// run until from == to
		merge(A, from, mid, to);
	}
}

void print_arr(int *A, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main()
{
	int A[] = {9, 8, 7, 5, 4, -3, 2, 1, -2};
	int size = sizeof(A) / sizeof(A[0]);
	mergeSort(A, 0, size - 1);
	print_arr(A, size);
	return 0;
}
