#pragma once

#include <string>
#include <unordered_set>
#include <optional>

#include "SqliteTable.hpp"

class DatabaseModel {
public:
  std::optional<SqliteTable> createTable(const std::string& tableName);

private:
  std::unordered_set<SqliteTable> tables_;
};