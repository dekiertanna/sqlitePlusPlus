#pragma once

#include "sqlite3.h"
#include <memory>
#include <string>

class sqlitePlusPlus {
public:
  using statement_ptr =
      std::unique_ptr<sqlite3_stmt, decltype(&sqlite3_finalize)>;

  sqlitePlusPlus(const std::string &filename);
  ~sqlitePlusPlus();

  void exec(const std::string &sql);
  statement_ptr prepare(const std::string &sql);

private:
  sqlite3 *db_;
};