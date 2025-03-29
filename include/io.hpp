#pragma once

#ifndef IO_HPP
#define IO_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

//Reads the contents of the file and displays it
auto read_file(std::string& input_file) -> std::string;

#endif