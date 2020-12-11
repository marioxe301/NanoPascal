#include <iostream>
#include "ast_inter.h"
#include "test_defines.h"

int main(){
    ExprPtr expr = NUMBER(10);
    Interpreter interpreter;

    std::cout<< interpreter.execute(expr.get()) << std::endl;
    return EXIT_SUCCESS;
}