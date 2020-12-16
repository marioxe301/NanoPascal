#ifndef __PARSER__
#define __PARSER__

#include "ast.h"
#include "test_defines.h"
#include "lexer.h"

class Parser{
public:
    Parser(const Lexer&lexer)
    :lexer(lexer)
    {}
    void setCurrentToken(){
        currentTokenType = lexer.getNextToken();
        currentToken = lexer.getText();
    }

    ASTNode * parse();
private:

    Lexer lexer;
    Token currentTokenType;
    std::string currentToken;

private:

};

#endif