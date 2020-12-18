#ifndef __LEXER_H__
#define __LEXER_H__

#include "tokens.h"
#include <iostream>
#include <string>
#include <istream>
#include <algorithm>

class Lexer{
public:
    Lexer(std::istream &input): input(input){
        line = 1;
    }
    
    std::string getText(){ return text; }
    int getNextChar(){ return input.get();}
    void ungetChar(int ch){ input.unget();}
    void reportError(int ch){
        throw std::string("Error inesperado");
    }

    Token getNextToken();
    Token findOperator(std::string &str);
    Token findKeyWord(std::string &str);
    Token findStringConst(std::string &str);
    static const char *tokenToString(Token tk);
    void setLineNumber(char t);
    std::string getLineNumber();
    
private:
    std::string text;
    std::istream &input;
    int line;
};


#endif