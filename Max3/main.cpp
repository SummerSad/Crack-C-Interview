#include <stdio.h>

int max3(int x, int y, int z)
{
    return (x > y) ? (x > z ? x : z) : (y > z ? y : z);
}

int main()
{
    printf("%d\n", max3(12, 23, 34));
    return 0;
}
