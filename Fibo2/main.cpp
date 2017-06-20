#include <stdio.h>
#include <math.h>

int Fibo(int n)
{
    // Gia tri dau
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 2;

    for(int i = 3; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    int result = arr[n];
    delete[]arr;
    return result;
}

bool isPerfectSquare(int n)
{
    int s = (int)sqrt(n);
    return s * s == n;
}

//A number is Fibonacci if and only if one or both of
//(5*n2 + 4) or (5*n2 – 4) is a perfect square
bool isFibo(int n)
{
    return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}

int main()
{
    int n = 10;
    for(int i = 0; i < n; i++)
    {
        printf("%d %d\n", Fibo(i), isFibo(Fibo(i)));
    }
    return 0;
}
