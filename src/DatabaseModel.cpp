#include "DatabaseModel.hpp"
#include "SqliteTable.hpp"

bool DatabaseModel::createTable(const std::string& tableName) {
  auto newTable = tables_.insert(SqliteTable(tableName));
  if(newTable.second)
  {
    return true;
  }
  else
  {
    return false;
  }
}