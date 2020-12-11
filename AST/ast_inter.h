#ifndef __INTERPRETER__
#define __INTERPRETER__ 

#include "ast.h"
#include<unordered_map>

typedef struct{
    std::string str;
    int value;
}return_type;

class Interpreter{
public:
    Interpreter() = default;
    return_type execute(const ASTNode *root);
private:
    return_type visit(const NumberExpr * expr);
    return_type visit(const VariableExpr * expr);

    return_type visit(const AddExpr * expr);
    return_type visit(const SubExpr * expr);
    return_type visit(const MultExpr * expr);
    return_type visit(const DivExpr * expr);
    return_type visit(const AndExpr * expr);
    return_type visit(const OrExpr * expr);
    return_type visit(const XorExpr * expr);
    return_type visit(const NotExpr * expr);
    return_type visit(const ModExpr * expr);
    return_type visit(const ShlExpr * expr);
    return_type visit(const ShrExpr * expr);
    return_type visit(const LessThanExpr * expr);
    return_type visit(const LessThanEqExpr * expr);
    return_type visit(const GreaterThanExpr * expr);
    return_type visit(const GreaterThanEqExpr * expr);
    return_type visit(const EqualExpr * expr);
    return_type visit(const DiffExpr * expr);

    return_type visit(const StringExpr * expr);
    return_type visit(const AssignStmt * expr);
    return_type visit(const PrintStmt * expr);

    return_type visit(const IfStmt * expr);
    return_type visit(const WhileStmt * expr);
    return_type visit(const SeqStmt * expr);


private:
    std::unordered_map<std::string,int>global_vars;
    std::unordered_map<std::string,int>local_vars;
};

#endif