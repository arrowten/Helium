#pragma once

#ifndef LEXER_HPP
#define LEXER_HPP

#include "token.hpp"

struct Lexer {
    std::string _source;    //Source string
    unsigned int _size;     //Size of source string
    char _c;                //Single character of the source string
    unsigned int _index;    //Index for the character of the source string
};

//Function to initialize the lexer
auto initialize_lexer(std::string source) -> std::shared_ptr<Lexer>;

#endif