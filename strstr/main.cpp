#include <stdio.h>
#include <string.h>

//forward
char *my_strstr(char *src, char *sub)
{
    int len_sub = strlen(sub);
    char *p = src;
    while(*p)
    {
        bool Flag = true;
        for(int i = 0; i < len_sub; i++)
        {
            if(*(p + i) != *(sub + i))
                Flag = false;
        }
        if(Flag)
            return p;
        p++;
    }
    return NULL;
}

int main()
{
    char *src = "ABC123DEF";
    char *sub = "23D";
    printf("%s.\n", my_strstr(src, sub));
    return 0;
}
