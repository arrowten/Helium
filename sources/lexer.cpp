#include "lexer.hpp"

auto initialize_lexer(std::string source) -> std::shared_ptr<Lexer> {
    std::shared_ptr<Lexer> lex = std::make_shared<Lexer>();
    lex->_source = source;
    lex->_size = source.size();
    lex->_index = 0;
    lex->_c = source[lex->_index];

    return lex;
}

void lexer_advance(std::shared_ptr<Lexer> lex) {
    lex->_index++;
    lex->_c = (lex->_index < lex->_size) ? lex->_source[lex->_index]: '\0';
}

void lexer_skip_whitespaces(std::shared_ptr<Lexer> lex) {
    while (lex->_c == '\r' || lex->_c == '\n' || lex->_c == '\t' || lex->_c == ' ') {
        lexer_advance(lex);
    }
}