#ifndef __LEXER_H__
#define __LEXER_H__

#include "tokens.h"
#include <iostream>
#include <string>
#include <istream>

class Lexer{
public:
    Lexer(std::istream &input): input(input){}

    std::string getText(){ return text; }
    int getNextChar(){ return input.get();}
    void ungetChar(){ input.unget();}
    void reportError(int ch){
        throw std::string("Error: Caracter Invalido: " + (char)ch);
    }

    Token getNextToken();
    Token findKeyWord(const std::string &str);
    static const char *tokenToString(Token tk);
private:
    std::string text;
    std::istream &input;
};


#endif