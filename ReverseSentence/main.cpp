#include <stdio.h>
#include <string.h>
#define SPACE ' '
// go to heaven -> heaven to go
//step 1: reverse invidual words
//step 2: reverse sentence
void reverseWord(char *begin, char *end)
{
    char *p = begin;
    char *q = end;
    for(; p < q; p++, q--)
    {
        char temp = *p;
        *p = *q;
        *q = temp;
    }
}

void reverseSentence(char *src)
{
    int len = strlen(src);
    int i, j;
    for(i = 0; i < len; i++)
    {
        if(src[i] != SPACE)
        {
            for(j = i; j < len; j++)
            {
                if(src[j + 1] == '\0' || src[j + 1] == SPACE)
                {
                    reverseWord(src + i, src + j);
                    break;
                }
            }
            i=j+1;
        }
    }
    reverseWord(src,src+len-1);
}

int main()
{
    char src[] = "welcome my life";
    reverseSentence(src);
    printf("%s.", src);
    return 0;
}
