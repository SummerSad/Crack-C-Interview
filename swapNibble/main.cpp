#include <stdio.h>
// 100 is (0110)(0100)
// (0110) is a nibble
// swap (0100)(0110) is 70
//nibble 4 bit

char swapNibble(char c)
{
	char result;
	//c: XXXXYYYY
	//c>>4: 0000XXXX
	//c<<4: YYYY0000
	result = c >> 4 | c << 4;
	return result;
}

int main()
{
	char c = 100;
	printf("%d\n", swapNibble(c));
	return 0;
}
