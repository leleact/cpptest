#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include "gtest/gtest.h"

#define LOGD(logger, fmt, ...)                                                 \
  {                                                                            \
    logger->debug("{}::{}()#{}: " fmt, __FILE__, __FUNCTION__, __LINE__,       \
                  __VA_ARGS__);                                                \
  }

TEST(ExternalProject, spdlog) {
  auto console = spdlog::stderr_color_mt("console");
  console->set_level(spdlog::level::trace);
  console->info("spdlog output, welcome to spdlog!");
  LOGD(console, "{}", "xxx");
}
