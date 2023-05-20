#include "SqliteTable.hpp"

SqliteTable::SqliteTable(const std::string& tableName) : tableName_{tableName} {}
const std::string SqliteTable::getTableName() const
{
    return tableName_;
}

bool SqliteTable::operator==(const SqliteTable &other) const {
  return tableName_ == other.tableName_;
}

const bool SqliteTable::addField(const std::string& name, const EFieldType& fieldType)
{
  for (const auto& field : fields_)
  {
    if(field.find(name) != field.end())
    {
      return false;
    }
  }

  std::map<std::string, EFieldType> toInsert;
  toInsert[name] = fieldType;
  fields_.push_back(toInsert);
  return true;
}