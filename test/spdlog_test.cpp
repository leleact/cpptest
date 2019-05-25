#include "spdlog/spdlog.h"
#include "gtest/gtest.h"

TEST(ExternalProject, spdlog) {
    auto console = spdlog::stdout_color_mt("console");
    console->info("spdlog output, welcome to spdlog!");
}
