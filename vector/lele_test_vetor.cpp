#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
class MyString {
public:
  MyString():data(new char[16]) {
    cout << "default constructor" << endl;;
    memset(data, 0x00, sizeof(*data));
  };

  MyString(const char *pchar) : data(new char[strlen(pchar) + 1]) {
    cout << "constructor const char *" << endl;
    strcpy(data, pchar);
  }

  MyString(const MyString &s) : data(new char[s.size() + 1]) {
    cout << "constuctor const MyString &" << endl;
    strcpy(data, s.c_str());
  }

  MyString &operator=(const MyString &s) {
    cout << "operator = MyString"  << endl;
    if (this != &s) {
      if (this->size() != s.size()) {
        delete[] data; 
        this->data = new char[s.size() + 1];
        strcpy(data, s.c_str());
      } else {
        strcpy(data, s.c_str());
      }
    }
    return *this;
  }

  MyString &operator=(const char *pchar) {
    cout << "operator = const char *"  << endl;
    if (this->size() != strlen(pchar)) {
      delete[] data; 
      this->data = new char[strlen(pchar) + 1];
      strcpy(data, pchar);
    } else {
      strcpy(data, pchar);
    }
    return *this;
  }

  size_t size() const {
    return strlen(data);
  }

  const char *c_str() const {
    return data; 
  }

  ~MyString() {
    cout << "destructor" << endl;;
    delete[] data; 
    data = nullptr;
  }

private:
  char *data;
};

int InitVectorTest();
template<typename T>
int ShowVectorElement(vector<T> &);

int main() {
  InitVectorTest();

  return 0;
}

int InitVectorTest() {
  vector<int> ivec;
  vector<int> ivec2(ivec);
  vector<int> ivec3 = ivec;

  return 0;
}
