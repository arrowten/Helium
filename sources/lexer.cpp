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

auto lexer_parse_identifier(std::shared_ptr<Lexer> lex) -> std::shared_ptr<Syntax_Token> {
    std::string identifier;

    while(std::isalpha(lex->_c)) {
        identifier.push_back(lex->_c);
        lexer_advance(lex);
    }

    return initialize_token(identifier, Token_Type::identifier_token);
}

auto lexer_parse_number(std::shared_ptr<Lexer> lex) -> std::shared_ptr<Syntax_Token> {
    std::string number;

    while(std::isdigit(lex->_c)) {
        number.push_back(lex->_c);
        lexer_advance(lex);
    }

    return initialize_token(number, Token_Type::number_token);
}