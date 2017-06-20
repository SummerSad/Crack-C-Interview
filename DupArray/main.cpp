#include <stdio.h>
//remove duplicate in array

bool isDup(int *A, int size, int pos)
{
    if(pos >= size)
        return false;
    for(int i = 0; i < pos; i++)
    {
        if(A[i] == A[pos])
            return true;;
    }
    return false;
}

void removePos(int *A, int &size, int pos)
{
    if(pos >= 0 && pos < size)
    {
        for(int i = pos; i < size - 1; i++)
        {
            A[i] = A[i + 1];
        }
        size--;
    }
}

void removeDup(int *A, int &size)
{
    for(int i = 0; i < size; i++)
    {
        if(isDup(A, size, i))
        {
            removePos(A, size, i);
            i--; //Xet tiep tai vi tri i
        }
    }
}

void removeDup2(int *A, int &size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(A[j] == A[i])
            {
                // remove A[j]
                for(int temp = j; temp < size - 1; temp++)
                {
                    A[temp] = A[temp + 1];
                }
                size--;
                j--; // trick to keep checking A[j]
            }
        }
    }
}

void printArr(int *A, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 1, 2, 1, 2, 3, 4, 3, 4, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *A = arr;
    removeDup2(A, size);
    printArr(A, size);
    return 0;
}
