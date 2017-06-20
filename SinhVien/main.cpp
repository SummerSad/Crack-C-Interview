#include <stdio.h>
#define MAX_NAME 50
#define MAX_CLASS 20

struct InfoStudent
{
	int ID;
	char Name[MAX_NAME + 1];
	int YearBorn;
	char Class[MAX_CLASS + 1];
	float Grade;
};

struct Node
{
	InfoStudent key;
	Node *next;
};

Node *getInfo()
{
	Node *p = new Node;
	printf("ID: ");
	scanf("%d", &p->key.ID);
	printf("Name: ");
	scanf("%s", &p->key.Name);
	printf("Year Born: ");
	scanf("%d", &p->key.YearBorn);
	printf("Class: ");
	scanf("%s", &p->key.Class);
	printf("Grade: ");
	scanf("%f", &p->key.Grade);
	p->next = NULL;
	return p;
}

int main()
{
	Node *p = getInfo();
	delete p;
	return 0;
}
