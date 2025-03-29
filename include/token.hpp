#pragma once

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <memory>

enum class Token_Type {
    //Identifiers are variable names
    identifier_token,
    //Numbers are like 123, 7.9 etc.
    number_token,
    //Seperator tokens
    comma_token,
    colon_token, 
    semi_colon_token,
    //Arithmetic tokens
    plus_token,
    minus_token,
    star_token,
    slash_token,
    percent_token,
    equal_to_token,
    //Comparison token
    lesser_than_token,
    greater_than_token,
    lesser_than_or_equal_to_token,
    greater_than_or_equal_to_token,
    equal_equal_to_token,
    //Container tokens
    left_curly_bracket_token,
    right_curly_bracket_token,
    left_parenthesis_token,
    right_parenthesis_token,
    left_square_bracket_token,
    right_square_bracket_token,
    //Return type deducer token
    arrow_right_return_type_token,
    //Bad token
    bad_token,
    //End of file token
    eof_token
};

struct Syntax_Token {
    Token_Type _type;       //Type of token
    std::string _value;     //Value of token
};

//Function to initialise the token
auto initialize_token(std::string value, Token_Type type) -> std::shared_ptr<Syntax_Token>;

#endif