#include "DatabaseModel.hpp"

#include <gtest/gtest.h>

TEST(UTDatabaseModel, ShoildInitialize) { DatabaseModel(); }

TEST(UTDatabaseModel, ShouldCreateTable) {
  DatabaseModel dbModel = DatabaseModel();
  ASSERT_TRUE(dbModel.createTable("Person"));
}

TEST(UTDatabaseModel, ShouldReturnFalseOnInsertingDuplicate) {
  DatabaseModel dbModel = DatabaseModel();
  ASSERT_TRUE(dbModel.createTable("Person"));
  ASSERT_FALSE(dbModel.createTable("Person"));
}
