#include "LinkedList.h"

SNode *getSNode(int key)
{
	SNode *temp = new SNode;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

void addSHead(SNode *&head, int key)
{
	SNode *p = getSNode(key);
	if (p != NULL) //protect memory
	{
		if (head == NULL)
			head = p;
		else
		{
			p->next = head;
			head = p;
		}
	}
}
void delSHead(SNode *&head)
{
	if (head != NULL)
	{
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
		}
		else
		{
			SNode *p = head;
			head = head->next;
			delete p;
		}
	}
}
void printSNode(SNode *head)
{
	if (head == NULL)
		cout << "NULL" << endl;
	else
	{
		cout << head->key << "->";
		printSNode(head->next);
	}
}
void reverseSNode(SNode *&head)
{
	SNode *prev = NULL;
	SNode *cur = head;
	while (cur != NULL)
	{
		SNode *temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;;
	}
	head = prev;
}
