#include <gtest/gtest.h>
#include <sqlite3.h>

TEST(sqlite3, db_create) {
  const char *fileName = "test.db";
  sqlite3 *db;
  int rc = sqlite3_open(fileName, &db);
  EXPECT_EQ(0, rc);
  sqlite3_close(db);
  rc = remove(fileName);
  EXPECT_EQ(0, rc);
}
