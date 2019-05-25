#include "spdlog/spdlog.h"
#include <add.hpp>
#include <iostream>
int main() {
    auto console = spdlog::stdout_color_mt("console");
    int a = 10;
    int b = 20;
    std::cout << add(a, b) << std::endl;
    console->info("Welcome to spdlog!");
    return 0;
}
