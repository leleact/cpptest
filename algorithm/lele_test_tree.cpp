#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
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

template<typename T>
int DeepOfTheTree(Node<T> *);

template<typename T>
void PreOrderTree(Node<T> *pNode);

template<typename T>
void InOrderTree(Node<T> *pNode);

template<typename T>
void PostOrderTree(Node<T> *pNode);

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
  int deep = DeepOfTheTree(pRoot);
  cout << "Deep of The Tree : " << deep << endl;

  PreOrderTree(pRoot);
  cout << endl;
  InOrderTree(pRoot);
  cout << endl;
  PostOrderTree(pRoot);
  cout << endl;

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

template<typename T>
int DeepOfTheTree(Node<T> *pNode) {
  if (nullptr == pNode)
    return 0;

  int deep_left_tree = DeepOfTheTree(pNode->pLeft);
  int deep_right_tree = DeepOfTheTree(pNode->pRight);
  int deep = deep_left_tree > deep_right_tree ? deep_left_tree : deep_right_tree;

  return deep + 1;
}


template<typename T>
void PreOrderTree(Node<T> *pNode) {
  if (nullptr == pNode)
    return;
  cout << pNode->data << " ";
  PreOrderTree(pNode->pLeft);
  PreOrderTree(pNode->pRight);
}

template<typename T>
void InOrderTree(Node<T> *pNode) {
  if (nullptr == pNode)
    return;

  InOrderTree(pNode->pLeft);
  cout << pNode->data << " ";
  InOrderTree(pNode->pRight);
}

template<typename T>
void PostOrderTree(Node<T> *pNode) {
  if (nullptr == pNode)
    return;

  PostOrderTree(pNode->pLeft);
  PostOrderTree(pNode->pRight);
  cout << pNode->data << " ";
}
