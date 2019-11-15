#include <chrono>
#include <gtest/gtest.h>
#include <thread>

TEST(CHRONO, MilliSec) {
  auto now = std::chrono::system_clock::now();
  auto d = now.time_since_epoch();
  auto sec = std::chrono::duration_cast<std::chrono::seconds>(d);
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(d);

  std::cout << "sec: " << sec.count() << std::endl;
  std::cout << "ms: " << ms.count() << std::endl;
}

TEST(chrono, count_down) {
  using std::chrono::duration_cast;
  using std::chrono::hours;
  using std::chrono::minutes;
  using std::chrono::seconds;

  auto now = std::chrono::system_clock::now().time_since_epoch();
  auto days = duration_cast<std::chrono::duration<int, std::ratio<86400>>>(now);
  auto end = days + hours{9} + minutes{40};
  auto count = duration_cast<seconds>(end - now).count();
  std::cout << "Total count: " << count << std::endl;
  // for (int i = count; i > 0; i--) {
  // std::cout << i << std::endl;
  // std::this_thread::sleep_for(std::chrono::seconds{1});
  //}
}
