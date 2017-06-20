#include <stdio.h>


bool isPower2(int n)
{
    if(!(n & (n - 1)) && n)
        return true;
    return false;
}
int main()
{
    for(int i = 2; i <= 20; i++)
        printf("%d %d\n", i,isPower2(i));
    return 0;
}
