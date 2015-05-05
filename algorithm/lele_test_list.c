#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node {
	int data;
	struct node *pNext;
} Node;

void AddElement(Node *, int);
void PrintList(Node *);

int main() {
	Node root;
	memset(&root, 0x00, sizeof(Node));

	for (int i = 1; i < 5; ++i) {
		AddElement(&root, i);
	}

	PrintList(&root);
	return 0;
}

void AddElement(Node *pNode, int data) {
	Node *pTemp = pNode;
	while(pTemp->pNext) {
		pTemp = pTemp->pNext;
	}

	pTemp->pNext = (Node *)malloc(sizeof(Node));
	pTemp->pNext->pNext = NULL;
	pTemp->pNext->data = data;
}

void PrintList(Node *pNode) {
	Node *pTemp = pNode;
	while(pTemp) {
		printf("pNode->data = [%d]\n", pTemp->data);	
		pTemp = pTemp->pNext;
	}
}
