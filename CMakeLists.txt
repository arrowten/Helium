cmake_minimum_required(VERSION 3.14)

project(Helium)

#Set C++ standard to 17 or higher
set(CMAKE_CXX_STANDARD 17)

#Export compilation database in JSON format
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

include_directories(include)

#All the source files
set(SOURCES sources/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})