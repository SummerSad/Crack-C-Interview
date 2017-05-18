#pragma once
#include <iostream>
using namespace std;

struct SNode {
	int key;
	SNode *next;
};

SNode *getSNode(int key);
void addSHead(SNode *&head, int key);
void printSNode(SNode *head);

void delSHead(SNode *&head);
void delSNode(SNode *&head, SNode *N);
