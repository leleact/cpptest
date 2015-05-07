#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

template <typename T>
struct Node {
  Node *pLeft;
  Node *pRight;
  T data;
};

template <typename T = int>
Node<T> * BuildTree(vector<T> &, int);

template <typename T = int>
void PrintTreeByLevel(Node<T> *);

int main() {
  vector<int> vec;
  vec.push_back(9);
  vec.push_back(5);
  vec.push_back(8);
  vec.push_back(2);
  vec.push_back(7);
  int index = 1;
  Node<int> *pRoot = BuildTree<int>(vec, index);
  PrintTreeByLevel(pRoot);

  return 0;
}

template <typename T>
Node<T> * BuildTree(vector<T> &vec, int index) {

  if (index > static_cast<int>(vec.size()))
    return nullptr;

  Node<T> *pNode = new Node<T>();
  pNode->data =  vec[index - 1];
  pNode->pLeft = BuildTree(vec, 2 * index);
  pNode->pRight = BuildTree(vec, 2 * index + 1);

  return pNode;
}

// 分层遍历 
template<typename T>
void PrintTreeByLevel(Node<T> *pNode) {
  vector<Node<T> *> vec;
  if (pNode == nullptr) {
    return;
  }

  vec.push_back(pNode);
  unsigned long  cur = 0;
  unsigned long  last = 1;
  while(cur < vec.size()) {  
    last = vec.size();
    while(cur < last) {
      cout << vec[cur]->data << " " ;
      if (vec[cur]->pLeft)
        vec.push_back(vec[cur]->pLeft);

      if (vec[cur]->pRight)
        vec.push_back(vec[cur]->pRight);
      cur++;
    }

    cout << endl;
  }
}
