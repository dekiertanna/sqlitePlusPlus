#include "DatabaseModel.hpp"

#include <gtest/gtest.h>

TEST(UTDatabaseModel, ShoildInitialize) { DatabaseModel(); }

TEST(UTDatabaseModel, ShouldCreateTable) {
  DatabaseModel dbModel = DatabaseModel();
  ASSERT_NE(dbModel.createTable("Person"), std::nullopt);
}

TEST(UTDatabaseModel, ShouldReturnNulloptOnInsertingDuplicate) {
  DatabaseModel dbModel = DatabaseModel();
  ASSERT_NE(dbModel.createTable("Person"), std::nullopt);
  ASSERT_EQ(dbModel.createTable("Person"), std::nullopt);
}
