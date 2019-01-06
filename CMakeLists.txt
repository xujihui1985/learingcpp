cmake_minimum_required(VERSION 3.13)
project(sqlite)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp Handle.cpp SQLite.h thirdparty/sqlite3.c thirdparty/sqlite3.h)


add_executable(sqlite ${SOURCE_FILES})
