#include "ast_inter.h"

#define HANDLE_CASE(n) \
    case NodeKind::n : return visit(reinterpret_cast<const n*>(root))

int Interpreter::execute(const ASTNode * root){
    switch (root->getKind())
    {
        HANDLE_CASE(NumberExpr);
        HANDLE_CASE(VariableExpr);
        HANDLE_CASE(AddExpr);
        HANDLE_CASE(SubExpr);
        HANDLE_CASE(MultExpr);
        HANDLE_CASE(DivExpr);
        HANDLE_CASE(AndExpr);
        HANDLE_CASE(OrExpr);
        HANDLE_CASE(XorExpr);
        HANDLE_CASE(NotExpr);
        HANDLE_CASE(ModExpr);
        HANDLE_CASE(ShlExpr);
        HANDLE_CASE(ShrExpr);
        HANDLE_CASE(LessThanExpr);
        HANDLE_CASE(LessThanEqExpr);
        HANDLE_CASE(GreaterThanExpr);
        HANDLE_CASE(GreaterThanEqExpr);
        HANDLE_CASE(EqualExpr);
        HANDLE_CASE(DiffExpr);
    default:
        throw std::string("No kind Found");
    }
}

int Interpreter::visit(const NumberExpr * expr){
    return expr->value;
}
int Interpreter::visit(const VariableExpr * expr){
    return expr->isLocal ? local_vars[expr->ident] : global_vars[expr->ident];
}

int Interpreter::visit(const AddExpr * expr){
    int a = execute(expr->left.get());
    int b = execute(expr->right.get());

    return a + b;
}
int Interpreter::visit(const SubExpr * expr){
    int a = execute(expr->left.get());
    int b = execute(expr->right.get());

    return a - b;
}
int Interpreter::visit(const MultExpr * expr){
    int a = execute(expr->left.get());
    int b = execute(expr->right.get());

    return a * b;
}
int Interpreter::visit(const DivExpr * expr){
    int a = execute(expr->left.get());
    int b = execute(expr->right.get());

    return b == 0 ? throw std::string("Can not divided by 0"):  a / b;
}
int Interpreter::visit(const AndExpr * expr){
    int a = execute(expr->left.get());
    int b = execute(expr->right.get());

    return a & b;
}
int Interpreter::visit(const OrExpr * expr){
    int a = execute(expr->left.get());
    int b = execute(expr->right.get());

    return a | b;
}
int Interpreter::visit(const XorExpr * expr){
    int a = execute(expr->left.get());
    int b = execute(expr->right.get());

    return a ^ b;
}
int Interpreter::visit(const NotExpr * expr){
    int a = execute(expr->child.get());

    return ~a;
}
int Interpreter::visit(const ModExpr * expr){
    int a = execute(expr->left.get());
    int b = execute(expr->right.get());

    return a % b;
}
int Interpreter::visit(const ShlExpr * expr){
    int a = execute(expr->left.get());
    int b = execute(expr->right.get());

    return a << b;
}
int Interpreter::visit(const ShrExpr * expr){
    int a = execute(expr->left.get());
    int b = execute(expr->right.get());

    return a >> b;
}
int Interpreter::visit(const LessThanExpr * expr){
    int a = execute(expr->left.get());
    int b = execute(expr->right.get());

    return a < b;
}
int Interpreter::visit(const LessThanEqExpr * expr){
    int a = execute(expr->left.get());
    int b = execute(expr->right.get());

    return a <= b;
}
int Interpreter::visit(const GreaterThanExpr * expr){
    int a = execute(expr->left.get());
    int b = execute(expr->right.get());

    return a > b;
}
int Interpreter::visit(const GreaterThanEqExpr * expr){
    int a = execute(expr->left.get());
    int b = execute(expr->right.get());

    return a >= b;
}
int Interpreter::visit(const EqualExpr * expr){
    int a = execute(expr->left.get());
    int b = execute(expr->right.get());

    return a == b;
}
int Interpreter::visit(const DiffExpr * expr){
    int a = execute(expr->left.get());
    int b = execute(expr->right.get());

    return a != b;
}