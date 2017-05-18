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
void delSAll(SNode *&head)
{
	while (head != NULL)
		delSHead(head);
}

DNode *getDNode(int key)
{
	DNode *temp = new DNode;
	temp->key = key;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
void addDHead(DNode *&head, int key)
{
	DNode *p = getDNode(key);
	if (p != NULL) //protect memory
	{
		if (head == NULL)
			head = p;
		else
		{
			head->prev = p;
			p->next = head;
			head = p;
		}
	}
}
void delDHead(DNode *&head)
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
			DNode *p = head;
			head = head->next;
			head->prev = NULL;
			delete p;
		}
	}
}
void printDNode(DNode *head)
{
	if (head == NULL)
		cout << "NULL" << endl;
	else
	{
		cout << head->key << "->";
		printDNode(head->next);
	}
}
void reverseDNode(DNode *&head)
{
	DNode *DPrev = NULL;
	DNode *DCur = head;
	while (DCur != NULL)
	{
		DNode *temp = DCur->next;
		//Dao chieu
		DCur->next = DPrev;
		DCur->prev = temp;
		if (DPrev != NULL)
			DPrev->prev = DCur;
		//Next DNode
		DPrev = DCur;
		DCur = temp;
	}
	head = DPrev;
}
void delDAll(DNode *&head)
{
	while (head != NULL)
		delDHead(head);
}
