#include "lexer.hpp"
#include "macros.hpp"

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

auto lexer_return_first_token(std::shared_ptr<Lexer> lex, std::shared_ptr<Syntax_Token> token) -> std::shared_ptr<Syntax_Token> {
    lexer_advance(lex);

    return token;
}

auto lexer_advance_current_token(std::shared_ptr<Lexer> lex, Token_Type type) -> std::shared_ptr<Syntax_Token> {
    std::string value;
    value += lex->_c;
    std::shared_ptr<Syntax_Token> token = initialize_token(value, type);
    lexer_advance(lex);

    return token;
}

auto lexer_peek(std::shared_ptr<Lexer> lex, int offset) -> char {
    return lex->_source[MIN(lex->_index + offset, lex->_size)];
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

auto lexer_next_token(std::shared_ptr<Lexer> lex) -> std::shared_ptr<Syntax_Token> {
    while(lex->_c != '\0') {
        //Whitespaces
        if(lex->_c == '\r' || lex->_c == '\n' || lex->_c == '\t' || lex->_c == ' ') {
            lexer_skip_whitespaces(lex);
        }
        //Alphabets
        if(std::isalpha(lex->_c)) {
            return lexer_parse_identifier(lex);
        }
        //Numbers
        if(std::isdigit(lex->_c)) {
            return lexer_parse_number(lex);
        }

        switch(lex->_c) {
            case '=': {
                //Arrow right return type
                if(lexer_peek(lex, 1) == '>') {
                    lexer_advance(lex);

                    return lexer_return_first_token(lex, initialize_token("=>", Token_Type::arrow_right_return_type_token));
                }
                //Equal equal to
                else if(lexer_peek(lex, 1) == '=') {
                    lexer_advance(lex);

                    return lexer_return_first_token(lex, initialize_token("==", Token_Type::equal_equal_to_token));
                }           
                //Equal to
                return lexer_advance_current_token(lex, Token_Type::equal_to_token);
            }
            //Colons and comma
            case ':': {
                return lexer_advance_current_token(lex, Token_Type::colon_token);
            }
            case ';': {
                return lexer_advance_current_token(lex, Token_Type::semi_colon_token);
            }
            case ',': {
                return lexer_advance_current_token(lex, Token_Type::comma_token);
            }
            //Curly brackets
            case '{': {
                return lexer_advance_current_token(lex, Token_Type::left_curly_bracket_token);
            }
            case '}': {
                return lexer_advance_current_token(lex, Token_Type::right_curly_bracket_token);
            }
            //Parenthesis
            case '(': {
                return lexer_advance_current_token(lex, Token_Type::left_parenthesis_token);
            }
            case ')': {
                return lexer_advance_current_token(lex, Token_Type::right_parenthesis_token);
            }
            //Square brackets
            case '[': {
                return lexer_advance_current_token(lex, Token_Type::left_square_bracket_token);
            }
            case ']': {
                return lexer_advance_current_token(lex, Token_Type::right_square_bracket_token);
            }
            case '<': {
                //Lesser than or equal
                if(lexer_peek(lex, 1) == '=') {
                    lexer_advance(lex);

                    return lexer_return_first_token(lex, initialize_token("<=", Token_Type::lesser_than_or_equal_to_token));
                }
                //Lesser than
                return lexer_advance_current_token(lex, Token_Type::lesser_than_token);
            }
            case '>': {
                //Greater than or equal
                if(lexer_peek(lex, 1) == '=') {
                    lexer_advance(lex);

                    return lexer_return_first_token(lex, initialize_token(">=", Token_Type::greater_than_or_equal_to_token));
                }
                //Greater than
                return lexer_advance_current_token(lex, Token_Type::greater_than_token);
            }
            //Arithmetic
            case '+': {
                return lexer_advance_current_token(lex, Token_Type::plus_token);
            }
            case '-': {
                return lexer_advance_current_token(lex, Token_Type::minus_token);
            }
            case '*': {
                return lexer_advance_current_token(lex, Token_Type::star_token);
            }
            case '/': {
                return lexer_advance_current_token(lex, Token_Type::slash_token);
            }
            case '%': {
                return lexer_advance_current_token(lex, Token_Type::percent_token);
            }
            case '\0': {
                return lexer_advance_current_token(lex, Token_Type::eof_token);
            }
            default: {
                std::cout << "[Lexer]: Unexpected character: " << lex->_c;
                lexer_advance(lex);
                //Bad token
                return initialize_token("", Token_Type::bad_token);
            }
        }
    }
    //End of file
    return initialize_token("\0", Token_Type::eof_token);
}