#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
struct Node {
  Node *pleft_child;
  Node *pright_child;
  T data;
};

template <typename T = int>
Node<T> * BuildTree(vector<T> &, int);

template <typename T = int>
void PrintTreeByLevel(Node<T> *);

template<typename T>
int DeepOfTheTree(Node<T> *);

template<typename T>
void PreOrderTree(Node<T> *pnode);

template<typename T>
void InOrderTree(Node<T> *pnode);

template<typename T>
void PostOrderTree(Node<T> *pnode);

template<typename T>
void PreOrderTreeByLoop(Node<T> *pnode);

template<typename T>
void InOrderTreeByLoop(Node<T> *pnode);

template<typename T>
void PostOrderTreeByLoop(Node<T> *pnode);

int main() {
  vector<int> vec;
  vec.push_back(9);
  vec.push_back(5);
  vec.push_back(8);
  vec.push_back(2);
  vec.push_back(7);
  int index = 1;
  Node<int> *proot = BuildTree<int>(vec, index);
  PrintTreeByLevel(proot);
  int deep = DeepOfTheTree(proot);
  cout << "Deep of The Tree : " << deep << endl;

  PreOrderTree(proot);
  cout << endl;
  InOrderTree(proot);
  cout << endl;
  PostOrderTree(proot);
  cout << endl;
  cout << "先序遍历: ";
  PreOrderTreeByLoop(proot);
  cout << endl;
  cout << "中序遍历: ";
  InOrderTreeByLoop(proot);
  cout << endl;
  cout << "后序遍历: ";
  PostOrderTreeByLoop(proot);
  cout << endl;

  return 0;
}

template <typename T>
Node<T> * BuildTree(vector<T> &vec, int index) {

  if (index > static_cast<int>(vec.size()))
    return nullptr;

  Node<T> *pnode = new Node<T>();
  pnode->data =  vec[index - 1];
  pnode->pleft_child = BuildTree(vec, 2 * index);
  pnode->pright_child = BuildTree(vec, 2 * index + 1);

  return pnode;
}

// 分层遍历 
template<typename T>
void PrintTreeByLevel(Node<T> *pnode) {
  vector<Node<T> *> vec;
  if (pnode == nullptr) {
    return;
  }

  vec.push_back(pnode);
  unsigned long  cur = 0;
  unsigned long  last = 1;
  while(cur < vec.size()) {  
    last = vec.size();
    while(cur < last) {
      cout << vec[cur]->data << " " ;
      if (vec[cur]->pleft_child)
        vec.push_back(vec[cur]->pleft_child);

      if (vec[cur]->pright_child)
        vec.push_back(vec[cur]->pright_child);
      cur++;
    }

    cout << endl;
  }
}

template<typename T>
int DeepOfTheTree(Node<T> *pnode) {
  if (nullptr == pnode)
    return 0;

  int deep_left_tree = DeepOfTheTree(pnode->pleft_child);
  int deep_right_tree = DeepOfTheTree(pnode->pright_child);
  int deep = deep_left_tree > deep_right_tree ? deep_left_tree : deep_right_tree;

  return deep + 1;
}


template<typename T>
void PreOrderTree(Node<T> *pnode) {
  if (nullptr == pnode)
    return;
  cout << pnode->data << " ";
  PreOrderTree(pnode->pleft_child);
  PreOrderTree(pnode->pright_child);
}

template<typename T>
void InOrderTree(Node<T> *pnode) {
  if (nullptr == pnode)
    return;

  InOrderTree(pnode->pleft_child);
  cout << pnode->data << " ";
  InOrderTree(pnode->pright_child);
}

template<typename T>
void PostOrderTree(Node<T> *pnode) {
  if (nullptr == pnode)
    return;

  PostOrderTree(pnode->pleft_child);
  PostOrderTree(pnode->pright_child);
  cout << pnode->data << " ";
}

template<typename T>
void PreOrderTreeByLoop(Node<T> *pnode) {
  if (nullptr == pnode)
    return;

  stack<Node<T> *> node_stack; 
  while(!node_stack.empty() || pnode) {
    while(pnode) {
      cout << pnode->data << " "; 
      node_stack.push(pnode);
      pnode = pnode->pleft_child;
    }

    if (!node_stack.empty()) {
      pnode = node_stack.top();
      node_stack.pop();
      pnode = pnode->pright_child;
    }
  }
}

template<typename T>
void InOrderTreeByLoop(Node<T> *pnode) {
  if (nullptr == pnode)
    return;
  stack<Node<T> *> node_stack;
  while(pnode || !node_stack.empty()) {
    while(pnode) {
      node_stack.push(pnode); 
      pnode = pnode->pleft_child;
    }

    if (!node_stack.empty()) {
      pnode = node_stack.top(); 
      cout << pnode->data << " ";
      node_stack.pop();
      pnode = pnode->pright_child;
    }
  }
}

template<typename T>
void PostOrderTreeByLoop(Node<T> *pnode) {
  if (nullptr == pnode)
    return;
  stack<Node<T> *> node_stack;
  Node<T> *pre = nullptr;
  while(pnode || !node_stack.empty()) {
    while(pnode) {
      node_stack.push(pnode); 
      pnode = pnode->pright_child;
    }

    pnode = node_stack.top(); 
    if (pnode->pright_child == nullptr || pnode->pright_child == pre) {
      cout << pnode->data << " ";
      node_stack.pop();
      pre = pnode;
      pnode = nullptr;
    } else {
      pnode = pnode->pright_child;
    }
  }
}
