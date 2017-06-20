#include <stdio.h>
#include <string.h>

void my_swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permu(char *str, int i, int len)
{
    if(i == len)
        printf("%s\n", str);
    else
    {
        int j;
        for(j = i; j <= len; j++)
        {
            my_swap(str + i, str + j);
            permu(str, i + 1, len);
            my_swap(str + i, str + j);
        }
    }
}

int main()
{
    char s[] = "abc";
    int len = strlen(s);
    permu(s, 0, len - 1);
    return 0;
}
