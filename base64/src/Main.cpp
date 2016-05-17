#include <iostream>
#include "base64.h"
int main(int argc, char *argv[]) {
    std::string str = "我是中国人a";
    std::cout << base64_encode(reinterpret_cast<const unsigned char *>(str.c_str()), static_cast<int>(str.size())) << std::endl;
    return 0;
}
