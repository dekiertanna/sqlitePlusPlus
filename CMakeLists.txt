cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)
project(sqlitePlusPlus VERSION 0.0.1 DESCRIPTION "C++ wrapper for sqlite3 library")
include(GNUInstallDirs)
enable_testing()
# Find SQLite3 library
find_package(SQLite3 REQUIRED)
find_package(GTest REQUIRED)
include_directories(${SQLite3_INCLUDE_DIRS})

# Add sqlitePlusPlus library target
add_library(sqlitePlusPlus STATIC
    src/sqlitePP.cpp
    src/DatabaseModel.hpp
    src/DatabaseModel.cpp
    src/SqliteTable.hpp
    src/SqliteTable.cpp)
set_target_properties(sqlitePlusPlus PROPERTIES
    VERSION ${PROJECT_VERSION}
    PUBLIC_HEADER include/sqlitePP.hpp)
target_include_directories(sqlitePlusPlus PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(sqlitePlusPlus PRIVATE ${SQLite3_LIBRARIES})

# Configure pkg-config file
configure_file(sqlitePlusPlus.pc.in sqlitePlusPlus.pc @ONLY)

# Install targets
install(TARGETS sqlitePlusPlus
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_BINARY_DIR}/sqlitePlusPlus.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

# Add test subdirectory and target
add_subdirectory(test)