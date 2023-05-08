enable_testing()

# Set the project name
project(sqlitePlusPlusTest)

# Add the test executable
add_executable(ut-run test_main.cpp 
mylib_test.cpp
UTDatabaseModel.cpp)

target_include_directories(ut-run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)

# Link the test executable with sqlitePlusPlus and GTest
target_link_libraries(ut-run PRIVATE sqlitePlusPlus GTest::GTest GTest::Main)

# Add a test
gtest_discover_tests(ut-run)
