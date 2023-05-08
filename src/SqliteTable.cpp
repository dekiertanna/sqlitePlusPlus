#include "SqliteTable.hpp"

SqliteTable::SqliteTable(const std::string& tableName) : tableName_{tableName} {}
const std::string SqliteTable::getTableName() const
{
    return tableName_;
}

bool SqliteTable::operator==(const SqliteTable &other) const {
  return tableName_ == other.tableName_;
}