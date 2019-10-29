#include <cstdio>
#include <ctime>
#include <gtest/gtest.h>

TEST(TIME, nanoseconds) {
  timespec ts{0, 0};
  clock_gettime(CLOCK_REALTIME, &ts);
  printf("seconds: %ld\nnanoseconds: %ld\n", ts.tv_sec, ts.tv_nsec);
  printf("real time: %.9lf\n", (double)(ts.tv_sec + 1.0e-9 * ts.tv_nsec));
}
