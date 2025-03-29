#include "helium.hpp"
#include "lexer.hpp"

void helium_compile(std::string& source) {
    std::shared_ptr<Lexer> lex = initialize_lexer(source);
    std::shared_ptr<Syntax_Token> token = lexer_next_token(lex);

    while(token->_type != Token_Type::eof_token) {
        std::cout << token->_value << "\t\t:" << token_type_to_string(token->_type) << '\n';
        token = lexer_next_token(lex);
    }
}