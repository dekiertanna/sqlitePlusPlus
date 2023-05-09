#include <gtest/gtest.h>
#include <sqlite3.h>

#include "sqlitePP.hpp"

TEST(SQLitePPTest, SimpleTest) {
  // Create an instance of the sqlitePlusPlus class
  sqlitePlusPlus db(":memory:");

  std::cerr << "I am being executed" << std::endl;

  // Execute a simple SQL statement
  EXPECT_NO_THROW(
      db.exec("CREATE TABLE test (id INTEGER PRIMARY KEY, name TEXT)"));
}