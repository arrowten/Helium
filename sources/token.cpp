#include "token.hpp"

auto init_token(std::string value, Token_Type type) -> std::shared_ptr<Syntax_Token> {
    std::shared_ptr<Syntax_Token> token = std::make_shared<Syntax_Token>();
    token->_type = type;
    token->_value = value;

    return token;
}