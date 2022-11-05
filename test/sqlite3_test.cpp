#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <gtest/gtest.h>
#include <spdlog/spdlog.h>
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
      "create table if not exists friends(id integer primary key, name text);",
      NULL, NULL, &errMsg);
  EXPECT_EQ(0, rc);

  rc = sqlite3_exec(db, "INSERT INTO Friends(Name) VALUES ('Tom');", callback,
                    0, &errMsg);
  EXPECT_EQ(0, rc);

  sqlite3_close(db);
  rc = remove(fileName);
  EXPECT_EQ(0, rc);
}

TEST(sqlite3, statement) {
  spdlog::set_level(spdlog::level::trace);
  const char *filename = "test.db";
  char *errMsg = NULL;
  int rc = 0;
  sqlite3 *db;
  rc = sqlite3_open(filename, &db);
  ASSERT_EQ(0, rc);

  rc = sqlite3_exec(
      db, "create table if not exists people(name text primary key, age int);",
      NULL, NULL, &errMsg);
  if (rc != SQLITE_OK) {
    SPDLOG_DEBUG("{}", errMsg);
    sqlite3_free(errMsg);
  }
  ASSERT_EQ(0, rc);

  rc = sqlite3_exec(db,
                    "insert into people values('x', 1);insert into people "
                    "values('x1', 2);insert into people values('y', 2);",
                    NULL, NULL, &errMsg);
  if (rc != SQLITE_OK) {
    SPDLOG_DEBUG("{}", errMsg);
    sqlite3_free(errMsg);
  }
  ASSERT_EQ(0, rc);

  const char *query = "select * from people where name = ?";
  sqlite3_stmt *statement;
  rc = sqlite3_prepare_v2(db, query, strlen(query), &statement, NULL);
  if (rc != SQLITE_OK) {
    SPDLOG_DEBUG("{}", errMsg);
    sqlite3_free(errMsg);
  }
  ASSERT_EQ(0, rc);

  rc = sqlite3_bind_text(statement, 1, "x", 1, SQLITE_TRANSIENT);
  if (rc != SQLITE_OK) {
    SPDLOG_DEBUG("{}", errMsg);
    sqlite3_free(errMsg);
  }
  ASSERT_EQ(0, rc);

  while ((rc = sqlite3_step(statement)) == SQLITE_ROW) {
    const unsigned char *s1 = sqlite3_column_text(statement, 0);
    long i2 = sqlite3_column_int64(statement, 1);
    SPDLOG_DEBUG("s1 = {}, i2 = {}", fmt::ptr(s1), i2);
  }

  sqlite3_finalize(statement);

  remove(filename);
}
