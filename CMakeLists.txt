cmake_minimum_required(VERSION 3.14)

#Name for the executable
project(Helium)

#Set C++ standard to 17 or higher
set(CMAKE_CXX_STANDARD 17)

#Export compilation database in JSON format
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

#Directories to include
include_directories(include)

#All the source files
set(SOURCES sources/io.cpp sources/helium.cpp sources/lexer.cpp sources/token.cpp sources/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE stdc++)