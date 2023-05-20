#include "SqliteTable.hpp"

#include <gtest/gtest.h>
#include <memory>

class UTSqliteTable : public ::testing::Test {
protected:
void SetUp() override
{
    sut = std::make_unique<SqliteTable>("TestTable");
}

void TearDown() override {

}
std::unique_ptr<SqliteTable> sut;
};

TEST_F(UTSqliteTable, ShouldReturnNameOfTable)
{
    ASSERT_EQ(sut->getTableName(), "TestTable");
}

TEST_F(UTSqliteTable, ShouldAddFieldOfTypeInteger)
{
    ASSERT_TRUE(sut->addField("testInteger", SqliteTable::EFieldType::EInteger));
}

TEST_F(UTSqliteTable, ShouldAddFieldOfTypeReal)
{
    ASSERT_TRUE(sut->addField("testInteger", SqliteTable::EFieldType::EReal));
}

TEST_F(UTSqliteTable, ShouldAddFieldOfTypeText)
{
    ASSERT_TRUE(sut->addField("testInteger", SqliteTable::EFieldType::EText));
}

TEST_F(UTSqliteTable, ShouldAddFieldOfTypeBlob)
{
    ASSERT_TRUE(sut->addField("testInteger", SqliteTable::EFieldType::EBlob));
}