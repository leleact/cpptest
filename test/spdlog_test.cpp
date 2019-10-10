#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include "gtest/gtest.h"

TEST(ExternalProject, spdlog) {
  auto console = spdlog::stderr_color_mt("console");
  console->info("spdlog output, welcome to spdlog!");
}
