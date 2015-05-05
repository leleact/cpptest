#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *pNext;
};

void AddElement(Node **, int);
void PrintLinkList(Node *);
Node *ReverseLinkList(Node *);

int main() {
	Node *pRoot = nullptr;
	for (int i = 1; i < 10; ++i) {
		AddElement(&pRoot, i);
	}
	PrintLinkList(pRoot);
	Node *reverseList = ReverseLinkList(pRoot);
	PrintLinkList(reverseList);
}

void AddElement(Node **pNode, int data) {
	if (nullptr == *pNode) {
		*pNode = new Node();	
		(*pNode)->data = data;
		(*pNode)->pNext = nullptr;
		return;
	}

	Node *pTemp = *pNode;
	while(pTemp->pNext){
		pTemp = pTemp->pNext;
	}

	pTemp->pNext = new Node();
	pTemp->pNext->data = data;
	pTemp->pNext->pNext = nullptr;
}

void PrintLinkList(Node *pNode) {
	while(pNode) {
		cout << "Node.data = [" << pNode->data << "], Node.pNext = [" << pNode->pNext << "]" << endl;;
		pNode = pNode->pNext;
	}
}

Node *ReverseLinkList(Node *pNode) {
	if (pNode || pNode->pNext)
		return nullptr;

	// 将链表第一个元素和第二个元素断开
	Node *pHead = pNode;
	Node *pCurr = pNode->pNext;
	Node *pReve;
	pNode->pNext = nullptr;

	while(pCurr) {
		pReve = pCurr->pNext;	

		pCurr->pNext = pHead;
		pHead = pCurr;

		pCurr = pReve;
	}

	pNode = pHead;
	return pNode;
}
