#ifndef __INTERPRETER__
#define __INTERPRETER__ 

#include "ast.h"
#include<unordered_map>

class Interpreter{
public:
    Interpreter() = default;
    int execute(const ASTNode *root);
private:
    std::unordered_map<std::string,int>vars;
};

#endif