#include "sqlitePP.hpp"
#include <stdexcept>

sqlitePlusPlus::sqlitePlusPlus(const std::string& filename)
{
  int rc = sqlite3_open(filename.c_str(), &db_);
  if (rc != SQLITE_OK) {
    throw std::runtime_error("Failed to open database: " +
                             std::string(sqlite3_errmsg(db_)));
  }
}

sqlitePlusPlus::~sqlitePlusPlus()
{
  sqlite3_close(db_);
}

void
sqlitePlusPlus::exec(const std::string& sql)
{
  char* errmsg;
  int rc = sqlite3_exec(db_, sql.c_str(), nullptr, nullptr, &errmsg);
  if (rc != SQLITE_OK) {
    throw std::runtime_error("Failed to execute SQL statement: " +
                             std::string(errmsg));
  }
  sqlite3_free(errmsg);
}

sqlitePlusPlus::statement_ptr
sqlitePlusPlus::prepare(const std::string& sql)
{
  sqlite3_stmt* stmt;
  int rc = sqlite3_prepare_v2(db_, sql.c_str(), -1, &stmt, nullptr);
  if (rc != SQLITE_OK) {
    throw std::runtime_error("Failed to prepare SQL statement: " +
                             std::string(sqlite3_errmsg(db_)));
  }
  return statement_ptr(stmt, &sqlite3_finalize);
}