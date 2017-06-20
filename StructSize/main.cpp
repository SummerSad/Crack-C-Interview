#include <stdio.h>
//size of struct without sizeof()

struct Point
{
    int x, y;
};

struct Circle
{
    Point O;
    int R;
};

int main()
{
    printf("%d\n",sizeof(Circle));
    Circle *p;
    //p+1 is next Circle
    //p+1 <-> p : sizeof(Circle)
    printf("%d\n", (char *)(p + 1) - (char*)p);
    return 0;
}
