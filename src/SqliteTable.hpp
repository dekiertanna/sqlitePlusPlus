#pragma once

#include <string>
#include <list>
#include <map>

class SqliteTable {
public:
  enum class EFieldType
  {
    EInteger,
    EReal,
    EText,  
    EBlob
  };
  
using Fields = std::list<std::map<std::string, EFieldType>>;

  SqliteTable() = delete;
  SqliteTable(const std::string &tableName);
  const bool addField(const std::string& name, const EFieldType& fieldType);
  const std::string getTableName() const;
  bool operator==(const SqliteTable &other) const;

private:
  std::string tableName_;
  Fields fields_;
};

namespace std {
template <> struct hash<SqliteTable> {
  std::size_t operator()(const SqliteTable &table) const {
    return std::hash<std::string>()(table.getTableName());
  }
};
} // namespace std