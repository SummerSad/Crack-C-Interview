#pragma once
#include <iostream>
using namespace std;

struct SNode {
	int key;
	SNode *next;
};

struct DNode {
	int key;
	DNode *prev;
	DNode *next;
};

SNode *getSNode(int key);
void addSHead(SNode *&head, int key);
void delSHead(SNode *&head);
void printSNode(SNode *head);
void reverseSNode(SNode *&head);
