#pragma once

#include <string>

class SqliteTable {
public:
  SqliteTable() = delete;
  SqliteTable(const std::string &tableName);
  const std::string getTableName() const;
  bool operator==(const SqliteTable &other) const;

private:
  std::string tableName_;
};

namespace std {
template <> struct hash<SqliteTable> {
  std::size_t operator()(const SqliteTable &table) const {
    return std::hash<std::string>()(table.getTableName());
  }
};
} // namespace std