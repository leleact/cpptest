#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char src[] = "The world is beautiful";

	char *pstr = strtok(src, " ");
	//cout << pstr << endl;	
	while(pstr != nullptr) {
		cout << pstr << endl;	
		pstr = strtok(nullptr, " ");
	}

	return 0;
}
