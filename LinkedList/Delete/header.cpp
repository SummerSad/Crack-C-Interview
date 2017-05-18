#include "header.h"

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
void delSNode(SNode *&head, SNode *X)
{
	if (head != NULL && X != NULL)
	{
		if (head == X)
			delSHead(head);
		else
		{
			SNode *SPrev = NULL;
			SNode *SCur = head;
			for (; SCur != NULL && SCur != X; SPrev = SCur, SCur = SCur->next)
				;
			if (SCur == X)
			{
				SPrev->next = SCur->next;
				delete SCur;
			}
		}
	}

}
