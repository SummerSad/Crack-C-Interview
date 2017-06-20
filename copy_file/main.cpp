#include <stdio.h>
#define BUFFER 10000

void copy_file(char *src_name, char *dest_name)
{
    FILE *src = fopen(src_name, "rb");
    if(src == NULL)
    {
        printf("No file\n");
        return;
    }
    FILE*dest = fopen(dest_name, "wb");
    fseek(src, 0, SEEK_SET);
    char *p = new char[BUFFER];
    int count;
    do
    {
        count = fread(p, sizeof(char), BUFFER, src);
        fwrite(p, sizeof(char), count, dest);
    }
    while(count == BUFFER);
    delete[]p;
    p = NULL;
}

int main()
{
    copy_file("1.pdf", "2.pdf");
    return 0;
}
