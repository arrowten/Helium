#include "token.hpp"

auto initialize_token(std::string value, Token_Type type) -> std::shared_ptr<Syntax_Token> {
    std::shared_ptr<Syntax_Token> token = std::make_shared<Syntax_Token>();
    token->_type = type;
    token->_value = value;

    return token;
}

auto token_type_to_string(Token_Type type) -> std::string {
    switch (type) {
        case Token_Type::identifier_token: {
            return "identifier_token";
        }
        case Token_Type::number_token: {
            return "number_token";
        }
        case Token_Type::comma_token: {
            return "comma_token";
        }
        case Token_Type::colon_token: {
            return "colon_token";
        }
        case Token_Type::semi_colon_token: {
            return "semi_colon_token";
        }
        case Token_Type::plus_token: {
            return "plus_token";
        }
        case Token_Type::minus_token: {
            return "minus_token";
        }
        case Token_Type::star_token: {
            return "star_token";
        }
        case Token_Type::slash_token: {
            return "slash_token";
        }
        case Token_Type::percent_token: {
            return "percent_token";
        }
        case Token_Type::equal_to_token: {
            return "equal_to_token";
        }
        case Token_Type::lesser_than_token: {
            return "lesser_than_token";
        }
        case Token_Type::greater_than_token: {
            return "greater_than_token";
        }
        case Token_Type::lesser_than_or_equal_to_token: {
            return "lesser_than_or_equal_to_token";
        }
        case Token_Type::greater_than_or_equal_to_token: {
            return "greater_than_or_equal_to_token";
        }
        case Token_Type::equal_equal_to_token: {
            return "equal_equal_to_token";
        }
        case Token_Type::left_curly_bracket_token: {
            return "left_curly_bracket_token";
        }
        case Token_Type::right_curly_bracket_token: {
            return "right_curly_bracket_token";
        }
        case Token_Type::left_parenthesis_token: {
            return "left_parenthesis_token";
        }
        case Token_Type::right_parenthesis_token: {
            return "right_parenthesis_token";
        }
        case Token_Type::left_square_bracket_token: {
            return "left_square_bracket_token";
        }
        case Token_Type::right_square_bracket_token: {
            return "right_square_bracket_token";
        }
        case Token_Type::arrow_right_return_type_token: {
            return "arrow_right_return_type_token";
        }
        case Token_Type::bad_token: {
            return "bad_token";
        }
        case Token_Type::eof_token: {
            return "eof_token";
        }
        default: {
            return "unknown_token";
        }
    }
}