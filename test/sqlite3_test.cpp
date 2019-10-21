#include <gtest/gtest.h>
#include <sqlite3.h>

int callback(void *NotUsed, int argc, char **argv, char **azColName) {
  NotUsed = 0;
  for (int i = 0; i < argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

TEST(sqlite3, db_create) {
  const char *fileName = "test.db";
  sqlite3 *db;
  char *errMsg;
  int rc = sqlite3_open(fileName, &db);
  EXPECT_EQ(0, rc);

  rc = sqlite3_exec(
      db,
      "create table IF NOT EXISTS Friends(Id INTEGER PRIMARY KEY, Name TEXT);",
      NULL, NULL, &errMsg);
  EXPECT_EQ(0, rc);

  rc = sqlite3_exec(db, "INSERT INTO Friends(Name) VALUES ('Tom');", callback,
                    0, &errMsg);
  EXPECT_EQ(0, rc);

  sqlite3_close(db);
  rc = remove(fileName);
  EXPECT_EQ(0, rc);
}
