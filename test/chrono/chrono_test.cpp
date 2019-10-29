#include <chrono>
#include <gtest/gtest.h>

TEST(CHRONO, MilliSec) {
  auto now = std::chrono::system_clock::now();
  auto d = now.time_since_epoch();
  auto sec = std::chrono::duration_cast<std::chrono::seconds>(d);
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(d);

  std::cout << "sec: " << sec.count() << std::endl;
  std::cout << "ms: " << ms.count() << std::endl;
}
