#include "lexer.hpp"

auto initialize_lexer(std::string source) -> std::shared_ptr<Lexer> {
    std::shared_ptr<Lexer> lex = std::make_shared<Lexer>();
    lex->_source = source;
    lex->_size = source.size();
    lex->_index = 0;
    lex->_c = source[lex->_index];

    return lex;
}