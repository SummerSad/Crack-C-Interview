#include <stdio.h>

struct Person
{
	char *Name;
	int Age;
	Person *Dad;
	Person *Mom;
};

Person Oldest(Person A)
{
	if(A.Dad == NULL && A.Mom == NULL)
		return A;
	if(A.Dad == NULL && A.Mom != NULL)
		return A.Age > Oldest(*(A.Mom)).Age ? A : Oldest(*(A.Mom));
	if(A.Dad != NULL && A.Mom == NULL)
		return A.Age > Oldest(*(A.Dad)).Age ? A : Oldest(*(A.Dad));
	if(A.Age > Oldest(*(A.Mom)).Age && A.Age > Oldest(*(A.Dad)).Age)
		return A;
	if(Oldest(*(A.Mom)).Age > A.Age && Oldest(*(A.Mom)).Age > Oldest(*(A.Dad)).Age)
		return Oldest(*(A.Mom));
	if(Oldest(*(A.Dad)).Age > A.Age && Oldest(*(A.Dad)).Age > Oldest(*(A.Mom)).Age)
		return Oldest(*(A.Dad));
}

int main()
{
	Person A, B, C, D;
	A.Name = NULL;
	A.Dad = &B;
	A.Mom = &C;
	A.Age = 8;
	B.Name = NULL;
	B.Dad = NULL;
	B.Mom = &D;
	B.Age = 18;
	C.Name = NULL;
	C.Dad = NULL;
	C.Mom = NULL;
	C.Age = 12;
	D.Name = NULL;
	D.Dad = NULL;
	D.Mom = NULL;
	D.Age = 10;
	printf("%d\n", Oldest(A).Age);
	return 0;
}
