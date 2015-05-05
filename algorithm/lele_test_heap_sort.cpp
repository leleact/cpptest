#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv) {
	if (argc != 3) {
		cout << "Please Use : Heap_sort <Filename1> <Filename2>" << endl;
		exit(1);
	}

	string filename1(*(argv + 1));
	string filename2(*(argv + 2));

}


