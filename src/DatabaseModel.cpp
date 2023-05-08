#include "DatabaseModel.hpp"
#include "SqliteTable.hpp"

std::optional<SqliteTable> DatabaseModel::createTable(const std::string& tableName) {
  auto newTable = tables_.insert(SqliteTable(tableName));
  if(newTable.second)
  {
    return (*newTable.first);
  }
  else
  {
    return std::nullopt;
  }
}