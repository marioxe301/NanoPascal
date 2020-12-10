#ifndef __AST__
#define __AST__

#include <memory>
#include <string>

enum class NodeKind{

};

class ASTNode{
public:
    virtual NodeKind getKind() const = 0;
    ~ASTNode(){}
protected:
    ASTNode() = default;
};

class Expr: public ASTNode{
public:
    Expr() = default;
};

class Stmt: public ASTNode{
public:
    Stmt() = default;
};

using ExprPtr = std::shared_ptr<Expr>;
using StmtPtr = std::shared_ptr<Stmt>;

class BinaryExpr: public Expr{
protected:
    BinaryExpr(const ExprPtr &expr_1,const ExprPtr &expr_2)
    : left(expr_1), right(expr_2)
    {}
public:
    ExprPtr left;
    ExprPtr right;
};



#endif