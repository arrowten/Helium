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

//Function to increment by a character
void lexer_advance(std::shared_ptr<Lexer> lex);

//Function for skipping whitespaces
void lexer_skip_whitespaces(std::shared_ptr<Lexer> lex);

//Function to parse an identifier
auto lexer_parse_identifier(std::shared_ptr<Lexer> lex) -> std::shared_ptr<Syntax_Token>;

//Function to parse a number
auto lexer_parse_number(std::shared_ptr<Lexer> lex) -> std::shared_ptr<Syntax_Token>;

#endif