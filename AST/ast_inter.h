#ifndef __INTERPRETER__
#define __INTERPRETER__ 

#include "ast.h"
#include<unordered_map>

class Interpreter{
public:
    Interpreter() = default;
    int execute(const ASTNode *root);
private:
    int visit(const NumberExpr * expr);
    int visit(const VariableExpr * expr);

    int visit(const AddExpr * expr);
    int visit(const SubExpr * expr);
    int visit(const MultExpr * expr);
    int visit(const DivExpr * expr);
    int visit(const AndExpr * expr);
    int visit(const OrExpr * expr);
    int visit(const XorExpr * expr);
    int visit(const NotExpr * expr);
    int visit(const ModExpr * expr);
    int visit(const ShlExpr * expr);
    int visit(const ShrExpr * expr);
    int visit(const LessThanExpr * expr);
    int visit(const LessThanEqExpr * expr);
    int visit(const GreaterThanExpr * expr);
    int visit(const GreaterThanEqExpr * expr);
    int visit(const EqualExpr * expr);
    int visit(const DiffExpr * expr);

private:
    std::unordered_map<std::string,int>global_vars;
    std::unordered_map<std::string,int>local_vars;
};

#endif